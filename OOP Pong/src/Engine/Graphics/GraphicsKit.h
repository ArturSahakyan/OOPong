#ifndef GRAPHICSKIT_H
#define GRAPHICSKIT_H

#include "./Platform/WindowIMP.h"
#include "./Platform/WindowContextIMP.h"

namespace PG {

	class GraphicsKit {
	private:
		static GraphicsKit* s_instance;

	public:
		virtual WindowIMP* CreateWindowIMP() = 0;
		virtual WindowContextIMP* CreateWindowContextIMP() = 0;

		static GraphicsKit* Instance();
	};

}


#endif // GRAPHICSKIT_H