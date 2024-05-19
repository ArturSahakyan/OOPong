#include "Win32WindowIMP.h"

#ifdef PG_PLATFORM_WINDOWS

namespace PG {

	// Grabs OpenGL Func Addresses for Windows Machines
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


	// TODO: Create Event Handler
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		// TODO: Don't Hardcode This
		switch (uMsg) {
		case WM_CLOSE:
			DestroyWindow(hWnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		}

		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	Win32WindowIMP::Win32WindowIMP()
		: m_hInstance(GetModuleHandle(nullptr)), m_hWnd(HWND())
	{}

	Win32WindowIMP::~Win32WindowIMP() {
		this->close();
	}


	void Win32WindowIMP::open(const WindowProps& props) {
		const wchar_t* class_name = this->convertToWideChar(props.title); // Convert to Wide String

		WNDCLASS wc = {};
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = m_hInstance;
		wc.lpszClassName = class_name;
		wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		wc.hCursor = LoadCursorW(NULL, IDC_ARROW);

		RegisterClass(&wc);

		// TODO: Don't Hardcode This
		RECT rect;
		rect.left = 100;
		rect.top = 100;
		rect.right = rect.left + props.width;
		rect.bottom = rect.top + props.height;

		m_hWnd = CreateWindowEx(
			0,
			class_name,
			class_name,
			WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
			rect.left,
			rect.top,
			rect.right - rect.left,
			rect.bottom - rect.top,
			NULL,
			NULL,
			m_hInstance,
			NULL
		);

		ShowWindow(m_hWnd, SW_SHOW);

		// TODO: Clean This Up
		HDC dc = GetDC(m_hWnd);

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

		// TODO: Get Rid of OpenGL Code
		HGLRC rc = wglCreateContext(dc);
		wglMakeCurrent(dc, rc);
		gladLoadGLLoader((GLADloadproc)get_proc);
		glViewport(0, 0, 800, 600);
		m_props = props;
		delete class_name;
	}

	void Win32WindowIMP::close() {
		wchar_t* name = this->convertToWideChar(m_props.title);
		UnregisterClass(name, m_hInstance);
		delete name;
	}


	void Win32WindowIMP::clear() {
		// TODO: Don't Override This? & Get Rid of OpenGL code
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Win32WindowIMP::handleEvents() {
		MSG msg = {};
		while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// TODO: Pull This?
		SwapBuffers(GetDC(m_hWnd));
	}

	wchar_t* Win32WindowIMP::convertToWideChar(const std::string& str) {
		// Grab size of wide string
		int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);

		// Allocate memory for the wide string
		wchar_t* wide_string = new wchar_t[size_needed]; // kinda hacky but workarounds are more hacky

		// Convert
		MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wide_string, size_needed);
		return wide_string;
	}

}

#endif