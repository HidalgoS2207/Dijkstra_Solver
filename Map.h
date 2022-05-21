#pragma once

#include "Tile.h"
#include "Solver.h"

#include <vector>
#include <iostream>
#include <random>
#include <utility>
#include <string>

class Map
{
public:
	Map(int x, int y, int obs_density);
	~Map();
private:
	void generate(int obs_density);
	void print_console_test();

	int x_size;
	int y_size;

	std::vector<std::vector<Tile>> tiles;

	std::pair<int, int>f;
	std::pair<int, int>o;

	Solver* solver;
};