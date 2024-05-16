#ifndef GAME_H
#define GAME_H

class Game
{
private:
	bool m_isRunning;
	bool m_isShutDown;

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