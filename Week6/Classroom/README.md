# Advanced Programming - Lab F

This tutorial introduces the reader to both template classes and recursive functions

---

## Q1. Template Grid

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

---

## Q2. Template Grid (floats)

Change the code in `main()` so that you can store `float` values instead of `int` values, i.e. `Grid<float> grid`

Run your code and step through the `LoadGrid()` method and you should see that the numbers are being stored as `float` values instead of `int` values.  The output file may still look like `int` values, because the streaming `operator<<` is doing a conversion.

Change some of the values in the `Grid1.txt` to floating point values and you should see the output is now correct.

#### [LAB BOOK - Add your the code from your `main()` function.  Add the output of `OutGrid.txt`.  Add a screenshot of the debugger showing the contents of the `grid` instance in main() after it has successfully loaded the values from file.]

---

## Q3. Binary search

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
