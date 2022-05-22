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

	node[f.second - 1][f.first - 1] = evaluate_position(f.first, f.second, f.first - 1, f.second - 1);
	node[f.second - 1][f.first] = evaluate_position(f.first, f.second, f.first, f.second - 1);
	node[f.second - 1][f.first + 1] = evaluate_position(f.first, f.second, f.first + 1, f.second - 1);

	node[f.second][f.first - 1] = evaluate_position(f.first, f.second, f.first - 1, f.second);
	node[f.second][f.first + 1] = evaluate_position(f.first, f.second, f.first + 1, f.second);

	node[f.second + 1][f.first - 1] = evaluate_position(f.first, f.second, f.first - 1, f.second + 1);
	node[f.second + 1][f.first] = evaluate_position(f.first, f.second, f.first, f.second + 1);
	node[f.second + 1][f.first + 1] = evaluate_position(f.first, f.second, f.first + 1, f.second + 1);

	print_stage(n);

	n = 1;

	while (!target_found || !all_target_nodes_ver)
	{

		//progresion en x

		for (int i = 0, idx = f.first - n, idy = f.second - n; i < ((2 * n) + 1); i++, idx++)
		{
			if (idx >= 1 && idx < map[0].size() - 1 && idy >= 1 && idy < map.size() - 1)
			{
				if (map[idy][idx].get_state())
				{
					//parte superior del cuadrado
					node[idy - 1][idx - 1] = evaluate_position(idx, idy, idx - 1, idy - 1);
					node[idy - 1][idx] = evaluate_position(idx, idy, idx, idy - 1);
					node[idy - 1][idx + 1] = evaluate_position(idx, idy, idx + 1, idy - 1);

					node[idy][idx - 1] = evaluate_position(idx, idy, idx - 1, idy);
					node[idy][idx + 1] = evaluate_position(idx, idy, idx + 1, idy);

					node[idy + 1][idx - 1] = evaluate_position(idx, idy, idx - 1, idy + 1);
					node[idy + 1][idx] = evaluate_position(idx, idy, idx, idy + 1);
					node[idy + 1][idx + 1] = evaluate_position(idx, idy, idx + 1, idy + 1);
				}
			}
		}

		for (int i = 0, idx = f.first - n, idy = f.second + n; i < ((2 * n) + 1); i++, idx++)
		{
			if (idx >= 1 && idx < map[0].size() - 1 && idy >= 1 && idy < map.size() - 1)
			{
				if (map[idy][idx].get_state())
				{
					//parte inferior del cuadrado
					node[idy - 1][idx - 1] = evaluate_position(idx, idy, idx - 1, idy - 1);
					node[idy - 1][idx] = evaluate_position(idx, idy, idx, idy - 1);
					node[idy - 1][idx + 1] = evaluate_position(idx, idy, idx + 1, idy - 1);

					node[idy][idx - 1] = evaluate_position(idx, idy, idx - 1, idy);
					node[idy][idx + 1] = evaluate_position(idx, idy, idx + 1, idy);

					node[idy + 1][idx - 1] = evaluate_position(idx, idy, idx - 1, idy + 1);
					node[idy + 1][idx] = evaluate_position(idx, idy, idx, idy + 1);
					node[idy + 1][idx + 1] = evaluate_position(idx, idy, idx + 1, idy + 1);
				}
			}
		}

		//progresion en y

		for (int i = 0, idx = f.first - n, idy = f.second - n + 1; i < ((2 * n) + 1) - 1; i++, idy++)
		{
			if (idx >= 1 && idx < map[0].size() - 1 && idy >= 1 && idy < map.size() - 1)
			{
				if (map[idy][idx].get_state())
				{
					//parte izquierda
					node[idy - 1][idx - 1] = evaluate_position(idx, idy, idx - 1, idy - 1);
					node[idy - 1][idx] = evaluate_position(idx, idy, idx, idy - 1);
					node[idy - 1][idx + 1] = evaluate_position(idx, idy, idx + 1, idy - 1);

					node[idy][idx - 1] = evaluate_position(idx, idy, idx - 1, idy);
					node[idy][idx + 1] = evaluate_position(idx, idy, idx + 1, idy);

					node[idy + 1][idx - 1] = evaluate_position(idx, idy, idx - 1, idy + 1);
					node[idy + 1][idx] = evaluate_position(idx, idy, idx, idy + 1);
					node[idy + 1][idx + 1] = evaluate_position(idx, idy, idx + 1, idy + 1);
				}
			}
		}

		for (int i = 0, idx = f.first + n, idy = f.second - n + 1; i < ((2 * n) + 1) - 1; i++, idy++)
		{
			if (idx >= 1 && idx < map[0].size() - 1 && idy >= 1 && idy < map.size() - 1)
			{
				if (map[idy][idx].get_state())
				{
					//parte derecha
					node[idy - 1][idx - 1] = evaluate_position(idx, idy, idx - 1, idy - 1);
					node[idy - 1][idx] = evaluate_position(idx, idy, idx, idy - 1);
					node[idy - 1][idx + 1] = evaluate_position(idx, idy, idx + 1, idy - 1);

					node[idy][idx - 1] = evaluate_position(idx, idy, idx - 1, idy);
					node[idy][idx + 1] = evaluate_position(idx, idy, idx + 1, idy);

					node[idy + 1][idx - 1] = evaluate_position(idx, idy, idx - 1, idy + 1);
					node[idy + 1][idx] = evaluate_position(idx, idy, idx, idy + 1);
					node[idy + 1][idx + 1] = evaluate_position(idx, idy, idx + 1, idy + 1);
				}
			}
		}

		if (target_found)
		{

		}

		print_stage(n);

		n++;
	}
}

int Solver::evaluate_position(int xo, int yo, int xt, int yt)
{
	int calc = UINT_MAX;

	if (map[yt][xt].get_state() && map[yo][xo].get_state())
	{
		calc = sqrt(((std::abs(xt) - std::abs(xo)) * (std::abs(xt) - std::abs(xo))) + ((std::abs(yt) - std::abs(yo)) * (std::abs(yt) - std::abs(yo)))) + node[yo][xo];

		if (node[yt][xt] > calc)
		{
			return calc;
		}
		else
		{
			return node[yt][xt];
		}		
	}

	return UINT_MAX;
}

void Solver::print_stage(int n)
{
	std::cout << "\n";
	std::cout << "n = " << n << "\n";
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[0].size(); j++)
		{
			if (node[i][j] == UINT_MAX)
			{
				std::cout << "L";
			}
			else
			{
				std::cout << node[i][j];
			}
		}
		std::cout << "\n";
	}
}
