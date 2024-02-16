#include <iostream>
using namespace std;

int mymax(int a, int b, int c)
{
	if (a > b && a > c)
		return a;
	else if (b > a && b > c)
		return b;
	else
		return c;

}

int main(int, char**) {

	int a = 10;
	int b = 20;
	int c = 30;

	int max = mymax(a, b, c);

	cout << "a=" << a << ", b=" << b << endl;
	cout << "max=" << max << endl;

	return 0;
}

