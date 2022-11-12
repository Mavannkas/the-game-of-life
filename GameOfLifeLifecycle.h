#pragma once
#include "Coords.h"
#include "Grid.h"

class GameOfLifeLifecycle
{
public:
	void initFields(vector<Coords> coords);
	void start();
protected:
	int _timeToWait = 0;
	Grid oldGrid = Grid(0, 0);
	Grid grid = Grid(0, 0);

	GameOfLifeLifecycle(int x, int y, int timeToWait);

	virtual void theEnd() {};
	virtual void generateNextGridState() {};

	void nextTick();
	void clear();
};

