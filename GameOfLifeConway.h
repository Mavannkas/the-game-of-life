#pragma once
#include "Grid.h"
#include "GameOfLifeLifecycle.h"

class GameOfLifeConway : public virtual GameOfLifeLifecycle
{
public:
	GameOfLifeConway(int x, int y, int time): GameOfLifeLifecycle(x, y, time) {}

private:
	virtual void theEnd() override;
	virtual void generateNextGridState() override;
};

