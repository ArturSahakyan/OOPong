#ifndef WINDOWCONTEXTIMP_H
#define WINDOWCONTEXTIMP_H

namespace PG {

	// TODO: Delete Context
	class WindowContextIMP {
	public:
		WindowContextIMP() {}
		~WindowContextIMP() {}

		virtual void createContext(void* window_data) = 0;
		virtual void deleteContext() = 0;

		virtual void swapBuffers() = 0;
		virtual void clearScreen() = 0;
	};

}

#endif // WINDOWCONTEXTIMP_H