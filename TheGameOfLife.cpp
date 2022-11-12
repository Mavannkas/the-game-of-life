#include <iostream>
#include <fstream>
#include <vector>
#include "Coords.h"
#include "GameOfLifeConway.h"
#include "GameOfLifeLifecycle.h"
using namespace std;

int main();


struct Params {
	int x;
	int y;
	int time;
	vector<Coords> coordsArr;
};

vector<Coords> getCoordsFromFile(ifstream& file);
void initTheGameOfLife(Params params);

int main()
{
	ifstream file("sample-data.txt");
	Params params;
	file >> params.x;
	file >> params.y;
	file >> params.time;

	params.coordsArr = getCoordsFromFile(file);
	file.close();

	initTheGameOfLife(params);
}

vector<Coords> getCoordsFromFile(ifstream& file) {
	vector<Coords> coordsArr;
	string buffer;
	while (!file.eof()) {
		Coords coords;
		file >> coords.x >> coords.y;
		coordsArr.push_back(coords);
	}
	return coordsArr;
}

void initTheGameOfLife(Params params) {
	GameOfLifeConway game = GameOfLifeConway(params.x, params.y, params.time);
	game.initFields(params.coordsArr);
	game.start();
}