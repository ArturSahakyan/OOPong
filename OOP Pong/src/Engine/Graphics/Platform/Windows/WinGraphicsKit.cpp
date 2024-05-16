#include "WinGraphicsKit.h"

namespace PG {
	WindowIMP* WinGraphicsKit::CreateWindowIMP() { 
		printf("You're on a Windows Window!");
		return nullptr; 
	}

	GraphicsKit* WinGraphicsKit::CreateInstance() {
		return nullptr;
	}
}