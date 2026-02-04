
#if __ALLOW_OSX_EXTENSIONS__
#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject <NSApplicationDelegate>
@end



void* JB_Str_CopyFromCString( const char* C );
void JB_FreeIfDead_(void* c);
static id							sigh;
static NSString*					FileOpened;


void* JB_App__DocumentOpened (bool Clear) {
	NSString* F = FileOpened;
	if (!F)
		return nil;
	if (Clear)
		FileOpened = nil;
	return JB_Str_CopyFromCString([F UTF8String]);
}

void JB_App__InitStuff (void) {
	if (!sigh) {
		sigh = [[AppDelegate alloc] init];
		NSApp.delegate = sigh;
	} 
}

void JB_App__Beep(void) {
	NSBeep();
}

void JB_App__ShowURL (const char* Path) {
	NSString* Where = [NSString stringWithUTF8String: Path];
	[[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:Where]];
}

@implementation AppDelegate
-(BOOL) application: (NSApplication*)sharedApplication openFile:(NSString*)fileName {
	FileOpened = fileName;
    return YES;
}
@end



void JB_App__SetIcon(const char* Path) {
	if (Path) {
		NSString* Where = [NSString stringWithUTF8String: Path];
		NSImage* IMG = [[NSImage alloc] initWithContentsOfFile:Where];
		[NSApp setApplicationIconImage: IMG];
	}
}

void JB_SDL_SetModified(void* w, bool b) {
	NSWindow* window = (__bridge NSWindow*)w;
	window.documentEdited = b;
}

void JB_SDL_FullScreenToggle (void* w) {
	NSWindow* window = (__bridge NSWindow*)w;
	[window toggleFullScreen:nil];
}

void JB_SDL_RemoveWindowBorder (void* w) {
	JB_App__InitStuff();
	NSWindow* window = (__bridge NSWindow*)w;
	window.titleVisibility = NSWindowTitleHidden;
	window.titlebarAppearsTransparent = YES;
	window.styleMask |= NSWindowStyleMaskFullSizeContentView;
}

//void JB_SDL_FullScreen (void* w, bool On) {
//}
#else
#define bool unsigned char
void* JB_App__DocumentOpened (bool Clear) {
	return 0;
}

void JB_App__InitStuff (void) {
}

void JB_App__Beep(void) {
}

void JB_App__ShowURL (const char* Path) {
}

void JB_App__SetIcon(const char* Path) {
}

void JB_SDL_SetModified(void* w, bool b) {
}

void JB_SDL_FullScreenToggle (void* w) {
}

void JB_SDL_RemoveWindowBorder (void* w) {
}


#endif
