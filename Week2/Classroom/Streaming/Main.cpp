#include <iostream>

int main(int argn, char* argv[])
{
	int i;
	float f;
	// take an int and float from the console - separated by a space, e.g. "1 6.7"
	std::cin >> i >> f;
	// output the int and float to the console
	std::cout << "i=" << i << ", f=" << f << std::endl;
}
