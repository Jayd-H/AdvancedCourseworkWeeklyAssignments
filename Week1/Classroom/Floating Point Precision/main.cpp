#include <iostream>
using namespace std;

int main(int argn, char* argv[])
{
	//const double x = 100000.123456789;
	//const double a = 200000.123456789;
	//double y = (x + a) / x;
	//double z = 1.0 + (a / x);
	//if (y == z) {
	//	std :: cout << "X and Y are identical" << endl;
	//}

	//std::cout << x << endl;
	//std::cout << a << endl;
	//std::cout << y << endl;
	//std::cout << z << endl;

	double oldvalue = 100.0;
	double divisor = 1.0;
	bool divisable = true;
	while (divisable) {
		if (divisor == 0) {
			std::cout << "Divisor has reached zero" << endl;
			divisable = false;
		}
		oldvalue = oldvalue / divisor;
		std::cout << "Old value: " << oldvalue << "  Divisor: " << divisor << endl;
		divisor /= 2;
	}
}