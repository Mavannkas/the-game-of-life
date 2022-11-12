#include "GameOfLifeConway.h"
#include "Grid.h"

void GameOfLifeConway::theEnd()
{
	cout << "The end";
}

void GameOfLifeConway::generateNextGridState()
{
    this->grid = Grid(this->oldGrid.getX(), this->oldGrid.getY());

	for (int i = 0; i < this->oldGrid.getX(); i++)
	{
		
		for (int j = 0; j < this->oldGrid.getY(); j++)
		{
			bool t = this->oldGrid.isAlive(i, j);
			this->grid.setState(i, j, this->oldGrid.isAlive(i, j));
		}
	}
}
