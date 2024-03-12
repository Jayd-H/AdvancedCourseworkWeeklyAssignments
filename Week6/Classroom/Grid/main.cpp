#include <iostream>
#include "Grid.h"
using namespace std;

int main (int, char**) {
	Grid<int> grid;
	grid.LoadGrid("Grid1.txt");
	std::cout << grid;
	grid.SaveGrid("OutGrid.txt");

	return 0;
}