#pragma once
#include "Grid.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Grid
{
private:
	vector<vector<bool>> _grid;
	int _x;
	int _y;

public:
	Grid(int x, int y);

	int getX();

	int getY();

	bool isAlive(int x, int y);

	bool setState(int x, int y, bool state);

	bool operator== (Grid grid);

	void print();

private:
	int countNeighbours(int x, int y);

	void fillGrid(int x, int y);
	
	void setConsoleColor(int textColor, int bgColor);
};
