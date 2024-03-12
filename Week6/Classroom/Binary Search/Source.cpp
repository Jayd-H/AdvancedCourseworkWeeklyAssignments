#include <iostream>
#include <fstream>

bool recursionBinarySearch(int* list, int start, int end, int value, int& tries, int& index) {
	if (start > end) {
		return false;
	}
	int mid = start + (end - start) / 2;
	tries++;
	if (list[mid] == value) {
		index = mid;
		return true;
	}
	else if (list[mid] > value) {
		return recursionBinarySearch(list, start, mid - 1, value, tries, index);
	}
	else {
		return recursionBinarySearch(list, mid + 1, end, value, tries, index);
	}
}


bool recursionBinarySearch(int* list, int size, int value) {
	static int tries = 0;
	tries = 0;
	int index = -1;
	bool found = recursionBinarySearch(list, 0, size - 1, value, tries, index);
	std::cout << (found ? "Found\n": "Not found\n");
	if (index != -1) {
		std::cout << "Index: " << index << "\n";
	
	}
	std::cout << "Tries: " << tries << std::endl;
	return found;
}

bool whileBinarySearch(int* list, int size, int value) {
	int tries = 0;
	int start = 0;
	int end = size - 1;
	while (start <= end) {
		tries++;
		int mid = (start + end) / 2;
		if (list[mid] == value) {
			std::cout << "Found\n";
			std::cout << "Index: " << mid << std::endl;
			std::cout << "Tries: " << tries << std::endl;
			return true;
		}
		else if (list[mid] > value) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	std::cout << "Not found\n";
	std::cout << "Tries: " << tries << std::endl;
	return false;
}

int main(int, char**) {
	int numlist[100];
	std::ifstream file("binarysearchIn.txt");
	int i = 0;

	while (file >> numlist[i]) {
		i++;
	}
	file.close();

	int value;
	std::cout << "Enter a value to search: ";
	std::cin >> value;

	std::cout << "Recursion Binary Search\n";
	recursionBinarySearch(numlist, i, value);

	std::cout << "\n";

	std::cout << "While Binary Search" << std::endl;
	whileBinarySearch(numlist, i, value);

	return 0;
}