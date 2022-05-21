#pragma once

class Tile
{
public:
	Tile(int x,int y);
	~Tile();

	void set_state(bool state);

	bool get_state();
	
private:
	int pos_x;
	int pos_y;

	bool state;
};