#ifndef GRAPHICSKIT_H
#define GRAPHICSKIT_H

#include "./Platform/WindowIMP.h"

namespace PG {

	class GraphicsKit {
	private:
		static GraphicsKit* s_instance;

	public:
		virtual WindowIMP* CreateWindowIMP() = 0;

		static GraphicsKit* Instance();
	};

}


#endif // GRAPHICSKIT_H