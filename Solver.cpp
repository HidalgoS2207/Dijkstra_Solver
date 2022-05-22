#include "Solver.h"

Solver::Solver(std::vector<std::vector<Tile>>& map, std::pair<int, int>& f, std::pair<int, int>& t)
	:
	map(map),
	f(f),
	t(t)
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

		for (int i = 0, idx = f.first - n, idy = f.second - n; i < ((2 * n) + 1); i++, idx++)
		{
			if (idx >= 1 && idx < map[0].size() - 1)
			{
				if (map[idx][idy].get_state())
				{
					evaluate_position(idx, idy, idx - 1, idy - 1);
					evaluate_position(idx, idy, idx, idy - 1);
					evaluate_position(idx, idy, idx + 1, idy - 1);

					evaluate_position(idx, idy, idx - 1, idy);
					evaluate_position(idx, idy, idx + 1, idy);

					evaluate_position(idx, idy, idx - 1, idy + 1);
					evaluate_position(idx, idy, idx, idy + 1);
					evaluate_position(idx, idy, idx + 1, idy + 1);
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}

		for (int i = 0, idx = f.first - n, idy = f.second - n + 1; i < ((2 * n) + 1)-1; i++, idy++)
		{
			if (idx >= 1 && idx < map[0].size() - 2)
			{
				if (map[idx][idy].get_state())
				{
					evaluate_position(idx, idy, idx - 1, idy - 1);
					evaluate_position(idx, idy, idx, idy - 1);
					evaluate_position(idx, idy, idx + 1, idy - 1);

					evaluate_position(idx, idy, idx - 1, idy);
					evaluate_position(idx, idy, idx + 1, idy);

					evaluate_position(idx, idy, idx - 1, idy + 1);
					evaluate_position(idx, idy, idx, idy + 1);
					evaluate_position(idx, idy, idx + 1, idy + 1);
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}

		if (target_found)
		{

		}

		n++;
	}
}

int Solver::evaluate_position(int xo, int yo, int xt, int yt)
{
	return 0;
}
