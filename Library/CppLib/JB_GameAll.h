

#include "JB_Alloc.h" // OK? so... now we just merged the two code-bases...
// we were gonna do this anyhow... now seems a good a time as any... 

#ifndef __Game_CLASSES__
#define __Game_CLASSES__

// easier to import... cos no reliance on GLM

extern "C" {
struct GameWorld;
struct GameScreen;
struct GameShader;
struct GameDrawer;
struct GameUniform;
struct GameTexInfo;
struct GamePipeline;
struct GameDrawDest;
struct GameFeedback;
struct GameDrawInit;
struct GameVoxelItem;
struct GameVoxelChunk;
struct GameKeyData;
struct GameVertexLayout;
struct GameFlyingChunk;

struct SDL_Window;

struct JB_Object;
struct JB_String;
typedef int         (*GameKeyHandler)(int* FrameCount, int Key, int KeyState);
typedef int         (*GameCallBack)(int State);
typedef JB_String*  (*fpFileLoader)(GameShader* self, uint8* Name, int N);
typedef void        (*fpDropFile)(byte* Name);

#define GamePipelineImageCount 8
#define kGameProcessCB (0)
#define kGameDrawCB (1)
#define kGamePostEffectsDrawCB (3)

enum GLImageSize {
    MSAA = 6,
    DepthBufferMSAA = MSAA + 1,
    DepthBufferNormal = 5,
    DepthBufferReadable = 4,
    QuarterSize = 2,
    HalfSize = 1,
    NormalSize = 0,
    DoubleSize = -1,
};





struct GameGLType {
    static const unsigned char _byte    = 0 + 0  + 0  + 0;
    static const unsigned char _byte2   = 1 + 0  + 0  + 0;
    static const unsigned char _byte3   = 2 + 0  + 0  + 0;
    static const unsigned char _byte4   = 3 + 0  + 0  + 0;
    static const unsigned char _sbyte   = 0 + 0  + 64 + 0;
    static const unsigned char _sbyte2  = 1 + 0  + 64 + 0;
    static const unsigned char _sbyte3  = 2 + 0  + 64 + 0;
    static const unsigned char _sbyte4  = 3 + 0  + 64 + 0;
    static const unsigned char _u16     = 0 + 16 + 0  + 0;
    static const unsigned char _u16x2   = 1 + 16 + 0  + 0;
    static const unsigned char _u16x3   = 2 + 16 + 0  + 0;
    static const unsigned char _u16x4   = 3 + 16 + 0  + 0;
    static const unsigned char _s16     = 0 + 16 + 64 + 0;
    static const unsigned char _s16x2   = 1 + 16 + 64 + 0;
    static const unsigned char _s16x3   = 2 + 16 + 64 + 0;
    static const unsigned char _s16x4   = 3 + 16 + 64 + 0;
    static const unsigned char _hfloat  = 0 + 16 + 64 + 128;
    static const unsigned char _hfloat2 = 1 + 16 + 64 + 128;
    static const unsigned char _hfloat3 = 2 + 16 + 64 + 128;
    static const unsigned char _hfloat4 = 3 + 16 + 64 + 128;
    static const unsigned char _float   = 0 + 32 + 64 + 128;
    static const unsigned char _vec2    = 1 + 32 + 64 + 128;
    static const unsigned char _vec3    = 2 + 32 + 64 + 128;
    static const unsigned char _vec4    = 3 + 32 + 64 + 128;
    static const unsigned char _int     = 0 + 32 + 64 + 0;
    static const unsigned char _ivec2   = 1 + 32 + 64 + 0;
    static const unsigned char _ivec3   = 2 + 32 + 64 + 0;
    static const unsigned char _ivec4   = 3 + 32 + 64 + 0;
    static const unsigned char _uint    = 0 + 32 + 0  + 0;
    static const unsigned char _u32     = _uint;
    static const unsigned char _u8      = _byte;
    static const unsigned char _short   = _s16;

////////////////////////////////////////////////////////////////////////////////

    unsigned char Data;

////////////////////////////////////////////////////////////////////////////////

    GameGLType() {}
    GameGLType (unsigned char C) { Data = C; }

    bool IsFloat();    
    bool IsInt();    
    bool IsSigned();    
    int  BitCount();
    int  ByteSize();
    int  Count();
    int  GLColorFormat();
    int  GLType();
    
    operator bool() const {
        return Data;
    }
};



struct GameDrawer {
    u64             VAO    : 24;
    u64             VBO    : 24;
    u64             _Count : 16;
    GameDrawInit*   MyInit;
    
    void UseVAO();
    void UseVBO();
    void Use();
    
    void Draw(GameShader* Sh);
    int  Count();
    void CountSet(int N);
    int  UpToDate();
    void UpToDateSet(int N);
    void DrawFlying(int Count, void* DataStart, int Bytes);
    void FillData(void* DataStart, int ByteSize);
    
    void Clear(GameShader* Sh);
    void SuperDraw();
    void Init(GameDrawInit* Init);
    void Update2(void* Data, int N);
};



struct GameShader {
    void*        Wrapper;
    const char*  Vert;
    const char*  Frag;
    GameShader*  NextShader;
    u32          Program;
    u32          uniOldScreen;
    u32          uniGBuff;
    u32          uniScreenInfo;
    char         ImageSize;
    bool         IsPostProcess;
    bool         HasTransparency;
    bool         HasBeenTested;
    bool         UseDrawArraysInstanced;

    bool Inited(){return NextShader;}
    int  Attrib(const char* name);
    void Delete();
    void SafeUse();
    void Use();
    void Use2(u32 Curr, u32 Old);
    void SetTex(const char* Name, int Tex);
    void InitAsPostProcess(const char* FragName, const char* VertName = 0);
    void Create(const char* vert, const char* frag);
    void Create2(const char* a, const char* b);
    void CreateNamed(const char* Special, const char* Name);
    void UseDest(GameDrawDest& Dest);
    void TestTexturesOK();
    GameShader* UpdateAllTextures(u64 Modified);
    void UpdateOneTexture(int Tex);
    void LoadAllTextures();
    void Validate();
    int  Uniform(const char* Name);

         //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  

    void PostProcess(bool Last=false);
    void DrawBackground();
    void Process(GameTexInfo& Tex, GameTexInfo& OldTex);
};




struct GameUniform {
    u32             UBO;
    int             BufferSize;
    int             Bind;
    void*           Buffer;
      // NO CONSTRUCTOR?
        
    void Allocate(int Size, void* Place);
    void Update();
    void Link(GameShader& Sh, const char* Name);
};



struct GameFeedback {
    u32             TBO;
    u32             Query;
    const char**    Names;
    int             BufferSize;
    void*           Buffer;
    int             Count;
    
      // NO CONSTRUCTOR?
    void Allocate(int Size, void* Place, const char** NewNames);
    void Link(int Program);
    void Use(int Mode);
    int Finish();
};




struct GamePipeline {
    u32          FBOs[3]; // should be 6?
    u32          Images[GamePipelineImageCount];
    u32          CurrVAO;
    u32          CurrVBO;
    float        GLTimeElapsed;
    u32          GLSamplesPassed;
    u16          CurrProgram;
    u16          UsingOffScreenTex;
    bool         IsFirst;
    bool         AppIsBackground;
    bool         IsPaused;
    bool         FrameCap;
    bool         CantAllocateStartupBuffers;
    uint8        CurrState;
    char         UseMSAA;
    char         CurrFBO;

    static const int kDepthTest = 1;
    static const int kTransparent = 2;
    static const int kCull = 4;


      // NO CONSTRUCTOR?
    void UseVAO(u32 V);
    void UseVBO(u32 V);
    void UseDepth(uint8 b);
    void UseBlend(bool b);
    void SetState(int State);
    void UseFBO(int FBO);
    void FillImageSub(int N, int Size, const char* Name, u32 Format=0x881A);
    void FillImage(int N, const char* Name);
    int  FillTexSub(GameShader& E, int CurrSize, int PingPong);
    void Delete();
    void UseMainFBO();
    void SetupFBOs();
    void SetupQuad();
    void SetupDefaults();
    void StartSetup();
    void SetupMSAA();
    void NoPostProcess();
    void Finish();
    double Aspect();
    void ResolveMSAA();
    void CollectDepth();
    bool UseProgram(GameShader& Shader);
    void CreateDrawDest(GameDrawDest& Dest);
    void Start();
};




struct GameTexInfo {
    const char*   Name;
    u32           TexID;
    uint8*        Data;
    int           UserFlags;
    u16           Width;
    u16           Height;
    u16           GLFormat;
    u16           TexType;
    u16           TexNum;
    GameGLType    SrcType;
    GameGLType    DestType;
    bool          IsPicture;

        // NO CONSTRUCTOR?

    void UseForDrawing();
};


const int MaxTextures = 63;
struct GameTextureLoader {
    GameTexInfo     Textures[MaxTextures];
    int             Count;
    u64             ModifiedBits;
    u64             TexBits;
    
      // NO CONSTRUCTOR?

    bool Load(const char* path, const char* name);
    void Delete();
    void InitRnd();
    void AddTexture(GameTexInfo& T, int N = -1, int FrameBufferPoint=0);
    void AppendTexture(GameTexInfo& T);

//////// Private
    void AlterItem(GameTexInfo* Info, int Num);
    void UpdateShaders();
};



struct GameDrawInfo {
    double    Time;
    float     MouseXY[2];
    float     Aura[4];
    int       ShaderType;
    u32       FrameCount;
    u32       SimulationCount;
//    int       DitherInfo;
    int       MSAA;
    float     Breath;
    float     FrameTime;
    int       ViewType;
    u32       InputReadCount; // for "check alive" stuff...
};



struct GameScreen {
    SDL_Window*      Window;
    GameFeedback*    FeedBack;
    GameDrawInfo     Info;
    GameDrawer       Draw;
    int              OldScreen;
    int              CurrScreen;
    GameUniform      UBO;
    int              Width; // these two stay constant unless screen changes
    int              Height;
    short            PortW; // for half-sized blur effects, I think
    short            PortH;
    bool             FullScreen;
    GamePipeline     Pipeline;
    
    void GoFullScreen(bool b);
    void Swap();
    SDL_Window* Start(int W, int H, int MSAA, bool Report, const char* WindowName);
    void SetViewPort(int W, int H);
    void UpdateUniforms();
};


struct GameLightning {
    GameTexInfo Tex1;
    GameTexInfo Tex2;

    void Start();
};



#ifndef kGameStructMax
#define kGameStructMax 8
struct GameVertexLayout {
    const char*        Names[kGameStructMax];
    GameGLType         Types[kGameStructMax];
    const char*        Name;
    short              GLShape;
    short              Count;
    short              Size_;
    GameVertexLayout*  Header;
//    int       Locations_[kGameStructMax]; // can't use. specific per-program.
    
    int Size();
    int ChunkSize();
    void Use(GameVertexLayout* Header, int Program, bool HasInstance);
};
#endif // kGameStructMax



      ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///

struct GameDrawInit {
    GameDrawer*          Instance;
    GameShader*          Shader;
    GameVertexLayout*    Info;
    u16                  GLShape;
    u16                  InstanceCount;
};


// might as well stuff this all into one place if we are gonna be using it together like this...
struct GameFlyingMem {
// changing
    uint8*                 CurrItem;
    uint8*                 LastItem;
    GameFlyingChunk*    CurrBlock;
    GameFlyingChunk*    Spares;
    GameFlyingMem*      NextActive;
    uint8                  DebugInfo;
    uint8                  Shape;
    GameDrawInit        RemoveThisLater; // shader should know everything it needs...

/// unchanging
    uint8*                 InitData;
    int                 InitDataLength;
    u16                 ItemSize;
    u16                 SuggestedCount;
    GameShader*         Shader;
    GameVertexLayout*   InitLayout;      // also should be in the shader.
};

struct GameVoxelItem;
struct GameVoxelChunk {
    float             X; // make sure we have 16 bytes header... I suppose we can compress Count a bit
    float             Y; // but the rest do need to be ints.
    float             Z;
    int               Count;
    int               Items[2048];
};







struct GameText {
// Should know everything so that you can just set the text and have it draw!! :3
    GameDrawer M;
    short X;
    short Y;
    short Width;
    short Height;

    void Init();
    void Draw();
    void BuildVAO();
    void Constructor(int X, int Y, int W, int H);
    void CopyOneLetter(int C, unsigned char* Dest, int Mode);
    void Load(const char* S, int N);    
};


//////////////////
struct GameMiniKey {
    u16              FramesDelay;
    u16              ToRemove    : 1; // only needs 1 but whatever.
    u16              ScanCode    : 15;
    u32              FrameCount;
};


#define kMaxDownKeys 8
struct GameKeyManager {
    short              Count;
    GameMiniKey        DownKeys[kMaxDownKeys];

    int Find(u16 Scan);
    void Add( u16 H );
    void Remove( u16 H );
    void Cleanup();
    void Clear();
};
// * Can't immediately remove keys on keyup, as keyup can happen before a frame starts.



//////////////////

typedef u64* Cell;
struct GameCellData {
    u64 Material:          12;
    u64 Heat:              12;  // Magical heat or whatever...
    u64 IsSolid:            1;
    u64 IsActive:           1;
    u64 PaletteSwap:        6;  // 64 appearance variants. Useful for "painting".
    u64 SlopeData:         32;  // Can be used for energy instead.
};

struct GamePackedSlopeInfo {
    u32 X:               10;
    u32 Z:               10;
    u32 YSign:           1;
    u32 W:               8;    // Z is implicit
    u32 Size:            2;    // perhaps use some bits from heat instead... cos we need more sizes.
    u32 HasSlopeAtAll:   1;    // bottom
};

}


#endif



