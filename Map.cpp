#include "Map.h"

Map::Map(int x, int y, int obs_density)
	:
	x_size(x),
	y_size(y)
{
	generate(obs_density);
	print_console_test();
	
	//solver = new Solver(tiles, f,o);
	
	//solver->run();
}

Map::Map(std::string map_name)
	:
	x_size(11),
	y_size(11)
{
	std::ifstream map_file(map_name);

	if (map_file.is_open())
	{
		while (true)
		{
			map_file.get();

			if (map_file.eof())
			{
				break;
			}

			tiles.emplace_back();

			map_file.seekg(-1, std::ios_base::cur);

			while (true)
			{
				std::string tl;
				tl.clear();

				tl = map_file.get();

				if (tl == "\n")
				{
					//map_file.seekg(1, std::ios_base::cur);
					break;
				}

				if (tl == "#")
				{
					tiles.back().emplace_back(tiles.back().size()-1,tiles.size()-1);
					tiles.back().back().set_state(false);
				}
				else if (tl == "-")
				{
					tiles.back().emplace_back(tiles.back().size() - 1, tiles.size() - 1);
					tiles.back().back().set_state(true);
				}
				else if (tl == "F")
				{
					tiles.back().emplace_back(tiles.back().size() - 1, tiles.size() - 1);
					tiles.back().back().set_state(true);

					f.second = tiles.size() - 1;
					f.first = tiles.back().size() - 1;
				}
				else if (tl == "O")
				{
					tiles.back().emplace_back(tiles.back().size() - 1, tiles.size() - 1);
					tiles.back().back().set_state(true);

					o.second = tiles.size() - 1;
					o.first = tiles.back().size() - 1;
				}
				
			}

			//map_file.seekg(1, std::ios_base::cur);
		}

		map_file.close();
	}
	else
	{
		std::cout << "\nError loading map file. Standard map auto-generated.\n\n";

		generate(10);
	}

	print_console_test();
}

Map::~Map()
{
	//delete solver;
}

std::pair<int, int>& Map::get_start()
{
	return f;
}

std::pair<int, int>& Map::get_goal()
{
	return o;
}

bool Map::check_tile(int x_pos, int y_pos)
{
	if (x_pos == o.first && y_pos == o.second)
	{
		return true;
	}
	
	return false;
}

std::vector<std::vector<Tile>>& Map::get_map_tiles()
{
	return tiles;
}

void Map::print_console_test()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		for (int j = 0; j < tiles.back().size(); j++)
		{
			if (tiles[i][j].get_state())
			{
				if (f.first == j && f.second == i)
				{
					std::cout << "F";
				}
				else if (o.first == j && o.second == i)
				{
					std::cout << "O";
				}
				else
				{
					std::cout << " ";
				}
			}
			else
			{
				std::cout << "X";
			}
		}

		std::cout << "\n";
	}
}

void Map::generate(int obs_density)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, std::ceil(double(100/obs_density)));

	std::uniform_int_distribution<> x_gen(1,x_size-1);
	std::uniform_int_distribution<> y_gen(1, y_size - 1);

	for (int i = 0; i < y_size; i++)
	{
		tiles.emplace_back();

		for (int j = 0; j < x_size; j++)
		{
			tiles[i].emplace_back(j,i);

			tiles[i].back().set_state(dis(gen));
		}
	}

	for (int i = 0; i < x_size; i++)
	{
		tiles[0][i].set_state(false);
		tiles[y_size - 1][i].set_state(false);
	}

	for (int i = 1; i < y_size; i++)
	{
		tiles[i][0].set_state(false);
		tiles[i][x_size - 1].set_state(false);
	}

	f.first = 0;
	f.second = 0;

	o.first = 0;
	o.second = 0;

	while (!tiles[f.second][f.first].get_state())
	{
		f.first = x_gen(gen);
		f.second = y_gen(gen);
	}

	while (!tiles[o.second][o.first].get_state())
	{
		o.first = x_gen(gen);
		o.second = y_gen(gen);
	}
}
