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

void Grid::SaveGrid(const char filename[])
{
    std::ofstream fileStream(filename);

    if (!fileStream)
    {
        std::cout << "Could not open the file: " << filename << std::endl;
        return;
    }

    for (int y = 0; y < 9; ++y)
    {
        for (int x = 0; x < 9; ++x)
        {
            fileStream << m_grid[y][x] << " ";
        }
        fileStream << std::endl;
    }
    fileStream.close();
}

std::ostream& operator << (std::ostream& os, const Grid& grid) {
    for (int y = 0; y < 9; ++y)
    {
        for (int x = 0; x < 9; ++x)
        {
            os << grid.m_grid[y][x] << " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator >> (std::istream& is, Grid& grid) {
    for (int y = 0; y < 9; ++y)
    {
        for (int x = 0; x < 9; ++x)
        {
            is >> grid.m_grid[y][x];
        }
    }
    return is;
}