#ifndef WINDOW_H
#define WINDOW_H

#include "../Platform/WindowIMP.h"
#include "../WindowContext/WindowContext.h"

namespace PG {

	class Window {
	protected:
		WindowIMP* m_window;
		WindowContext m_context;

	protected:
		void handleEvents();

	public:
		Window();
		virtual ~Window();

		virtual void open(const WindowProps&);
		virtual void close();

		void clear();
		virtual void update();
	};

}
#endif // WINDOW_H