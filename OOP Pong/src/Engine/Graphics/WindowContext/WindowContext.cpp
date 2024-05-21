#include "WindowContext.h"

#include "../GraphicsKit.h"

namespace PG {

	WindowContext::WindowContext() {
		m_context = GraphicsKit::Instance()->CreateWindowContextIMP();
	}

	WindowContext::~WindowContext() {
		m_context->deleteContext();
		delete m_context;
	}

	void WindowContext::createContext(void* window_data) {
		m_context->createContext(window_data);
	}

	void WindowContext::deleteContext() {
		m_context->deleteContext();
	}

	void WindowContext::swapBuffers() {
		m_context->swapBuffers();
	}

	void WindowContext::clearScreen() {
		m_context->clearScreen();
	}

}