#include "GameOfLifeLifecycle.h"
#include <stdlib.h>
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono;

GameOfLifeLifecycle::GameOfLifeLifecycle(int x, int y, int timeToWait)
{
	_timeToWait = timeToWait;
	grid = Grid(x, y);
	oldGrid = Grid(x, y);
}

void GameOfLifeLifecycle::nextTick()
{
	oldGrid = grid;

	clear();
	oldGrid.print();

	generateNextGridState();
	sleep_for(milliseconds(_timeToWait));

	if (oldGrid == grid) {
		theEnd();
	}
	else {
		nextTick();
	}
}

void GameOfLifeLifecycle::clear()
{
	system("CLS");
}

void GameOfLifeLifecycle::initFields(vector<Coords> coordsArr)
{
	for (int i = 0; i < coordsArr.size(); i++)
	{
		Coords coords = coordsArr[i];
		grid.setState(coords.x, coords.y, true);
	}
}

void GameOfLifeLifecycle::start()
{
	nextTick();
}
