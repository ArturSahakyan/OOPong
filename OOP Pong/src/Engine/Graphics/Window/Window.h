#ifndef WINDOW_H
#define WINDOW_H

#include "../Platform/WindowIMP.h"

namespace PG {

	class Window {
	protected:
		WindowIMP* m_window;

	public:
		Window();
		virtual ~Window();

		void clear();
		void update();
	};

}
#endif // WINDOW_H