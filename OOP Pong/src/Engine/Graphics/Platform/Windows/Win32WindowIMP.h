#ifndef WIN32WINDOWIMP_H
#define WIN32WINDOWIMP_H

#include "../WindowIMP.h"

#ifdef PG_PLATFORM_WINDOWS
#include <Windows.h>

namespace PG {

	LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	class Win32WindowIMP : public WindowIMP {
	private:
		HINSTANCE m_hInstance;
		HWND m_hWnd;

	private:
		wchar_t* convertToWideChar(const std::string&);

	public:
		Win32WindowIMP();
		~Win32WindowIMP();

		void open(const WindowProps&) override;
		void close() override;

		void* getWindowHandle() override;

		void handleEvents() override;
	};

}

#else
namespace PG {
	// This Class Will Never Get Created Anyway
	class Win32WindowIMP : public WindowIMP {
	public:
		Win32WindowIMP() {}
		~Win32WindowIMP() {}

		void open(const WindowProps&) {}
		void close() {}

		void* getWindowHandle() { return nullptr; }

		void handleEvents() {}
	};
}
#endif

#endif // WIN32WINDOWIMP_H