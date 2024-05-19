#include "GraphicsKit.h"

#include "./Platform/Windows/WinGraphicsKit.h"

namespace PG {
	GraphicsKit* GraphicsKit::s_instance = nullptr;

	GraphicsKit* GraphicsKit::Instance() {
		if (GraphicsKit::s_instance != 0)
			return GraphicsKit::s_instance;

#ifdef PG_PLATFORM_WINDOWS
		GraphicsKit::s_instance = WinGraphicsKit::Instance();
#else
		return nullptr;
#endif

		return GraphicsKit::s_instance;
	}
}