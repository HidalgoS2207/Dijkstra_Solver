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
		origin.emplace_back();

		for (int j = 0; j < map[0].size(); j++)
		{
			if (j == f.first && i == f.second)
			{
				node[i].push_back(0);
			}
			else
			{
				node[i].push_back(INT_MAX);
			}

			origin[i].push_back({ 0,0 });
		}
	}


}

Solver::~Solver()
{
}

void Solver::run()
{
	origin[f.second][f.first] = { f.first,f.second };

	int n = 0;

	node[f.second - 1][f.first - 1] = evaluate_position(f.first, f.second, f.first - 1, f.second - 1);
	node[f.second - 1][f.first] = evaluate_position(f.first, f.second, f.first, f.second - 1);
	node[f.second - 1][f.first + 1] = evaluate_position(f.first, f.second, f.first + 1, f.second - 1);

	node[f.second][f.first - 1] = evaluate_position(f.first, f.second, f.first - 1, f.second);
	node[f.second][f.first + 1] = evaluate_position(f.first, f.second, f.first + 1, f.second);

	node[f.second + 1][f.first - 1] = evaluate_position(f.first, f.second, f.first - 1, f.second + 1);
	node[f.second + 1][f.first] = evaluate_position(f.first, f.second, f.first, f.second + 1);
	node[f.second + 1][f.first + 1] = evaluate_position(f.first, f.second, f.first + 1, f.second + 1);

	//print_stage(n);

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

					if (idx == t.first && idy == t.second)
					{
						target_found = true;
					}
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

					if (idx == t.first && idy == t.second)
					{
						target_found = true;
					}
				}
			}
		}

		//progresion en y

		for (int i = 0, idx = f.first - n, idy = f.second - n + 1; i < ((2 * n) + 1) - 2; i++, idy++)
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

					if (idx == t.first && idy == t.second)
					{
						target_found = true;
					}
				}
			}
		}

		for (int i = 0, idx = f.first + n, idy = f.second - n + 1; i < ((2 * n) + 1) - 2; i++, idy++)
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

					if (idx == t.first && idy == t.second)
					{
						target_found = true;
					}
				}
			}
		}

		if (target_found)
		{
			std::cout << "\nTarget Found\n";
			if (!all_target_nodes_ver)
			{
				all_target_nodes_ver = true;
			}
			else
			{
				break;
			}
		}

		print_stage();

		n++;
	}

	//print_stage(n);
	save_min_path();
}

void Solver::run_alt()
{
	origin[f.second][f.first] = { f.first,f.second };

	q.emplace(std::pair<int, int>{ f.first, f.second });

	std::vector<bool> surr_val;
	std::vector<std::pair<int, int>> surr_coor;

	for (int i = 0; i < 8; i++)
	{
		surr_val.push_back(false);
		surr_coor.emplace_back(std::pair<int, int>{ 0, 0 });
	}

	while (!q.empty())
	{
		surr_val[0] = val_pos(q.front().first - 1, q.front().second - 1);
		surr_val[1] = val_pos(q.front().first, q.front().second - 1);
		surr_val[2] = val_pos(q.front().first + 1, q.front().second - 1);
		surr_val[3] = val_pos(q.front().first + 1, q.front().second);
		surr_val[4] = val_pos(q.front().first + 1, q.front().second + 1);
		surr_val[5] = val_pos(q.front().first, q.front().second + 1);
		surr_val[6] = val_pos(q.front().first - 1, q.front().second + 1);
		surr_val[7] = val_pos(q.front().first - 1, q.front().second);

		surr_coor[0] = { q.front().first - 1, q.front().second - 1 };
		surr_coor[1] = { q.front().first, q.front().second - 1 };
		surr_coor[2] = { q.front().first + 1, q.front().second - 1 };
		surr_coor[3] = { q.front().first + 1, q.front().second };
		surr_coor[4] = { q.front().first + 1, q.front().second + 1 };
		surr_coor[5] = { q.front().first, q.front().second + 1 };
		surr_coor[6] = { q.front().first - 1, q.front().second + 1 };
		surr_coor[7] = { q.front().first - 1, q.front().second };

		for (int i = 0; i < 8; i++)
		{
			if (surr_val[i])
			{
				if (node[surr_coor[i].second][surr_coor[i].first] == INT_MAX)
				{
					q.emplace(std::pair<int, int>{ surr_coor[i].first, surr_coor[i].second });
				}

				node[surr_coor[i].second][surr_coor[i].first] = evaluate_position(q.front().first, q.front().second, surr_coor[i].first, surr_coor[i].second);
			}
		}

		q.pop();

		//print_stage();
	}

	save_min_path();

	print_solution();
}

int Solver::evaluate_position(int xo, int yo, int xt, int yt)
{
	unsigned int calc = INT_MAX;

	if (map[yt][xt].get_state() && map[yo][xo].get_state())
	{
		//calc = sqrt(((std::abs(xt) - std::abs(xo)) * (std::abs(xt) - std::abs(xo))) + ((std::abs(yt) - std::abs(yo)) * (std::abs(yt) - std::abs(yo)))) + node[yo][xo];
		calc = 1 + node[yo][xo];

		if (node[yt][xt] > calc)
		{
			origin[yt][xt] = { xo,yo };

			return calc;
		}
		else
		{
			//origin[yt][xt] = { xo,yo };

			return node[yt][xt];
		}
	}

	return node[yt][xt];
}

void Solver::print_stage()
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[0].size(); j++)
		{
			if (node[i][j] >= INT_MAX)
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

void Solver::print_solution()
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[0].size(); j++)
		{
			if (node[i][j] >= INT_MAX)
			{
				std::cout << "X";
			}
			else 
			{
				bool p = false;

				for (int k = 0; k < min_path.size(); k++)
				{
					if (min_path[k].first == j && min_path[k].second == i)
					{
						std::cout << 'a';
						p = true;
						break;
					}
				}

				if (!p)
				{
					std::cout << " ";
				}
			}
		}
		std::cout << "\n";
	}
}

void Solver::save_min_path()
{
	int idx = t.first;
	int idy = t.second;

	min_path.push_back({ idx,idy });

	//std::cout << "{" << idx << " ; " << idy << "}\n";

	while (idx != f.first || idy != f.second)
	{
		min_path.push_back({ origin[idy][idx].first, origin[idy][idx].second });

		idx = min_path.back().first;
		idy = min_path.back().second;

		//std::cout << "{" << idx << " ; " << idy << "}\n";
	}
}

bool Solver::val_pos(int x, int y)
{
	if (x >= map[0].size() || x <= 0 || y >= map.size() || y <= 0 || !map[y][x].get_state())
	{
		return false;
	}

	return true;
}
