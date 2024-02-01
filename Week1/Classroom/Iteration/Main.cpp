#include <iostream>
using namespace std;

int main(int argn, char* argv[])
{
	int factorialNumber = 5;
	int factorialTotal = 1;
	for (int n = 2; n <= factorialNumber; ++n) {
		factorialTotal *= n;
	}

	std::cout << factorialTotal << endl;

	return 0;
}