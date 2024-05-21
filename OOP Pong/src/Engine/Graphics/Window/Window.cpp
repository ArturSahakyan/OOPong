#include "Window.h"

#include "../GraphicsKit.h"

namespace PG {
	
	Window::Window() {
		m_window = GraphicsKit::Instance()->CreateWindowIMP();
		m_context = WindowContext();
	}

	Window::~Window() {
		m_context.deleteContext();
		m_window->close();
		delete m_window;
	}

	void Window::open(const WindowProps& props) {
		m_window->open(props);
		m_context.createContext(m_window->getWindowHandle());
	}

	void Window::close() {
		m_window->close();
	}

	void Window::clear() {
		m_context.clearScreen();
	}

	void Window::update() {
		this->handleEvents();
		m_context.swapBuffers();
	}

	void Window::handleEvents() {
		m_window->handleEvents();
	}

}