#include "Grid.h"
#include <fstream> 
#include <iostream> 

Grid::Grid() {}
Grid::~Grid() {}


void Grid::LoadGrid(const char filename[])
{
    std::ifstream fileStream(filename); 

    if (!fileStream)
    {
        std::cout << "Could not open the file: " << filename << std::endl;
        return;
    }

    for (int y = 0; y < 9; ++y) 
    {
        for (int x = 0; x < 9; ++x) 
        {
            fileStream >> m_grid[y][x]; 
        }
    }

    fileStream.close();
}


