

#ifndef kGameStructMax
#define kGameStructMax 8

struct GameVertexLayout {
    const char*        Names[kGameStructMax];
    unsigned char      Types[kGameStructMax];
    short              GLShape;
    short              Count;
    short              Size_;
    GameVertexLayout*  Header;
};

////////////
#define GameAudioBuffer short* 
#define GAME_PAUSED 1
////////////
#define GL_POINTS                         0x0000
#define GL_LINES                          0x0001
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_STRIP                     0x0003
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006

struct GameType {
    static const unsigned char _byte    = 0 + 0  + 0  + 0;
    static const unsigned char _byte2   = 1 + 0  + 0  + 0;
    static const unsigned char _byte3   = 2 + 0  + 0  + 0;
    static const unsigned char _byte4   = 3 + 0  + 0  + 0;
    static const unsigned char _sbyte   = 0 + 0  + 64 + 0;
    static const unsigned char _sbyte2  = 1 + 0  + 64 + 0;
    static const unsigned char _sbyte3  = 2 + 0  + 64 + 0;
    static const unsigned char _sbyte4  = 3 + 0  + 64 + 0;
    static const unsigned char _u16     = 0 + 16 + 0  + 0;
    static const unsigned char _s16     = 0 + 16 + 64 + 0;
    static const unsigned char _s16x2   = 1 + 16 + 64 + 0;
    static const unsigned char _s16x3   = 2 + 16 + 64 + 0;
    static const unsigned char _s16x4   = 3 + 16 + 64 + 0;
    static const unsigned char _hfloat  = 0 + 16 + 64 + 128;
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
    static const unsigned char _u8     = _byte;
};

#endif // kGameStructMax

