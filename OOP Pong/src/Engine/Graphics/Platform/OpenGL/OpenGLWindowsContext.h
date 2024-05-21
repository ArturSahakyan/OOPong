#ifndef OPENGLWINDOWSCONTEXT_H
#define OPENGLWINDOWSCONTEXT_H

#include "../WindowContextIMP.h"

#include <glad/glad.h>

#ifdef PG_PLATFORM_WINDOWS
#include <Windows.h>

namespace PG {

	class OpenGLWindowsContext : public WindowContextIMP {
	private:
		HWND* m_windowHandle;
		HGLRC m_context;

	public:
		void createContext(void* window_data) override;
		void deleteContext() override;

		void swapBuffers() override;
		void clearScreen() override;
	};
#else
	class OpenGLWindowsContext : public WindowContextIMP {

	public:
		void createContext(void* window_data) override;
		void deleteContext() override;

		void swapBuffers(void* window_data) override;
		void clearScreen() override;
	};
#endif

}


#endif // OPENGLWINDOWSCONTEXT_H