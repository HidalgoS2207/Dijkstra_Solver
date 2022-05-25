// Dijkstra_Solver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once

#include "Map.h"
#include "Solver.h"

#include <iostream>

int main()
{
    Map map(100,30,30);
    //Map map("map_file_002.txt");

    Solver solver(map.get_map_tiles(), map.get_start(), map.get_goal());
    solver.run();

    return 0;
}
