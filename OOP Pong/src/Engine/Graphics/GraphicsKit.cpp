#include "GraphicsKit.h"

#include "./Platform/Windows/WinGraphicsKit.h"

namespace PG {
	GraphicsKit* GraphicsKit::CreateInstance() {
#ifdef PG_PLATFORM_WINDOWS
		return new WinGraphicsKit;
#else
		return;
#endif
	}
}