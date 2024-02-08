#include <iostream>
using namespace std;

int main(int, char**) {
	const int start = 3;
	const int end = 10;
	int total = 0;

	int count = start;
	while (count < end) {
		total += count;
		count++;
	}

	cout << "Total= " << total << endl;

	return 0;
}