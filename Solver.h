#pragma once

#include "Tile.h"

#include <vector>
#include <utility>

class Solver
{
public:
	Solver(std::vector<std::vector<Tile>>& map,std::pair<int,int>& f);
	~Solver();

	void run();
private:
	std::vector<std::vector<Tile>>& map;

	std::pair<int, int>& f;
};