

#if DEBUG
int Count[32];
int TotalCount[32];
int GrandTotal;
int OutTotal;
int EscapeTotal;
int EscapeCount;
int EscapeFile;


float PC (int P) {
	return ((float)P/(float)GrandTotal) * 100.0f;
}


extern "C" void JB_ProbabilityDump (FastString* fs) {
	char Buffer[128];
	if (!Count[5]) {
		int n = snprintf(Buffer, 128, "\tGrandTotal %i\n", GrandTotal);
		JB_FS_AppendMem_(fs, (u8*)Buffer, n);
		
		int MegaTotal = 0;

		for (int i = 0; i < 32; i++) {
			if (int P = TotalCount[i]) {
				MegaTotal += P;
				int n = snprintf(Buffer, 128, "\tSlot %i = %i // (%.1f%%, %.1f%%)\n", 1<<i, P, PC(P), PC(MegaTotal) );
				JB_FS_AppendMem_(fs, (u8*)Buffer, n);
			}
		}
		
		n = snprintf(Buffer, 128, "\tFinal %i\n", OutTotal);
		JB_FS_AppendMem_(fs, (u8*)Buffer, n);
		
		n = snprintf(Buffer, 128, "\tEscape %i / %i\n", EscapeTotal, EscapeCount);
		JB_FS_AppendMem_(fs, (u8*)Buffer, n);
	} else {
		for (int i = 0; i < 32; i++) {
			if (int P = Count[i]) {
				TotalCount[i] += P;
				GrandTotal += P;
				int n = snprintf(Buffer, 128, "\tSlot %i = %i\n", 1<<i, P);
				JB_FS_AppendMem_(fs, (u8*)Buffer, n);
			}
			Count[i] = 0;
		}
	}
}


void probability_output (int x) {
	OutTotal += x;
}


#include <fcntl.h>
#include <unistd.h>
void probability_escape (u8* Read, int x) {
	if (EscapeFile == 0)
		EscapeFile = open("/tmp/spd_comp.esc", O_WRONLY|O_CREAT|O_TRUNC|0755);
	if (EscapeFile > 0)
		write(EscapeFile, Read, x);
	// save the data to a file...
	EscapeTotal += x;
	EscapeCount ++;
}

void probability_add (int Offset, int Min) {
	int log = std::max(JB_Int_Log2(Offset), Min);
	Count[log]++;
}

#else
	extern "C" void JB_ProbabilityDump (FastString* fs) {;}
	#define probability_output(a)
	#define probability_escape(a, b)
	#define probability_add(a, b)
#endif

