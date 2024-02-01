#include <iostream>
using namespace std;

int main (int argc, char **argv) {

	cout << "Hello World" << endl;

	// Short
	const short shortnum = 5;
	cout << "Short: " << shortnum << " Size: " << sizeof(shortnum) << endl;

	const unsigned short ushortnum = 5;
	cout << "Unsigned Short: " << ushortnum << " Size: " << sizeof(ushortnum) << endl;

	// Long
	const short longnum = 5;
	cout << "Long: " << longnum << " Size: " << sizeof(longnum) << endl;

	const unsigned short ulongnum = 5;
	cout << "Unsigned Long: " << ulongnum << " Size: " << sizeof(ulongnum) << endl;

	// Int
	const int intnum = 5;
	cout << "Integer: " << intnum << " Size: " << sizeof(intnum) << endl;

	const unsigned int uintnum = 5;
	cout << "Unsigned Integer: " << uintnum << " Size: " << sizeof(uintnum) << endl;

	// Char
	const char *letter = "G";
	cout << "Char: " << letter << " Size: " << sizeof(letter) << endl;

	const char word[] = "GG";
	cout << "Char: " << word << " Size: " << sizeof(word) << endl;

	// Float
	const float fnum = 5.0;
	cout << "Float: " << intnum << " Size: " << sizeof(float) << endl;

}