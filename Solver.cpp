#include "Solver.h"

Solver::Solver(std::vector<std::vector<Tile>>& map, std::pair<int, int>& f)
	:
	map(map),
	f(f)
{
	target_found = false;
	all_target_nodes_ver = false;

	for (int i = 0; i < map.size(); i++)
	{
		node.emplace_back();

		for (int j = 0; j < map[0].size(); j++)
		{
			if (j == f.first && i == f.second)
			{
				node[i].push_back(0);
			}
			else
			{
				node[i].push_back(UINT_MAX);
			}
		}
	}
}

Solver::~Solver()
{
}

void Solver::run()
{
	int n = 0;

	while (!target_found || !all_target_nodes_ver)
	{
		for (int i = 0, idx = f.first - n, idy = f.second - n; i < ((2 * n) + 1); i++)
		{

		}

		if (target_found)
		{

		}

		n++;
	}
}
