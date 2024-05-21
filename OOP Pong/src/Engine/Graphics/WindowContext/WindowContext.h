#ifndef WINDOWCONTEXT_H
#define WINDOWCONTEXT_H

#include "../Platform/WindowContextIMP.h"

namespace PG {

	class WindowContext {
	protected:
		WindowContextIMP* m_context;

	public:
		WindowContext();
		~WindowContext();

		void createContext(void* window_data);
		void deleteContext();

		void swapBuffers();
		void clearScreen();
	};

}

#endif // WINDOWCONTEXT_H