

#include <stdio.h>
#include "SDL.h"


#ifdef __linux__
#include "JB_BasicTypes.h"
extern "C" {
void* JB_App__DocumentOpened (bool Clear) {
	return 0;
}

void JB_App__InitStuff (void) {
	return;
}

void JB_App__Beep(void) {
	putc('\a', stdout);
}

void JB_App__ShowURL (const char* Path) {
	SDL_OpenURL(Path);
}

void JB_App__SetIcon(const char* Path) {
	printf("Unimplemented request to set Application Icon: %s\n", Path);
}

void JB_SDL_SetModified(void* w, bool b) {
	printf("Unimplemented request to set Window Modified State\n");
}


void JB_SDL_RemoveWindowBorder (void* w) {
	SDL_SetWindowBordered((SDL_Window*)w, false);
}
}
#else

extern "C" void JB_SDL_FullScreen (void* w, bool On) {
	uint state = On ? 1 : 0; // fullscreen_desktop fails in WSL?
	SDL_SetWindowFullscreen((SDL_Window*)w, state);
}

#endif



