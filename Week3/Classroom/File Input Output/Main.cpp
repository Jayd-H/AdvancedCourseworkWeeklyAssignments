#include <iostream>
#include <fstream>
using namespace std;

/*
* Partially completed program
* The program should copy a text file
*
*/

bool Copy(char filenamein[], char filenameout[])
{
	return false;
}

int main(int argn, char* argv[])
{
	if (argn != 3) {
		cerr << "Usage: " << argv[0] << " <input filename> <output filename>" << endl;
		int keypress; cin >> keypress;
		return -1;
	}

	if (Copy(argv[1], argv[2]))
	{
		cout << "Copy successful" << endl;
	}
	else
	{
		cout << "Copy error" << endl;
	}

	system("PAUSE");
}