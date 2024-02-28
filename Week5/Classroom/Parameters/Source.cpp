#include <iostream>
using namespace std;

void myswap(int* lhs, int* rhs) {
	int temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}


int& clamp(int& value, int low, int high) {
	if (value < low)
		return low;
	if (value > high)
		return high;
	return value;
}

int main(int, char**) {

	int value1 = 10;
	int value2 = 20;
	int result1 = clamp(value1, 0, 30) + clamp(value2, 0, 30);
	cout << "result1: " << result1 << endl;

	int result2 = clamp(value1, 0, 5) + clamp(value2, 0, 10);
	cout << "result2: " << result2 << endl;
	return 0;
}