#pragma once

#include "Tile.h"

#include <vector>
#include <iostream>
#include <random>
#include <utility>
#include <string>
#include <fstream>

class Map
{
public:
	Map(int x, int y, int obs_density); 
	Map(std::string map_name);
	~Map();

	std::pair<int, int>& get_start();
	std::pair<int, int>& get_goal();
	bool check_tile(int x_pos,int y_pos);

	std::vector<std::vector<Tile>>& get_map_tiles();

	std::vector<std::vector<Tile>> tiles;
private:
	void generate(int obs_density);
	void print_console_test();

	int x_size;
	int y_size;

	

	std::pair<int, int>f;
	std::pair<int, int>o;

	//Solver* solver;
};