#pragma once

#include "Tile.h"

#include <vector>
#include <utility>
#include <limits>
#include <iostream>
#include <queue>

class Solver
{
public:
	Solver(std::vector<std::vector<Tile>>& map,std::pair<int,int>& f, std::pair<int, int>& t);
	~Solver();

	void run();
private:
	int evaluate_position(int xo,int yo,int xt,int yt);
	void print_stage();
	void print_solution();
	void save_min_path();
	bool val_pos(int x, int y);

	std::queue<std::pair<int,int>> q;

	std::vector<std::vector<Tile>>& map;

	std::pair<int, int>& f;
	std::pair<int, int>& t;

	std::vector<std::vector<unsigned int>>node;
	std::vector<std::vector<std::pair<int, int>>>origin;

	std::vector<std::pair<int, int>> min_path;

	bool target_found;
	bool all_target_nodes_ver;
};