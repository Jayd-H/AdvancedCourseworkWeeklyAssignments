# Week 1

## Q1 Hello World

I ran the program and it printed "Hello World"

## Q2 Creating a new project

I followed the instructions and created a new project and coded my fahrenheit-celcius converter. After I wrote the program, I had a logic error where no matter what I inputted as the fahrenheit temperature, celcius would always appear as 0. I fixed this by changing the integers used in my conversion equations to include a decimal point.

### Code

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

##  Q3 Types


