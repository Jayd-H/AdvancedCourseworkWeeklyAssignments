#pragma once
#include <iostream>
#include <fstream>

template<class T>
class Grid
{
public:
    Grid() = default;
    ~Grid() = default;

    void LoadGrid(const char* filename); 
    void SaveGrid(const char* filename);

    friend std::ostream& operator<<(std::ostream& os, const Grid<T>& grid) {
        for (int y = 0; y < 9; ++y) {
            for (int x = 0; x < 9; ++x) {
                os << grid.m_grid[y][x] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Grid<T>& grid) {
        for (int y = 0; y < 9; ++y) {
            for (int x = 0; x < 9; ++x) {
                is >> grid.m_grid[y][x];
            }
        }
        return is;
    }

private:
    T m_grid[9][9];
};

template<class T>
void Grid<T>::LoadGrid(const char* filename) 
{
    std::ifstream fileStream(filename);
    if (!fileStream) {
        std::cout << "Could not open the file: " << filename << std::endl;
        return;
    }

    for (int y = 0; y < 9; ++y) {
        for (int x = 0; x < 9; ++x) {
            fileStream >> m_grid[y][x];
        }
    }
    fileStream.close();
}

template<class T>
void Grid<T>::SaveGrid(const char* filename)
{
    std::ofstream fileStream(filename);
    if (!fileStream) {
        std::cout << "Could not open the file: " << filename << std::endl;
        return;
    }

    for (int y = 0; y < 9; ++y) {
        for (int x = 0; x < 9; ++x) {
            fileStream << m_grid[y][x] << " ";
        }
        fileStream << std::endl;
    }
    fileStream.close();
}
