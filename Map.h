#pragma once

#include "Tile.h"

#include <vector>
#include <iostream>
#include <random>

class Map
{
public:
	Map(int x, int y);
	~Map();
private:
	void generate();

	int x_size;
	int y_size;

	std::vector<std::vector<Tile>> tiles;
};