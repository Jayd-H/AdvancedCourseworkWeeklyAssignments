# Week 1

## Q1 Hello World

I ran the program and it printed "Hello World"

## Q2 Creating a new project

### Question

Create a new Empty C++ Console project called Temperature by using the project application wizard. This is done by right clicking on the 500083-Lab-A solution in the Solution Explorer Window and selecting Add » New Project.

NB: Be careful to select a C++, Empty Project

Create a new cpp file within the temperature project by right clicking on the Temperature project in the Solution Explorer Window and select Add » Add New Item.

Write a program to input a Fahrenheit measurement, convert it and output a Celsius value. The conversion formula is

celsius = 5/9 * (fahrenheit-32)
NB: You may want to select the Temperature project as the default project; to do this right click on the Temperature project and select Set as Startup Project.

Also what happens if you dividing two integers?

### Answer

I followed the instructions and created a new project and coded my fahrenheit-celcius converter. After I wrote the program, I had a logic error where no matter what I inputted as the fahrenheit temperature, celcius would always appear as 0. I fixed this by changing the integers used in my conversion equations to include a decimal point.

### Code
```cpp
	#include <iostream>
	using namespace std;

	int main(int argc, char** argv) {

		std::cout << "Input fahrenheit: " << endl;

		float ftemp;
		std::cin >> ftemp;

		const float ctemp = (5.0 / 9.0 * (ftemp - 32.0));

		std::cout << "Fahrenheit:" << ftemp << endl;
		std::cout << "Celcius:" << ctemp << endl;

	}
```
##  Q3 Types

### Question

Using the “Hello World” program as a starting point, write a program that prints out the size in bytes of each of the fundamental data types in C++.

Hint: Make use of the sizeof() operator, that returns the size of any data type.

Remember to include both the signed and unsigned versions of each data type.

### Answer

I wrote a simple program to declare each of the fundamental datatypes, both signed and unsigned, and printed out the size of them all in memory.

### Code
```cpp
	#include <iostream>
	using namespace std;

	int main (int argc, char **argv) {

		cout << "Hello World" << endl;

		// Short
		const short shortnum = 5;
		cout << "Short: " << shortnum << " Size: " << sizeof(shortnum) << endl;

		const unsigned short ushortnum = 5;
		cout << "Unsigned Short: " << ushortnum << " Size: " << sizeof(ushortnum) << endl;

		// Long
		const short longnum = 5;
		cout << "Long: " << longnum << " Size: " << sizeof(longnum) << endl;

		const unsigned short ulongnum = 5;
		cout << "Unsigned Long: " << ulongnum << " Size: " << sizeof(ulongnum) << endl;

		// Int
		const int intnum = 5;
		cout << "Integer: " << intnum << " Size: " << sizeof(intnum) << endl;

		const unsigned int uintnum = 5;
		cout << "Unsigned Integer: " << uintnum << " Size: " << sizeof(uintnum) << endl;

		// Char
		const char *letter = "G";
		cout << "Char: " << letter << " Size: " << sizeof(letter) << endl;

		const char word[] = "GG";
		cout << "Char: " << word << " Size: " << sizeof(word) << endl;

		// Float
		const float fnum = 5.0;
		cout << "Float: " << intnum << " Size: " << sizeof(float) << endl;

	}
```
## Q4 Floating point precision

### Question

In the lectures we discussed the precision of floating point numbers within C++, and how due to this precision the equality operator was unreliable.

Write a simple program that includes the lines:
```cpp
	double x = 10.0;
	double y = 10.0;
	if (x == y)
		cout << “X and Y are identical” << endl;
```
Did the program execute as expected?
Now try y = 20.0  / 2.0 and execute the program again.
Then try a more complex calculation for y e.g.
```cpp
	const double x = 100000.123456789;
	const double a = 200000.123456789;
	double y = (x + a) / x;
	double z = 1.0 + (a / x);
	if (y == z) 
	cout << “y and z are identical” << endl;
```
Now try different values for x and a

Printing out the values of x, y and z, may be useful in helping you form an opinion of what is happening.

Once you’re confident you understand the logic, investigate:

double z = x / y;
How small does y have to be before you get a “divide by zero” error? Does the value of x affect the result?

### Answer

I ran this code

```cpp
#include <iostream>
using namespace std;

int main(int argn, char* argv[])
{
	const double x = 10.0;
	const double y = 10.0;
	if (x == y) {
		std :: cout << "X and Y are identical" << endl;
	}
}
```
And got the expected "X and Y are identical" output. I ran it multiple times and consistently got the same output.

However, when I ran this code

```cpp
#include <iostream>
using namespace std;

int main(int argn, char* argv[])
{
	const double x = 100000.123456789;
	const double a = 200000.123456789;
	double y = (x + a) / x;
	double z = 1.0 + (a / x);
	if (y == z) {
		std :: cout << "X and Y are identical" << endl;
	}
}
```

I got no resulted output. I modified the code to print out all the values, which follow.

x = 100000
a = 200000
y = 3
z = 3

I wanted to see how small I could get a number before a divide by zero error, so I wrote a simple program to test that.

```cpp
double oldvalue = 100.0;
double divisor = 1.0;
bool divisable = true;
while (divisable) {
	if (divisor == 0) {
		std::cout << "Divisor has reached zero" << endl;
		divisable = false;
	}
	double newvalue = oldvalue / divisor;
	std::cout << "Old value: " << oldvalue << "  Divisor: " << divisor << "  New value: " << newvalue << endl;
	divisor /= 2;
}
```

In this code, the divisor should never reach 0, only infinitely approach it. The program falsely claims the divisor has reached 0 after it has done 4.94066e-324 / 2. Honestly, I thought it would have reached that conclusion earlier than it did. To test if oldvalue effected this, I modified the code slightly.

```cpp
oldvalue = oldvalue / divisor;
std::cout << "Old value: " << oldvalue << "  Divisor: " << divisor << endl;
```

This did not effect the outcome, with the program still claiming the divisor has reached 0 after it has done 4.94066e-324 / 2.

## Q5 C#/C++ Iteration Comparison (for loop)

### Question

In the lectures we have looked at constructs and iterators.

Below is some C# code that calculates the factorial of a number (see https://www.mathsisfun.com/numbers/factorial.html for details of a factorial).

```cpp
static void Main(string[] args)
{
   int factorialNumber = 5;
   int factorialTotal = 1;

   for(int n = 2; n <= factorialNumber; ++n)
   {
      factorialTotal *= n;
   }

   System.Console.WriteLine(factorialTotal);
}
```

Port the above C# code in to C++ using the provided Main.cpp file.

[LAB BOOK - Add your C++ code to your lab book. Then reflect on what you have to change (or not change) from C# to C++ in terms of the iteration]

### Answer