#include <iostream>
#include "Game.hpp"

int main()
{
	Game game;

	bool gameInit = game.InitSandGrid();

	if (gameInit)
	{
		game.SimulationLoop();
	}

	game.EndSimulation();

	return 0;
}
