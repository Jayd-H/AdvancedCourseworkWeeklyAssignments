#include <iostream>
#include <fstream>
using namespace std;

bool Copy(char filenamein[], char filenameout[])
{
    ifstream input;
    ofstream output;

    input.open(filenamein, ios::in);
    if (!input.is_open()) {
        cout << "Failed to open input file: " << filenamein << endl;
        return false;
    }

    output.open(filenameout, ios::out);
    if (!output.is_open()) {
        cout << "Failed to create output file: " << filenameout << endl;
        input.close(); 
        return false;
    }

    char ch;
    while (input.get(ch)) { 
        output.put(ch);
    }

    input.close();
    output.close();

    return true;
}


int main(int argn, char* argv[])
{

    for (int i = 0; i < argn; i++)
    {
		cout << "argv[" << i << "] = " << argv[i] << endl;
	}

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