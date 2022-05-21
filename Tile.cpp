#include "Tile.h"

Tile::Tile(int x, int y)
	:
	pos_x(x),
	pos_y(y),
	state(true)
{}

Tile::~Tile()
{}

void Tile::set_state(bool state)
{
	this->state = state;
}

bool Tile::get_state()
{
	return state;
}
