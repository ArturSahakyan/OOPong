#include "Game.h"

int main() {
	Game* game = new Game;
	game->run();

	delete game; // Courtesy Delete
	return 0;
}