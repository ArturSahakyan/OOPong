#ifndef GAME_H
#define GAME_H

#include "Engine/Graphics/Window/RenderWindow.h"

class Game
{
private:
	bool m_isRunning;
	bool m_isShutDown;

	PG::RenderWindow m_window;

private:
	void initSystems();
	void initProps();
	void shutDownSystems();

	void gameLoop();

public:


public:
	Game();
	~Game();

	void run();
};

#endif // GAME_H