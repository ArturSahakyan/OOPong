#include "Window.h"

#include "../GraphicsKit.h"

namespace PG {
	
	Window::Window() {
		m_window = GraphicsKit::Instance()->CreateWindowIMP();
	}

	Window::~Window() {
		m_window->close();
	}

	void Window::open(const WindowProps& props) {
		m_window->open(props);
	}

	void Window::close() {
		m_window->close();
	}

	void Window::clear() {
		m_window->clear();
	}

	void Window::update() {
		this->handleEvents();
		// TODO: Swap Double Buffer
	}

	void Window::handleEvents() {
		m_window->handleEvents();
	}

}