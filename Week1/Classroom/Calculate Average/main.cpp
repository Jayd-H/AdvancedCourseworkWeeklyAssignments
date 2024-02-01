#include <iostream>
using namespace std;

int main(int argn, char* argv[])
{
	int sum = 0;
	int divisor = 0;
	do {
		std::cout << "Enter an integer, enter '-1' to stop." << endl;
		int n = 0;
		cin >> n;

		if (n < 0) {
			break;
		}

		divisor += 1;
		sum += n;
		float total = static_cast<float>(sum) / divisor;

		std::cout << "Total:" << total << endl;
		std::cout << endl;

	} while (true);

	return 0;
}