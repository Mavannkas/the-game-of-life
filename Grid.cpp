#include "Grid.h"
#include<iostream>
#include<windows.h>
using namespace std;

Grid::Grid(int x, int y)
{
	_y = y;
	_x = x;
	fillGrid(x, y);
}

int Grid::getX()
{
	return _x;
}

int Grid::getY()
{
	return _y;
}

bool Grid::isAlive(int x, int y)
{
	int neighbours = countNeighbours(x, y);
	bool isAliveNow = _grid[x][y];
	if (!isAliveNow && neighbours == 3) {
		return true;
	}
	else if (isAliveNow && (neighbours == 2 || neighbours == 3)) {
		return true;
	}
	return false;
}

bool Grid::setState(int x, int y, bool state)
{
	_grid[x][y] = state;
	return true;
}

bool Grid::operator==(Grid grid)
{
	for (int i = 0; i < _x; i++)
	{
		for (int j = 0; j < _y; j++)
		{
			if (_grid[i][j] != grid._grid[i][j]) {
				return false;
			}
		}
	}

	return true;
}

void Grid::setConsoleColor(int textColor, int bgColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor +
		(bgColor * 16)));
}

void Grid::print()
{
	for (int i = 0; i < _x; i++)
	{
		for (int j = 0; j < _y; j++)
		{

			if (_grid[i][j]) {
				setConsoleColor(0, 4);
				cout << "  ";
			}
			else {
				setConsoleColor(0, 15);
				cout << "  ";
			}
		}
		cout << endl;
	}
	setConsoleColor	(1, 0);
}

void Grid::fillGrid(int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		vector<bool> subArr;
		for (int j = 0; j < y; j++)
		{
			subArr.push_back(false);
		}
		_grid.push_back(subArr);
	}
}

int Grid::countNeighbours(int x, int y)
{
	int counter = 0;
	for (int i = max(0, x - 1); i < min(_x, x + 2); i++)
	{
		for (int j = max(0, y - 1); j < min(_y, y + 2); j++)
		{
			if (i == x && j == y) {
				continue;
			}

			if (_grid[i][j]) {
				counter++;
			}
		}
	}
	return counter;
}
