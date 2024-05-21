#include "OpenGLWindowsContext.h"

namespace PG {
	
	// Gets ProcAddress for Window's OpenGL
	void* get_proc(const char* name) {
		void* p = (void*)wglGetProcAddress(name); // load newer functions via wglGetProcAddress
		if (p == 0 ||
			(p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) ||
			(p == (void*)-1)) // does it return NULL - i.e. is the function not found?
		{
			// could be an OpenGL 1.1 function
			HMODULE module = LoadLibraryA("opengl32.dll");
			p = (void*)GetProcAddress(module, name); // then import directly from GL lib
		}

		return p;
	}

	void OpenGLWindowsContext::createContext(void* window_data){ 
		m_windowHandle = static_cast<HWND*>(window_data);

		// Generate Descriptors
		HDC dc = GetDC(*m_windowHandle);

		PIXELFORMATDESCRIPTOR descriptor;

		ZeroMemory(&descriptor, sizeof(descriptor));

		descriptor.nSize = sizeof(descriptor);
		descriptor.nVersion = 1;
		descriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_DRAW_TO_BITMAP | PFD_SUPPORT_OPENGL | PFD_GENERIC_ACCELERATED | PFD_DOUBLEBUFFER | PFD_SWAP_LAYER_BUFFERS;
		descriptor.iPixelType = PFD_TYPE_RGBA;
		descriptor.cColorBits = 32;
		descriptor.cRedBits = 8;
		descriptor.cGreenBits = 8;
		descriptor.cBlueBits = 8;
		descriptor.cAlphaBits = 8;
		descriptor.cDepthBits = 32;
		descriptor.cStencilBits = 8;

		int pixel_format = ChoosePixelFormat(dc, &descriptor);
		SetPixelFormat(dc, pixel_format, &descriptor);

		// Create Context
		m_context = wglCreateContext(dc);
		wglMakeCurrent(dc, m_context);

		// Load OpenGL
		gladLoadGLLoader((GLADloadproc)get_proc);

		// TODO: Fix?
		glViewport(0, 0, 800, 600);
	}

	void OpenGLWindowsContext::deleteContext() {
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(m_context);
	}

	void OpenGLWindowsContext::swapBuffers() {
		SwapBuffers(GetDC(*m_windowHandle));
	}

	void OpenGLWindowsContext::clearScreen() {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

}