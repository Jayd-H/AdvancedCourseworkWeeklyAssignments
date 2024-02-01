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