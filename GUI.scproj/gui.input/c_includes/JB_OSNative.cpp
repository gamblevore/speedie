

//#include "JB_Umbrella.h"
#include <stdio.h>
#include "/usr/local/speedie/GUI.scproj/gui.input/c_includes/SDL.h"
#include "JB_BasicTypes.h"
// fix this path later... obviously we don't want a full-path here.


extern "C" {
#ifdef __linux__
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
	printf("Unimplemented request to show URL: %s\n", Path);
}

void JB_App__SetIcon(const char* Path) {
	printf("Unimplemented request to set Application Icon: %s\n", Path);
}

void JB_SDL_SetModified(void* w, bool b) {
	printf("Unimplemented request to set Window Modified State\n");
}

void JB_SDL_FullScreen (void* w, bool On) {
	uint state = On ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0;
	SDL_SetWindowFullscreen((SDL_Window*)w, state);
}

void JB_SDL_RemoveWindowBorder (void* w) {
	SDL_SetWindowBordered((SDL_Window*)w, false);
}
#else
	
	void JB_Stub_OSNative() {
		; // do nothing. avoid complaints about empty files.
	}
#endif

}

