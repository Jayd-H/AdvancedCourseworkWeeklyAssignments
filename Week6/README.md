# Week 7 Advanced Programming - Lab F

This tutorial introduces the reader to both template classes and recursive functions

---

## Q1. Template Grid

### Question

Copy your `Grid` class (both the `Grid.h` and `Grid.cpp`) from lab D (or from the Grid part in Lab E if you want to add more functionality but lab D is fine for this week's work) into the Grid Project.
You are going to turn the `Grid` class into a **template** class so that we can store any type of number, e.g. float, int, double, into our 2D grid array.

In the header file `Grid.h`, add the following immediately above the class definition:

```c++
template<class T>
```

The type `T` is going to represent any number type.  Therefore you need to replace the `int` for our `m_grid` data member to be of this `T` type instead:

```c++
T m_grid[9][9];
```

Add the code in the `main()` method with the following:

```c++
Grid<int> grid;
grid.LoadGrid("Grid1.txt");
grid.SaveGrid("OutGrid.txt");
```

This is creating a new Grid that will store `int` types.

You should see that if you try to compile your code that it fails to compile.  This is because a template class must have all of the code in the header file.  Therefore move the code from the methods of your `Grid.cpp` file into the methods in the header file `Grid.h`. Then remove `Grid.cpp` from your project.  You should now find that your code compiles.

Run your code any you should have the same result as when you completed this task in Lab D.

#### [LAB BOOK - Add your `Grid.h` code]

### Answer

I first started by copying my code from a few weeks ago into this new solution. I altered my grid class to be a template and added the new 'main' logic.

#### main.cpp
```cpp
#include <iostream>
#include "Grid.h"
using namespace std;

int main (int, char**) {
	Grid<int> grid;
	grid.LoadGrid("Grid1.txt");
	grid.SaveGrid("OutGrid.txt");

	return 0;
}
```

#### grid.h
```cpp
#pragma once
#include <iostream>

template<class T>
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
	T m_grid[9][9];

};
```
#### grid.cpp
```cpp
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
```

I then moved all of my code from my grid.cpp into my grid.h, leaving me now with two files, main.cpp, and grid.h. Here are them now

#### main.cpp
```cpp
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
```

#### grid.h
```cpp
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
```

#### Output

```
1 2 3 4 5 6 7 8 9
2 3 4 5 6 7 8 9 1
3 4 5 6 7 8 9 1 2
4 5 6 7 8 9 1 2 3
5 6 7 8 9 1 2 3 4
6 7 8 9 1 2 3 4 5
7 8 9 1 2 3 4 5 6
8 9 1 2 3 4 5 6 7
9 1 2 3 4 5 6 7 8

D:\Files\Documents\#UNIY2\AP\AdvancedCourseworkWeeklyAssignments\Week6\Classroom\Debug\Grid.exe (process 31428) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
```

I also verified that the contents of grid1.txt was being correctly copied over to outgrid1.txt. As you can see, I have had to move the overloaded streaming operators inside of the class definition. This is because when I copied them over and treat them like the other functions, I was getting a linker error 'LNK2019'. I looked this up and to my understanding this error means that the linker could not find a definition for something that is declared but not defined. I found an easy fix online that involves moving them into the class definition to ensure that they are instantiated and therefore can be found. I do not know if this is considered bad practice or not, or if there is a better way to do this however. 


---

## Q2. Template Grid (floats)

### Question

Change the code in `main()` so that you can store `float` values instead of `int` values, i.e. `Grid<float> grid`

Run your code and step through the `LoadGrid()` method and you should see that the numbers are being stored as `float` values instead of `int` values.  The output file may still look like `int` values, because the streaming `operator<<` is doing a conversion.

Change some of the values in the `Grid1.txt` to floating point values and you should see the output is now correct.

#### [LAB BOOK - Add your the code from your `main()` function.  Add the output of `OutGrid.txt`.  Add a screenshot of the debugger showing the contents of the `grid` instance in main() after it has successfully loaded the values from file.]

### Answer

---

## Q3. Binary search

### Question

In this exercise, you'll implement two versions of a binary search, one using iteration, the other using a recursive function.

The text file (binarysearchIn.txt) contains 100 integers, ordered from small to large.

Create a 100 element 1D array and read the numbers from the file into the array, using the streaming operators.

Check the array within the debugger to ensure that your input code is functioning correctly.

A binary search algorithm tests a candidate value against the value stored in the middle of the array.  If the candidate is smaller, the process is repeated on the lower half of the array.  If the candidate is larger, the process is repeated on the upper half of the array.  The process is repeated until either the middle of the sub-array contains the candidate value (the candidate is found), or the sub-array contains only a single value which is not equal to the candidate value (the candidate is not in the array).  

Implement this process using a recursive function, with the following prototype

```c++
bool binarySearch(int *list, int size, int value);
```

Now create a second implementation, replacing the recursive function with a single while loop

Which implementation do you prefer, in terms of both readability and design intent?

### Answer
