#pragma once

#include "Tile.h"

#include <vector>
#include <utility>
#include <limits>
#include <iostream>

class Solver
{
public:
	Solver(std::vector<std::vector<Tile>>& map,std::pair<int,int>& f, std::pair<int, int>& t);
	~Solver();

	void run();
private:
	int evaluate_position(int xo,int yo,int xt,int yt);
	void print_stage(int n);

	std::vector<std::vector<Tile>>& map;

	std::pair<int, int>& f;
	std::pair<int, int>& t;

	std::vector<std::vector<unsigned int>>node;

	bool target_found;
	bool all_target_nodes_ver;
};