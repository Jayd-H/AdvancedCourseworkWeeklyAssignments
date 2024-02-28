#include <iostream>
using namespace std;

void myswap(int& lhs, int& rhs) {
	int temp = lhs;
	lhs = rhs;
	rhs = temp;
}

int clamp(int value, int low, int high) {
	if (value < low)
		return low;
	if (value > high)
		return high;
	return value;
}

int main(int, char**) {

	int a = 10;
	int b = 20;
	
	cout << "a=" << a << ", b=" << b << endl;

	myswap(a, b);

	cout << "a=" << a << ", b=" << b << endl;
	
	return 0;
}