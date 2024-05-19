#ifndef WINDOWIMP_H
#define WINDOWIMP_H

#include <string>

namespace PG {

	struct WindowProps {
		std::string title = "";
		uint16_t width = 0;
		uint16_t height = 0;
	};

	class WindowIMP {
	protected:
		friend class Window;

		WindowProps m_props;

	public:
		WindowIMP() {}
		virtual ~WindowIMP() {}

		virtual void clear() = 0;

		virtual void handleEvents() = 0;

		virtual void open(const WindowProps&) = 0;
		virtual void close() = 0;
	};

}

#endif // WINDOWIMP_H
