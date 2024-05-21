#include "WinGraphicsKit.h"

namespace PG {
	WinGraphicsKit* WinGraphicsKit::s_instance = nullptr;

	WindowIMP* WinGraphicsKit::CreateWindowIMP() {
		return new Win32WindowIMP; 
	}

	WindowContextIMP* WinGraphicsKit::CreateWindowContextIMP() {
		// TODO: Choose Between OpenGL or DirectX
		return new OpenGLWindowsContext;
	}

	GraphicsKit* WinGraphicsKit::Instance() {
		return (WinGraphicsKit::s_instance != nullptr) ? WinGraphicsKit::s_instance : new WinGraphicsKit;
	}
}