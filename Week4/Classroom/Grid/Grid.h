#pragma once
#include <iostream>

class Grid
{
public:
	Grid();
	~Grid();

	void LoadGrid(const char filename[]);
	void SaveGrid(const char filename[]);
	friend std::ostream& operator << (std::ostream& os, const Grid& grid);
	friend std::istream& operator >> (std::istream& is, Grid& grid);

private:
	int m_grid[9][9];

};
