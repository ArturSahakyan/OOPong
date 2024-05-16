#ifndef GRAPHICSKIT_H
#define GRAPHICSKIT_H

#include "./Platform/WindowIMP.h"

namespace PG {

	class GraphicsKit {

	public:
		virtual WindowIMP* CreateWindowIMP() = 0;

		static GraphicsKit* CreateInstance();
	};

}


#endif // GRAPHICSKIT_H