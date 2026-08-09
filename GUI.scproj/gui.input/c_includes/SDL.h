
typedef int SDL_Keycode;
typedef int SDL_Keymod;
typedef int SDL_Scancode;
#define __CC_ARM // fixes the SDL_bool thing
#define SDL_scancode_h_
#define SDL_keycode_h_
#include <SDL2/SDL.h>
#undef __CC_ARM

struct SDL_SysWMinfo;
extern "C" {
extern DECLSPEC SDL_bool SDLCALL SDL_GetWindowWMInfo(SDL_Window* window, SDL_SysWMinfo* info);

// enums suck so bad. they make everything uncompileable!
inline SDL_Cursor* JB_CreateSystemCursor (int ID) {
	return SDL_CreateSystemCursor((SDL_SystemCursor)ID);
}

}


