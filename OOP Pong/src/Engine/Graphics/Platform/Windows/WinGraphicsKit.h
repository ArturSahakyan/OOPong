#ifndef WINGRAPHICSKIT_H
#define WINGRAPHICSKIT_H

#include "../../GraphicsKit.h"
#include "Win32WindowIMP.h"

#include <iostream>

namespace PG {
	class WinGraphicsKit : public GraphicsKit {
	private:
		static WinGraphicsKit* s_instance;

	public:
		WindowIMP* CreateWindowIMP() override;

		static GraphicsKit* Instance();
	};
}

#endif // WINGRAPHICSKIT_H