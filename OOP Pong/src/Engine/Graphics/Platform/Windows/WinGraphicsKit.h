#ifndef WINGRAPHICSKIT_H
#define WINGRAPHICSKIT_H

#include "../../GraphicsKit.h"
#include "Win32WindowIMP.h"

#include <iostream>

namespace PG {
	class WinGraphicsKit : public GraphicsKit {
	public:
		WindowIMP* CreateWindowIMP() override;

		static GraphicsKit* CreateInstance();
	};
}

#endif // WINGRAPHICSKIT_H