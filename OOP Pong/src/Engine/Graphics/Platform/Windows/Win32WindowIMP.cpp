#include "Win32WindowIMP.h"

#include "../../GraphicsKit.h"

#ifdef PG_PLATFORM_WINDOWS

namespace PG {

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
	{
	}

	Win32WindowIMP::~Win32WindowIMP() {
		this->close();
	}

	void* Win32WindowIMP::getWindowHandle() {
		return &m_hWnd;
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

		m_props = props;
		delete class_name;
	}

	void Win32WindowIMP::close() {
		wchar_t* name = this->convertToWideChar(m_props.title);
		UnregisterClass(name, m_hInstance);
		delete name;
	}

	void Win32WindowIMP::handleEvents() {
		MSG msg = {};
		while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
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