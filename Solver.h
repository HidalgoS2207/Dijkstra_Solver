#pragma once

#include "Tile.h"

#include <vector>
#include <utility>
#include <limits>

class Solver
{
public:
	Solver(std::vector<std::vector<Tile>>& map,std::pair<int,int>& f);
	~Solver();

	void run();
private:
	std::vector<std::vector<Tile>>& map;

	std::pair<int, int>& f;
	std::pair<int, int>& t;

	std::vector<std::vector<unsigned int>>node;

	bool target_found;
	bool all_target_nodes_ver;
};