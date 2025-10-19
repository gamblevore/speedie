
/// picomsg
/// Licence: https://creativecommons.org/licenses/by/4.0/

/// Parent-child queue-based message-passing.
/// The API is simple. Hides the complexity of message-passing. 
/// Uses one (or more) worker threads, and is non-blocking.
/// 64 communicators max. 

/// Released 2024
/// Author: Theodore H. Smith, http://gamblevore.org



#ifndef __PICO_MSG__
#define __PICO_MSG__

#define PicoSilent				0
#define PicoNoiseDebugChild		1
#define PicoNoiseDebugParent	2
#define PicoNoiseDebug			3
#define PicoNoiseEventsChild	4
#define PicoNoiseEventsParent	8
#define PicoNoiseEvents			12
#define PicoNoiseAll			15
#define PicoSendGiveUp			0
#define PicoSendCanTimeOut		1
#define PicoMsgInfo				4
#ifndef PicoDefaultInitSize
	#define PicoDefaultInitSize (1024*1024)
#endif

#include <stdint.h> // for picodate

/// todo: Could remove some locks, for a pico hard-coded to one worker-thread

static float	PicoRemainDefault = 5.0;
typedef	int64_t	PicoDate;  // Resolution is 1s/64K, at ±445M years range.

struct			PicoComms;
struct			PicoGlobalConfig;

#pragma pack(push, 1)
struct			PicoMessage { char* Data; int Length;  operator bool () {return Data;}; };
#pragma pack(pop)

typedef void	(*PicoThreadFn)(PicoComms* M, unsigned int Mode, const char** Args);
typedef int		(*PicoObserverFn)(PicoDate CurrTime);  /// Receives the time via clock_gettime(CLOCK_REALTIME)
typedef char*   (*PicoAppenderFn)(void* Obj, int Length);



#ifdef PICO_IMPLEMENTATION

	#include <fcntl.h>
	#include <unistd.h>
	#include <pthread.h>
	#include <signal.h>
	#include <errno.h>
	#include <sys/socket.h>
	#include <algorithm>
	#include <atomic>

struct PicoBuff;
struct PicoTrousers { // only one person can wear them at a time.
	std::atomic_bool Value;
	PicoTrousers  () {Value = false;}
	bool enter () {
		bool Expected = false;
		return Value.compare_exchange_strong(Expected, true);
	}
	void leave () {
		Value = false;
	}
	void lock () {
		while (!enter()); // spin
	}
};
#endif


struct 			PicoConfig  {
	char 				Name[16];		/// Used for reporting events to stdout.
	PicoDate			LastRead;		/// The date of the last Read.
	PicoDate			LastSend;		/// The date of the last send.
	unsigned short		DeathCount;		/// How many times the subprocess died.
	unsigned short		SendFailCount;	/// How many times sending failed.
	unsigned short		ReadFailCount;	/// How many times reading failed.
	short				PIDStatus;		/// The exit-status of the sub-process (if any).
	unsigned char		Noise;			/// How much information PicoMsg prints. From `PicoSilent` to `PicoNoiseAll`
	unsigned char		SendTimeOut;	/// The number of seconds before a send will timeout (if the send is not instant)
	bool				LeaveOrphaned;	/// If this is true, the child-process will not be killed by `PicoKill()`
	unsigned char		Bits; 			/// The size we used to allocate stuff:  1 << Bits
	bool				IsParent;		/// Are we the parent.
#if defined(PICO_IMPLEMENTATION) || defined(PICO_SEE_INTERNALS) /// Don't alter the internals. 
	unsigned char		StateFlags;
	unsigned char		SocketStatus;
	unsigned char		PartClosed;
	PicoTrousers		SendLock;
	PicoTrousers		ReadLock;
	PicoTrousers		GrabLock;
	PicoTrousers		InUse;
	int					Socket;
	int					PID;
	PicoBuff*			Reading;
	PicoBuff*			Sending;
	PicoBuff*			StdErr;
	PicoBuff*			StdOut;
	std::atomic<char*>	PreData;
	int					PreLength;
	std::atomic_char	DestroyMe;  // these two must come last. It only memsets up to DestroyMe.
	unsigned char		ID;			// and we wnat to keep the ID!
#endif
};


struct			PicoProcStats {
	const char*		StatusName;
	int				PID;
	int				Status;
};


struct PicoGlobalConfig {
///
	PicoDate				LastActivity;
/// Useful data to check when the last activity was. Don't set this value yourself. Just read it.

///
	PicoObserverFn			Observer;
/// Allows your callback function to be called, repeatedly inbetween pico's own self-checks.
/// Return -1 to signify that you want to exit the program, and Pico will call exit() 

///
	PicoDate				TimeOut;
/// Defaults to zero. If this is zero, this does nothing.
/// Otherwise: Quits the app, if picomsg doesn't get any activity after `TimeOut` time. 

///
	int						ExitCode;
/// This is the exit code that will be used... if the we time out.
};


struct PicoGlobalStats {
	int			TimeOutCount;
	int         OpenSockets;
	int			OpenPicos;
};


#ifndef PICO_IMPLEMENTATION
	#define _pico_code_(x) ;
#else
	#define _pico_code_(x) {x}

#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
	#define htole(x) __builtin_bswap32(x)
	#define letoh(x) __builtin_bswap32(x)
#else
	#define htole(x) (x)
	#define letoh(x) (x)
#endif


extern "C" bool	PicoInit (int DesiredThreadCount);
static PicoTrousers PicoCommsLocker;


PicoDate pico_date_create ( uint64_t S, uint64_t NS ) {
	uint64_t NS2 = (NS * 9223372046ULL)>>47ULL; // avoid division :)
    return (S << 16) + NS2;
}

PicoDate PicoGetDate( ) {
	timespec ts; clock_gettime(CLOCK_REALTIME, &ts);
	return pico_date_create(ts.tv_sec, ts.tv_nsec);
}


void PicoSleep (float Wait) {
	if (Wait >= 0) {
		int Seconds = Wait;
		float F = Wait - floorf(Wait); 
		timespec ts = {Seconds, (int)(F*1000000000.0)};
		while ((nanosleep(&ts, &ts) == -1 and errno == EINTR)) {
			;
		}
    }
}


inline int pico_log2 (uint64_t X) {
	return 63-__builtin_clzll(X);
}


struct PicoCommList {
	std::atomic_uint64_t		Map;
	PicoTrousers				Lock;
	
	int Reserve () {
		int ID = 0;
		Lock.lock();
		uint64_t F0 = Map;
		if (F0+1) {
			auto F = ~F0;
			F &= -F;
			ID = pico_log2(F)+1;
			Map = F|F0;
		}
		Lock.leave();
		return ID;
	}           						 ;;;/*_*/;;;
	
	void Remove (int64_t M) {
		Lock.lock();
		uint64_t Old = Map;
		int64_t M2 = 1ULL << M;
		Map = Old & ~M2;
		Lock.leave();
	}
};



static	PicoCommList			pico_list;
static	std::atomic_int			pico_thread_count;
static	PicoTrousers			pico_inited;
static	int						pico_timeout_count;
static  std::atomic_int         pico_open_sockets;
static  PicoGlobalConfig		pico_global_conf;
static	PicoConfig				pico_all[64];


struct PicoLister {
	uint64_t SavedList;
	PicoLister () {SavedList = pico_list.Map;}
	
	PicoComms* NextComm () {
		auto L = SavedList;
		while (L) {
			auto Lowest = L & -L;
			L &= ~Lowest;
			SavedList = L;
			PicoComms* Found = (PicoComms*)&(pico_all[pico_log2(Lowest)]);
			if (Found)
				return Found;
		}
		return 0;
	}
};



//#ifdef PICO_DEBUG_LOG
//	#include <fcntl.h>
//	#include <sys/stat.h>
//	extern "C" PicoConfig* PicoCommsConf (PicoComms* M);
//#endif



struct PicoBuff {
	const char*			Name;
	std::atomic_uint	Tail;
	std::atomic_uint	Head;
	int					Size;
	int					Pipe;
//	#ifdef PICO_DEBUG_LOG
//	int					FDLog;
//	#endif
	void*				ThreadArgs;
	int					ThreadMode;
	std::atomic_short	RefCount;
	char				Data[0];             ;;;/*_*/;;;

	static PicoBuff* New (int bits, const char* name, PicoComms* O, int pipe) { // 🕷️vv🕷️
		PicoBuff* Rz = nullptr; 
		do {
			if ((Rz = (PicoBuff*)calloc((1<<bits)+sizeof(PicoBuff), 1))) break;
			if (bits < 9) return nullptr;
			bits--; 
		} while (true);
		Rz->Tail = 0; Rz->Head = 0; Rz->ThreadArgs = 0; Rz->ThreadMode = 0;
		Rz->RefCount = 1; Rz->Pipe = pipe;
		Rz->Size = 1<<bits; Rz->Name = name;
//	#ifdef PICO_DEBUG_LOG
//		char Path[128] = {};
//		snprintf(Path, sizeof(Path), "%s/%s/%s%s.txt", PICO_DEBUG_LOG, PicoCommsConf(O)->Name, PicoCommsConf(O)->Name, name);
//		int Sep = (int)(strlen(PICO_DEBUG_LOG) + 1 + strlen(PicoCommsConf(O)->Name));
//		Path[Sep] = 0;	
//		if (mkdir(Path, 0755) < 0 and errno!=EEXIST) {
//			printf("%s creating Path: %s\n", strerror(errno), Path);
//			exit(-1);
//		}
//			
//		Path[Sep] = '/';	
//		Rz->FDLog = open(Path, O_WRONLY|O_CREAT|O_TRUNC|0755);
//		if (Rz->FDLog == -1) {
//			printf("%s opening LOG: %s\n", strerror(errno), Path);
//			exit(-1);
//		}
//			
//	#endif
		return Rz;
	}

	void Log (const char* Src, int Length) {
//	#ifdef PICO_DEBUG_LOG
//		if (FDLog > 0) {
//			char Tmp[32*1024]; // increase this yourself if using PICO_DEBUG_LOG
//			int N = std::min(Length, (int)sizeof(Tmp)-1);
//			for (int i = 0; i < N; i++) {
//				int c = Src[i];
//				if (c < 32 or c >= 128)
//					c = '?';
//				Tmp[i] = c;
//			}
//			Tmp[N++] = '\n';
//
//			int x = 0;
//			while (x < N) {
//				int err = (int)write(FDLog, Tmp+x, N-x);
//				if (!err) break;
//				if (err < 0) {
//					err = errno;
//					if (err == EINTR or err == EAGAIN)
//						continue;
//					perror("Failed write: ");
//					exit(-1); // sigh
//				}
//				x+=N;
//			}
//		}
//	#endif
	}
	
	void lost (int N) {
		pico_global_conf.LastActivity = PicoGetDate();
		Tail += N;
	}

	void gained (int N) { 
		Head += N;
	} ;;;/*_*/;;;
	
	void send_sub (const char* Src, int Need) {
		while (auto Dest = AskUnused()) {
			int Avail = std::min(Need, Dest.Length);
			memcpy(Dest.Data, Src, Avail);
			gained(Avail + (-Avail&3));
			Need -= Avail;
			Src += Avail;
			if (Need <= 0) return;
		};
	}
	
	static void Decr (PicoBuff* self) {
//	#ifdef PICO_DEBUG_LOG
//		if (self->FDLog) {
//			fsync(self->FDLog);
//			close(self->FDLog);
//		}
//	#endif
		if (self and --(self->RefCount) == 0)
			free(self);
	}
		
	PicoMessage AskUsed () {
		int T = Tail; int H = Head; int S = Size; int B = S - 1;
		if (T >= H) return {};
		T &= B; H &= B; // 🕷️ _ 🕷️
		if (T >= H) // tail to head... or to size
			H = S;
		return {Data+T, H-T}; // 🕷️w🕷️
	}
	
	PicoMessage AskUnused () {
		int T = Tail; int H = Head; int S = Size; int B = S-1;
		int L = H - T;
		if (L >= S) return {};
		T &= B; H &= B;
		if (T > H) // head to size, or head to tail.
			S = T;
		return {Data+H, S-H};
	}

	int Length () {
		return Head - Tail;
	}  										;;;/*_*/;;;
	
	PicoDate SendOutput (const char* Src, int MsgLen) {
//		this->Log(Src, MsgLen); // So I can search -> Log and get all.
		int NetLen = letoh(MsgLen);
		if (Size - Length() >= MsgLen+PicoMsgInfo) {
			send_sub((char*)&NetLen, PicoMsgInfo);
			send_sub(Src, MsgLen);
			return pico_global_conf.LastActivity = PicoGetDate();
		}
		return 0;
	}
	
	/*	
		* Can save 8*64 bytes by merge all buffs into one. Still need 4 ints.
	*/

	int ReadLength () {
		int N = Length();
		if (N >= 4) {
			int T = Tail&(Size-1);
			int D = *((int*)(Data+T));
			lost(4);
			return D;
		}
		return 0;
	}

	void ReadInput4 (char* Dest, int N) {
		ReadInput(Dest, N);
		Tail += (-N&3);
	}
	
	void ReadInput (char* Dest, int N) {
		while (auto Msg = AskUsed()) {
			int B = std::min(Msg.Length, N); // 🕷️_🕷️
			memcpy(Dest, Msg.Data, B);
			Dest += B;
			N -= B; // 🕷️
			lost(B);
			if (N <= 0) break;
		}
	}
}; 



struct PicoComms : PicoConfig {
	static PicoComms* New (PicoComms* M, int noise, bool isparent, int size, const char* name, int ID) {
		M = (PicoComms*)&pico_all[ID-1];
		return M->Init(noise, isparent, size, name, ID-1);
	}
	
	PicoComms* Init (int noise, bool isparent, int size, const char* name, int iD) { // constructor
		DestroyMe = 0;
		ID = iD; IsParent = isparent; Socket = -1;
		PartClosed = 255;
		SocketStatus = 255;
		PIDStatus = -2;
		
		Noise = noise;
		SendTimeOut = 10.0f; // 🕷️_🕷️

		if (size <= 0)
			size = PicoDefaultInitSize;
		int B = std::clamp(pico_log2(size), 14, 30);		// 16KB mins, 1GB max

		B += ((1<<B) < size);
		Bits = B;
		
		if (!name) name = "";
		strncpy(Name, name, sizeof(Name)-1);
		return this;
	} ;;;/*_*/;;;
	
	void Destroy () {
		free(PreData);
		if (Socket > 0)
			msg_close_for_real(Socket);
		PicoBuff::Decr(Sending);
		PicoBuff::Decr(Reading);
		PicoBuff::Decr(StdErr );
		PicoBuff::Decr(StdOut );
		if (CanSayDebug()) Say("Deleted");
//		int x = --DebugCount;
//		printf("------- %i: %i\n", ID, x);
		int N = (intptr_t)&(((PicoComms*)0)->DestroyMe);
		memset(this, 0, N);
		pico_list.Remove(ID);
		DestroyMe = 2;
	}

	/// **Class Initialisation Helpers**
	bool MiniPipe (int Pipe[2], int Mode, int Std) {
		if (Mode >= 1)
			return true;

		if (pipe(Pipe))
			return failed();
		unblock(Pipe[0]);
		return true;
	}
	
	void* ChildClosePipes (int* Capture, int Std_FileNo) {
		int WR = Capture[1];
		if (WR >= 0) {
			while (dup2(WR, Std_FileNo) == -1) {
				int err = errno;
				if (err != EINTR and err != EBUSY)	
					return failed();
			}
			close(WR);
			close(Capture[0]);
		}
		return nullptr;
	}
	

	/// **Initialisation**
	int SimpleExec (const char* DebugName, bool NoMsgs, int NoStdOut, int NoStdErr, const char** argv) {
		int PID = StartExec(DebugName, NoMsgs, NoStdOut, NoStdErr);
		if (PID)
			return PID;
		// CHILD
		int p = getpid();
		setpgid(p, p);
		execvp(argv[0], (char* const*)argv);
		exit(errno); // execvp can fail!
	}
	
	int StartExec (const char* Name, bool NoMsgs, int NoStdOut, int NoStdErr) {
		int Out[2] = {-1, -1};  int Err[2] = {-1, -1};
		if ( (!MiniPipe(Out, NoStdOut, STDOUT_FILENO))
		  or (!MiniPipe(Err, NoStdErr, STDERR_FILENO)  and  GiveUp(Out) < 0))
			return -errno;

		PID = 0;
		PIDStatus = -2;
		int ChildID = NoMsgs?fork():StartFork(Name, true);
		if (ChildID < 0)
			return -errno;
		
		IsParent = ChildID;
		if (!IsParent) {
			StateFlags|=1; // a forked child
			if (NoStdOut == 1) 
				close(STDOUT_FILENO);
			if (NoStdErr == 1) 
				close(STDERR_FILENO);
			pico_thread_count = 0;
			ChildClosePipes(Out, STDOUT_FILENO);
			ChildClosePipes(Err, STDERR_FILENO);
			return 0;
		}
		
		PartClosed &= 15;
		PicoInit(0);
		
		if (!NoStdOut) {
			close(Out[1]);
			StdOut = PicoBuff::New(18, "StdOut", this, Out[0]);
			if (StdOut)
				PartClosed &=~ 4;
		}
		
		if (!NoStdErr) {
			close(Err[1]);
			StdErr = PicoBuff::New(16, "StdErr", this, Err[0]);
			if (StdErr)
				PartClosed &=~ 8;
		}
		
		PID = ChildID;
		mark_started();
		return PID;
	}

	bool StartThread (PicoThreadFn fn, uint Mode, const char** Args, int Noise) {
		if (!alloc_msg_buffs()) return false;

		int ChildID = pico_list.Reserve();
		if (!ChildID) return false;
		
		PicoComms* C = PicoComms::New(nullptr, Noise, false, 1<<Bits, "Thread", ChildID);
		Socket = -1;  C->Socket = -1;
		Sending->RefCount++;     Reading->RefCount++; 
		C->Sending = Reading; C->Reading = Sending;
		C->PartClosed = PartClosed;

		mark_started();
		C->mark_started();
		
		pthread_t T = 0;   						;;;/*_*/;;;   // creeping upwards!!
		C->Reading->ThreadArgs = Args;
		C->Reading->ThreadMode = Mode;
		C->Sending->ThreadArgs = (void*)fn;
		if (!pthread_create(&T, nullptr, pico_thread_root, C) and !pthread_detach(T))
			return true;
		
		C->AskDestroy("ThreadFailed");
		return false;
	}
	
	PicoComms* StartPair (int Noise) {
		int Socks[2] = {};
		if (!get_pair_of(Socks)) return nullptr;

		int PairID = pico_list.Reserve();
		if (!PairID) {GiveUp(Socks); return nullptr;}
		
		PicoComms* Rz = PicoComms::New(nullptr, Noise, false, 1<<Bits, "Pair", PairID);
		add_msg_buffs(Socks[0]);
		Rz->add_msg_buffs(Socks[1]);
		return Rz;
	}

	bool StartSocket (int Sock) {
		IsParent = false;
		return (Sock > 0 or failed(EBADF)) and add_msg_buffs(Sock);
	}

	bool RestoreExec () {
		return StartSocket(FindSock()); 
	}
	
	pid_t StartFork (const char* ChildName, bool SaveSocket) {
		int Socks[2] = {};
		if (!get_pair_of(Socks)) return -1;
		pid_t childid = fork();
		if (childid < 0) return GiveUp(Socks);

		IsParent = childid!=0; // 🕷️_🕷️
		close(Socks[!IsParent]);
		int S = Socks[IsParent];
		if (!IsParent) {
			StateFlags|=1; // a forked child
			if (ChildName)
				strncpy(Name, ChildName, sizeof(Name));
			pico_thread_count = 0; // Forked process don't keep threads.
			if (SaveSocket)
				return StoreSock(S);
		} 
		
		PID = childid;
		add_msg_buffs(S);
		return PID; 
	}
	/// **End of  Initialisation**
	
	
	int GiveUp (int* Socks) {
		close(Socks[0]);
		close(Socks[1]);
		return -1;
	}
	
	int FindSock () {
		const char* x = getenv("__PicoSock__");
		if (!x) return -1;
		unsetenv("__PicoSock__");
		return std::atoi(x);
	}
	
	int TextNumber (int N, char* S) {
		int C = N ? (int)log10( (double)N ) + 1 : 1;
		
		S += C;
		*S = 0;
		for (int i = 0; i < C; i++) {
			int P = N % 10;
			N = N / 10;
			*--S = ('0' + P);
		}
		return C;
	}
	
	pid_t StoreSock (int Succ) {
		char Data[8]; TextNumber(Succ, Data);
		setenv("__PicoSock__", Data, 1);
		return 0;
	}

	bool CanGet () {
		return !(PartClosed & 2) or PreData;
	}
	
	bool StillSending () {
		return !(PartClosed & 1) and Sending->Length() > 0;	
	}
	
	bool QueueSend (const char* msg, int n, int Policy) {
		if (!msg or n < 0 or PartClosed&1 or !Sending) return false; //
		if (queue_sub(msg, n)) return true;
		if (n+PicoMsgInfo > Sending->Size)
			return SayEvent("CantSend: Message too large!");
		if (Policy == PicoSendGiveUp)
			return (!SendFailCount++) and SayEvent("CantSend: BufferFull");
		
		PicoDate Final = PicoGetDate() + (PicoDate)(SendTimeOut*65536.0f);
		while (PicoGetDate() < Final) {
			if (PartClosed&1) return false; // closed!
			sched_yield();
			if (queue_sub(msg, n)) return true;
		}
		
		return (!SendFailCount++) and SayEvent("CantSend: TimedOut");
	}
	
	PicoMessage GetStd (PicoAppenderFn Fn, void* Obj, PicoBuff* B) {
		if (B) {
			int L = B->Length();
			if (L > 0) {
				char* Dest = Fn ? (Fn)(Obj, L) : phalloc(L);
				if (Dest) {
					B->ReadInput(Dest, L);
					return {Dest, L};
				}
				fail_alloc();
			}
		}
		return {};
	}
	
	PicoMessage ReadStdErr (PicoAppenderFn Fn, void* Obj) {
		return GetStd(Fn, Obj, StdErr);
	}
	
	PicoMessage ReadStdOut (PicoAppenderFn Fn, void* Obj) {
		return GetStd(Fn, Obj, StdOut);
	}
	
	PicoMessage Get (float T = 0.0) {
		if (!PreData and !pre_grab())
			if (!T or !delay_read(T))
				return {};
		
		PicoMessage M = {PreData, PreLength};
		PreLength = 0;	// could this have sync errors?
		PreData = 0;	// we are setting two values, and we have to assume things can get out of sync.
		return M;		// but will that cause a problem or not?
	}
	
	void* SayEvent (const char* A, const char* B="", int Iter=0) {
		if (Noise & (PicoNoiseEventsChild << IsParent))
			return Say(A, B, Iter);
		return nullptr;
	}

	inline bool CanSayDebug () {
		return Noise & (PicoNoiseDebugChild << IsParent);
	}
	
	void* Say (const char* A, const char* B="", int Iter=0) {
		const char* S = IsParent?"Parent":"Child";
		const char* P = Name;
		if (!B)
			B = "";
		if (!P or !strlen(P))
			P = IsParent ? "Parent" : "Child";
		if (Iter)
			printf("%s.%s: %s %s %i\n", S, P, A, B, Iter);
		  else // SPAB lol.
			printf("%s.%s: %s %s\n", S, P, A, B);
		
		return nullptr;
	}

	static const char* StatusName (int T) {
		if (T == 0)
			return "Successful: 0";
		if (T < 0)
			return "Running: -1";
		if (T & 128)
			return strsignal(T&~128);
		return strerror(T);
	}
	
	int Status (PicoProcStats* S) {
		int T = PIDStatus;
		if (S) {
			S->Status = T;
			S->PID = PID;
			S->StatusName = StatusName(T);
			if (StateFlags&1)
				S->PID = getppid();
		}
		return T;
	}
	
	void AskClose (const char* Why) {
		if ((PartClosed&15) == 15) return;
		PartClosed |= 15;
		if (!SocketStatus) SocketStatus = ENOTCONN;
		if (CanSayDebug()) Say("AskClose", Why);
	}
	
	void AskDestroy (const char* Why) {
		AskClose(Why);
		//if (!DestroyMe)
		DestroyMe = 1;
	}



/// ** INTERNALS **	
	static void* pico_thread_root (void* C_) {
		auto C = (PicoComms*)C_;
		auto S = C->Sending;
		auto R = C->Reading;
		auto fn = (PicoThreadFn)(S->ThreadArgs);
		auto Args = (const char**)R->ThreadArgs;
		auto Mode = R->ThreadMode;
		S->ThreadArgs = 0; R->ThreadArgs = 0;
		(fn)(C, Mode, Args);
		C->AskDestroy("ThreadCompleted");
		return 0;
	}
	
	bool queue_sub (const char* msg, int n) {
		if (!Sending) return false;
		auto D = Sending->SendOutput(msg, n);
		if (!D) return false;
		if (Socket < 0) LastSend = D; // threaded
		return true;
	}
	
	void read_part (PicoBuff* B, int S, int Part) {
		if (S >= 0) while ( auto Msg = B->AskUnused() ) {
			int Amount = 0;
			if (Part > 2)
				Amount = (int) read(S, Msg.Data, Msg.Length);
			  else // maybe nicer to avoid sockets and just use pipes. Simpler and more flexible.
			       // and can still use sockets.
				Amount = (int) recv(S, Msg.Data, Msg.Length, MSG_NOSIGNAL|MSG_DONTWAIT);
			if (Amount <= 0) {
				if (!io_pass(Amount, Part)) break;
				continue;
			}
//			B->Log(Msg.Data, Amount);
			pico_timeout_count = 0;			// reset
			B->gained(Amount);
			if (CanSayDebug()) Say("|recv|", "", Amount);
			pico_global_conf.LastActivity = PicoGetDate();
		}
	}
	
	inline void do_io() {
		if ((PartClosed&14) != 14 and ReadLock.enter())
			do_reading();
		if (can_send() and SendLock.enter())
			do_sending();
	}

	void do_reading () {
		if (!(PartClosed&2)) {
			if (Socket > 0)					// else, its memory-only IPC.
				read_part(Reading, Socket, 2);
			if (!PreData) pre_grab();
		}
		if (!(PartClosed&4))
			read_part(StdOut, StdOut->Pipe, 4);
		if (!(PartClosed&8))
			read_part(StdErr, StdErr->Pipe, 8);
		ReadLock.leave();
	}

	void do_sending () { 
		while ( auto Msg = Sending->AskUsed() ) {
		// send(MSG_DONTWAIT) does nothing on OSX sadly.
			int Amount = (int) send(Socket, Msg.Data, Msg.Length, MSG_NOSIGNAL|MSG_DONTWAIT);
  			if (Amount > 0) {
				Sending->lost(Amount);
				LastSend = PicoGetDate();
				if (CanSayDebug()) Say("|send|", "", Amount);
			} else if (!io_pass(Amount, 1))
				break;
		}
		SendLock.leave();
	}
	
	bool can_send () {
		return !(PartClosed&1)  and  (Socket > 0)  and  (Sending->Length());
	}

	bool delay_read (float T) {
		if (T < 0) T = SendTimeOut;
		T = std::min(T, 543210000.0f); // 17 years?
		PicoDate Final = PicoGetDate() + (PicoDate)(T*65536.0f);
		timespec ts = {0, 1000000}; int n = T*16000;
		for ( int i = 0;  i < n and !(PartClosed&2);   i++) {
			nanosleep(&ts, 0);
			if (PreData) return true; 
			if (PicoGetDate() > Final) return false;
		}
		return false;
	}
	
	static char* phalloc (int n) {
		char* Result = (char*)malloc(n+1);
		if (Result)
			Result[n] = 0;
		return Result;
	}
	
	bool pre_grab () {
		if (!GrabLock.enter())
			return false;
		bool Result = pre_grab_sub();
		GrabLock.leave();
		return Result;
	}
		
	bool pre_grab_sub () {
		int L = PreLength;
		if (!L) {
			PreLength = L = htole(Reading->ReadLength()); 
			if (L <= 0)
				return L < 0 and failed(EILSEQ);
			if (Reading->Size < L + PicoMsgInfo)			// msg bigger than our buffers
				return failed(EMSGSIZE);
		}
		
		if (Reading->Length() < L)
			return false;
		
		if (char* Data = phalloc(L+1); Data) {
			Reading->ReadInput4(Data, L);
			PreData = Data;
			LastRead = PicoGetDate();
			return true;
		}

		return fail_alloc();
	}
	
	bool get_pair_of (int* Socks) {
		if (pico_open_sockets > 96 or socketpair(PF_LOCAL, SOCK_STREAM, 0, Socks)) return failed();
		struct linger so_linger = {1, 5};
		for (int i = 0; i < 2; i++)
			setsockopt(Socks[i], SOL_SOCKET, SO_LINGER, &so_linger, sizeof so_linger);
		return true; 				;;;/*_*/;;;
	}
	
	bool alloc_msg_buffs () {
		if (!Sending and !(Sending = PicoBuff::New(Bits, "Send", this, -1)))
			return failed(ENOBUFS);
		if (!Reading and !(Reading = PicoBuff::New(Bits, "Read", this, -1)))
			return failed(ENOBUFS);
		PartClosed &= ~3; // Open up sending and reading. Say they are "not closed".
		PartClosed &= 15; // Make it not 255 anymore.
		return PicoInit(0);
	}

	void unblock (int Pipe) {
		int FL = fcntl(Pipe, F_GETFL, 0);
		if (FL >= 0)
			fcntl(Pipe, F_SETFL, FL | O_NONBLOCK);
		  else
			failed();
	}
	
	bool add_msg_buffs (int Sock) {
		if (int S = Socket; S > 0) { // currently open still.
			Socket = -1;
			close(S);
			pico_open_sockets--;
		}
		unblock(Sock);
		Socket = Sock;
		pico_open_sockets++;
		return alloc_msg_buffs() and mark_started();
	}

	bool mark_started () {
		SocketStatus = 0;
		PIDStatus = -1;
		if (CanSayDebug()) Say("Started");
		return true;
	}  ;;;/*_*/;;;   // creeping upwards!!


	bool fail_alloc () {
		perror("picomsg: ");
		return failed(ENOBUFS);
	}
	
	void* failed (int Err = errno, int P = 0) {
		int C = PartClosed;				
		if (C&P)					// already closed
			return nullptr;
		
		C |= P;
		PartClosed = C;
		if (C == 15)				// fully closed! perhaps the process died. Lets find out fast.
			check_exit_code();
		
		if (Err == EPIPE) {			// A normal close.
			if ( !(P & 3) or !((C&3)==3) )
				return nullptr;		// messages are still somewhat open.
			SocketStatus = EPIPE;	// messages are closed now.
			if (CanSayDebug())
				return Say("ClosedGracefully");
			return nullptr;
		}
		
		static const char* pico_fail_actions[4] = {"Sending", "Reading", "StdOut", "StdErr"};
		const char* Name = P ? pico_fail_actions[pico_log2(P)]: "Failed";
		SayEvent(Name, strerror(Err));
		if (Err == EBADF)
			SayEvent("Socket", "", Socket);
												;;;/*_*/;;;
		return nullptr;
	}
	
	bool io_pass (int Error, int Part) {
		if (!Error)
			return failed(EPIPE, Part);

		int e = errno;
						;;;/*_*/;;;
		if (e == EAGAIN) return false;
		if (e == EINTR)  return true;
		return failed(e, Part);
	}
	
	void io_buff_report(PicoBuff* B) {
		int SL = Sending->Length();
		if (SL) Say(B->Name, "Still Contains", SL);
		SL = Sending->Tail;
		if (SL)
			Say(B->Name, "", SL);
	}

	void msg_close_for_real (int S) {
		Socket = -1;
		if (S > 0) {
			pico_open_sockets--;
			close(S);
		}
		if (CanSayDebug()) {
			io_buff_report(Sending);
			io_buff_report(Reading);
			Say("Closing");
		}
	}
	
	bool all_closed() {
		int S = Socket; if (S < 0) return false;
		if (!ReadLock.enter()) return false;
		msg_close_for_real(S);
		ReadLock.leave();
		return true;
	}								;;;/*_*/;;;

	void check_exit_code () {
		if (PIDStatus >= 0)
			return;
		if (!PID)
			if (!(PartClosed == 15 and StateFlags&1))
				return;
		
		int ExitCode = 0;
		if (!PID) {
			if (getppid() <= 1)		// parent died.
				PIDStatus = 0;		// unknown why. So lets say it ended nicely.

		} else if (waitpid(PID, &ExitCode, WNOHANG) <= 0) {
			if (PartClosed!=15) return;
			errno = 0;
			if (kill(PID, 0)>=0) return;
			PIDStatus = errno;		// Process closed, but we missed it? was SIGCHLD ignored?
		} else if (WIFSIGNALED(ExitCode)) {
			PIDStatus = WTERMSIG(ExitCode)|128;
		} else if (WIFEXITED(ExitCode)) {
			PIDStatus = WEXITSTATUS(ExitCode);
		}
		if (CanSayDebug())
			Say("Process", StatusName(PIDStatus), -PID);
	}
	
	bool kill_me () {
		if (!PID or DestroyMe or LeaveOrphaned or (PIDStatus >= 0) or (StateFlags&1))
			return true;
		if (!InUse.enter())
			return false;
		
		// Don't update PIDStatus here. The kill might not go through! Or be caught and then die differently.
		kill(PID, SIGKILL);
		InUse.leave();
		return true;
	}
	
	void cleanup (PicoDate CheckPID) {
		if (!InUse.enter())
			return;
		
		if (CheckPID or (PartClosed&15)==15)
			check_exit_code();

		if (DestroyMe == 1) {
			if (CanSayDebug()) Say("Bye");
			check_exit_code(); // cleanup process PID list...
			Destroy();
		}
		InUse.leave();
	}
	
	;;;/*_*/;;;
	void io () {
		if (DestroyMe or !InUse.enter())
			return;
		// lock might be a little too aggressive.
		// it dissallows two threads to both read/write at the same time
		// but we still do want to block destruction/kill/waitpid
		int P = PartClosed;			
		if ((P&15) != 15)
			do_io();
		  else if (P != 255)
			all_closed();
		InUse.leave();
	}
};


static void pico_cleanup () {
	static PicoDate LastCheck = 0;
	PicoDate Now = PicoGetDate();
	if (abs(Now - LastCheck) > 64*1024*0.25) // 4x a second
		LastCheck = Now;
	  else
		Now = 0;
	
	PicoLister Items;
	while (auto M = Items.NextComm())
		M->cleanup(Now);
}


static bool pico_try_exit () {
	auto D = PicoGetDate();
	if (pico_global_conf.Observer and (pico_global_conf.Observer)(D) < 0)
		return true;

	if (pico_global_conf.TimeOut <= 0)
		return pico_timeout_count = 0;
	;;;/*_*/;;;

	PicoDate MaxTime = pico_global_conf.TimeOut + pico_global_conf.LastActivity;
	if (MaxTime >= D)
		return pico_timeout_count = 0;

	// Fail a few times, first. In case of computer-suspend.
	if (++pico_timeout_count > 12)
		return true; /// only happens if  `pico_global_conf.TimeOut > 0` 
	;;;/*_*/;;;
	
	pico_global_conf.LastActivity += 64*1024*2.5; // 2.5 seconds of grace. 
	return false;
}


static void pico_work_comms () {
	PicoLister Items;
	while (auto M = Items.NextComm())
		M->io();
	
	float S = (PicoGetDate() - pico_global_conf.LastActivity) * (0.000015258789f * 0.005f);

	S = std::clamp(S*S, 0.001f, 0.5f);
	timespec ts = {0, (int)(S*1000000000.0)};
	nanosleep(&ts, 0); // interuptible sleep	
}


static int pico_any_still_sending () {
	PicoLister L;
	int Count = 0;
	while (auto M = L.NextComm())
		Count += M->StillSending();
	return Count;
}


static void pico_keep_sending () {
	auto Remain = PicoRemainDefault;
	while (pico_any_still_sending() and Remain > 0) {
		PicoSleep(0.01);
		Remain -= 0.01;
	};
}


static void* pico_worker (void* Dummy) {
	char PicoName[] = {'P','i','c','o','W','o','r','k','e','r','0','0',0};
	int p = ++pico_thread_count;
	PicoName[10] += p / 10;
	PicoName[11] += p % 10;
#if __APPLE__
	pthread_setname_np(PicoName); // why?
#else
	pthread_setname_np(pthread_self(), PicoName);
#endif 

	if (p!=1) while (true)
		pico_work_comms();
	
	while (true) {
		pico_work_comms();
		pico_work_comms();
		pico_cleanup();
		pico_work_comms();
		if (pico_try_exit())
			exit(pico_global_conf.ExitCode);
	}
}


static bool pico_init (int D) {
	if (pico_thread_count)
		return true;
	
	if (!pico_inited.enter())
		return true;
	
	atexit(pico_keep_sending);

	D = std::clamp(D, 1, 6);
	pthread_t T = 0;   ;;;/*_*/;;;   // creeping downwards!!
	bool OK = false;
	for (int i = pico_thread_count; i < D; i++) {
		if (!(pthread_create(&T, nullptr, (void*(*)(void*))pico_worker, nullptr) or pthread_detach(T)))
			OK = true;
	}

	pico_global_conf.LastActivity = PicoGetDate();
	pico_inited.leave();
	return OK;
}


static void pico_kill_all () {
	PicoLister Items;
	while (auto M = Items.NextComm())
		while (!M->kill_me());
}


#endif



// ------------------------------------------------------------------------------------- //
/// C-API, Documentation and Headers
// ------------------------------------------------------------------------------------- //

///
/// **Initialisation / Destruction** ///
///

extern "C" PicoComms* PicoCreate (const char* Name, int BufferByteSize=0)  _pico_code_ (
/// Creates your message-passer.  Can return `null`, if 64 PicoComms already are in-use.
/// Can specify input buffer size. Passing `0` defaults to `PicoDefaultInitSize` (1MB, unless overridden).
	int ID = pico_list.Reserve();
	if (ID)
		return PicoComms::New(nullptr, PicoNoiseEvents, true, BufferByteSize, Name, ID);
	return nullptr;
)

extern "C" PicoComms* PicoDestroy (PicoComms* M, const char* Why=nullptr) _pico_code_ (
/// Destroys the PicoComms object, and reclaims memory. Also closes the other side.
/// Returns null always. The destruction will happen at a later (very short) time, in another thread.
	if (M) M->AskDestroy(Why);
	return nullptr;
)
	;// 🕷️_🕷️

extern "C" PicoComms* PicoStartChild (PicoComms* M) _pico_code_ (
/// Creates a new child comm and links them together, using sockets.
	return M->StartPair(PicoNoiseEvents);
)


extern "C" bool PicoStartThread (PicoComms* M, PicoThreadFn fn, uint Mode=0, const char** Args=nullptr) _pico_code_ (
/// Creates a new thread, using the function `fn`, and passes a newly created PicoComms object to your function! Also cleans up the newly created PicoComms when done. Returns `false` if any error occurred. Look at PicoTest.cpp for a good example. :) You can pass two user-defined parameters.
	return M->StartThread(fn, Mode, Args, PicoNoiseEvents);
)



///
/// **SubProcesses** ///
///
extern "C" int PicoStartFork (PicoComms* M, const char* Name=nullptr) _pico_code_ (
/// This will fork your app, and then connect the two apps with PicoMsg. Returns the result of `fork()`. So handle it just the same.
	return M->StartFork(Name, false);
)


extern "C" int PicoExec (PicoComms* M, const char* DebugName, const char** argv, bool NoMsgs=false, int NoStdOut=2, int NoStdErr=2) _pico_code_ (
/// Will `exec` a new subprocess. Returns a child PID on success, otherwise returns `-errno`.
/// The `PicoComms` passed can get `stderr`, `stdout` and `PicoMsg` connected.
/// Thats up to 3 pipes that *can* be made. Each can be disabled.
/// The values that `NoStdOut` / `NoStdErr` take are:
	/// 0) Captures piped data and saves it in our `PicoComms`.
	/// 1) Closes the pipe. We don't get it. No one gets it. It just disappears.
	/// 2) PassThru of piped data. If the child prints to `stdout`, it appears as our `stdout`. (Done via pipe setup. We don't touch the data.)
/// `NoMsgs` is similar, except that its either 1 or 0. Passthru is not available. 
	return M->SimpleExec(DebugName, NoMsgs, NoStdOut, NoStdErr, argv);
)


extern "C" int PicoShellExec (PicoComms* M, const char* DebugName, const char** argv) _pico_code_ (
/// Similar to `PicoExec()` except that is is configured to be useful for capturing all the output of a shell app.
/// So its just a helper function really. 
	return M->SimpleExec(DebugName, true, 0, 0, argv);
)


extern "C" int PicoPartialExec (PicoComms* M, const char* DebugName, bool NoMsgs=false, int NoStdOut=1, int NoStdErr=1) _pico_code_ (
/// Similar to `PicoSimpleExec()`, but doesn't call `exec()` after `fork()`. This allows your child process to do final setup before you call `exec()` yourself. 
	return M->StartExec(DebugName, NoMsgs, NoStdOut, NoStdErr);
) ;;;/*_*/;;; // 🕷️_🕷️	


extern "C" bool PicoRestoreExec (PicoComms* M) _pico_code_ (
	return M->RestoreExec();
)


extern "C" void PicoKill(PicoComms* M) _pico_code_ (
	if (M)
		while (!M->kill_me());
	  else
		pico_kill_all();
)


///
/// **Communications** ///
///

extern "C" bool PicoSend (PicoComms* M, const char* Msg, int Length, int Policy=PicoSendGiveUp) _pico_code_ (
/// Sends the message. The data is copied to internal buffers so you do not need to hold onto it after send. If Policy==`PicoSendGiveUp` and there is no buffer space, this function returns `false`. If Policy==`PicoSendCanTimeOut`, and there is no buffer space, PicoSend will block until the timeout is reached. See the ["configuration"](#Configuration) section about how to change the timeout. (You probably should design your programs to slurp up data so fast that blocking isn't necessary.)
	return M->QueueSend(Msg, Length, Policy);
)

extern "C" bool PicoSendStr (PicoComms* M, const char* Msg, bool Policy=PicoSendGiveUp) _pico_code_ (
/// Same as `PicoSend`, just a little simpler to use, if you have a c-string.
	return M->QueueSend(Msg, (int)strlen(Msg), Policy);
)

extern "C" void PicoGet (PicoComms* M, PicoMessage* Out, float Time=0) _pico_code_ (
/// Gets a message if any exist. You can either return immediately if none are queued up, or wait for one to arrive.
/// Once it returns a PicoMessage, you must `free()` it's `Data` property, after you are finished with it.
/// The string is zero-terminated, but the zero is not included in the reported length.
	;;;/*_*/;;;  // 🕷️_🕷️
	*Out = M->Get(Time);
)

extern "C" PicoMessage PicoGetCpp (PicoComms* M, float Time=0) _pico_code_ (
/// In case you want something a bit fancier than PicoGet. Returns a `PicoMessage` struct.
/// Same zero-term behaviour as `PicoGet()`
	return M->Get(Time);
);;;/*_*/;;;

extern "C" PicoMessage PicoStdOut (PicoComms* M, PicoAppenderFn Alloc=nullptr, void* Obj=nullptr) _pico_code_ (
/// Reads the captured output of `stdout` (if any). Assumes you created this `PicoComms` via `PicoStartExec()`.
/// The data is returned via `malloc()`, unless you pass a non-zero value to `Alloc`.
/// If you want to choose where the data is written to, then pass a function and object to the `Alloc` and `Obj` params.

/// if `PicoAppenderFn` is `null`, Pico will zero-terminate your data.
/// You are told the correct number of bytes, its just that one byte was secretly allocated for the last null-byte.

/// If you want the same behaviour with your own `PicoAppenderFn`, you have to do that in yourself.
	return M->ReadStdOut(Alloc, Obj);
)

extern "C" PicoMessage PicoStdErr (PicoComms* M, PicoAppenderFn Alloc=nullptr, void* Obj=nullptr) _pico_code_ (
/// Same as `PicoStdOut()`, except it reads from `stdout`.
	return M->ReadStdErr(Alloc, Obj);
)


///
/// **Utilities** ///
///

extern "C" void PicoClose (PicoComms* M, const char* Why=nullptr) _pico_code_ (
/// Closes the comms object. Does not destroy it. Useful if you have many places that might need to close the comms, but only one place that will destroy it. It is acceptable to close a comms twice!
	M->AskClose(Why);
)

extern "C" void* PicoSay (PicoComms* M, const char* A, const char* B="", int Iter=0) _pico_code_ (
/// Prints a string to `stdout`. This can be used to debug or report things. This helpfully mentions if we are the parent or not, and also mentions our Comm's name. (`Name` is settable via `PicoConfig`).
	return M->Say(A, B, Iter);
)

extern "C" bool PicoStillSending (PicoComms* M) _pico_code_ (
///  Returns if the comms object is still in the business of sending. This is to let you keep your app open while busy sending. Pass nil to see if any are sending.
	return M?M->StillSending():pico_any_still_sending();
)

extern "C" void PicoSleepForSend (float During, float After) _pico_code_ (
///  Sleeps while sends occur. Useful to call last in your app.
	PicoRemainDefault = During;
	pico_keep_sending();
	PicoSleep(After);
)

extern "C" int PicoPartsOpen (PicoComms* M) _pico_code_ (
/// Flags for open parts of the PicoComms.
/// 1 = SendMessages, 2 = ReadMessages, 4 = ReadStdOut, 8 = ReadStdErr 
	if (!M) return 0;
	return (~(M->PartClosed)) & 15;
)

extern "C" bool PicoCanGet (PicoComms* M) _pico_code_ (
/// Returns if we either HAVE unread messages, or MIGHT get them in the future (That is, it is not closed)
	return M?M->CanGet():false;
)

extern "C" bool PicoIsParent (PicoComms* M) _pico_code_ (
/// Returns if we are the parent, or child end of the comms.
	return M->IsParent;
)

extern "C" bool PicoHasParentSocket () _pico_code_ (
/// Returns if our app, created via `PicoStartFork(M, true)` (with the true param). This is in case your app could be launched in multiple ways. Like my compiler speedie can be run normally from the terminal, or run as a sub-process by the IDE, and then speedie will want to know if it was run as a sub-process via the IDE! This function informs speedie of that fact.
	return getenv("__PicoSock__");
)

extern "C" bool PicoInit (int DesiredThreadCount) _pico_code_ (
/// Starts the PicoMsg worker threads.
	return pico_init(DesiredThreadCount);
)    ;;;/*_*/;;;  ;;;/*_*/;;;     ;;;/*_*/;;;   // the final spiders



///
/// **Configuration / Statistics / Info ** ///
///

extern "C" int PicoStatus (PicoComms* M, PicoProcStats* S=nullptr) _pico_code_ (
	/// Pico has a unified system for status codes.
	/// EG: After `PicoShellExec(M)`, then call `PicoInfo(M)` to find `M`'s status.
	/// Result codes:
	//  Positive:  A crash, or exited normally but with an error.
	//  Negative:  The program is still running.
	//  Zero	:  The program exited successfully.
	
	/// Positive numbers are either from errno, or signal numbers.
	/// A number of 128 or more, is a signal.
	/// You can check if the process is finished with:  `(PicoInfo(M, nullptr) >= 0)`
	/// Get extra info by passing a `PicoProcStats` struct. Contains error names, and the PID. 
	
	/// Don't `free()` the `StatusName` field in `PicoProcStats`! Just let it be.
	return M->Status(S);
)

extern "C" int PicoError (PicoComms* M) _pico_code_ (
/// Returns an error that forced comms to close. If the comms is still open, the error is 0.
	return M->SocketStatus;
)


extern "C" PicoGlobalConfig* PicoGlobalConf() _pico_code_ (
// Returns the global conf struct, which allows you to set important values.
	return &pico_global_conf;
)

extern "C" void PicoGlobals (PicoGlobalStats* F) _pico_code_ (
	F->TimeOutCount = pico_timeout_count;
	F->OpenSockets  = pico_open_sockets;
	F->OpenPicos    = __builtin_popcountll(pico_list.Map); 
);;;/*_*/;;;  //reeeeeeee

#endif

