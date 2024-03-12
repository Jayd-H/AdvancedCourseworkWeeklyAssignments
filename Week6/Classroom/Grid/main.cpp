#include <iostream>
#include "Grid.h"

float LoadSingleNumber(const char* filename) {
	std::ifstream fileStream(filename);
	float number;
	fileStream >> number;
	return number;
}

int main(int, char**) {
	//Grid<float> grid;
	//grid.LoadGrid("Grid1.txt");
	//std::cout << grid;
	//grid.SaveGrid("OutGrid.txt");

	float num = LoadSingleNumber("Grid1.txt");
	std::cout << num << std::endl;
	return 0;

}