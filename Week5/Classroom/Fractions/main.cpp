
#include "Fraction.h"
#include <iostream>
using namespace std;

int main(int args, char** argv)
{
    Fraction f1(1, 2);        // 1/2
    Fraction f2(3, 4);        // 3/4
    Fraction result;

    result = f1.Add(f2);      // 1/2 + 3/4 = 10/8
    cout << "1/2 + 3/4 = ";
    result.Write(cout);
    cout << endl;

    result = f2.Subtract(f1); // 3/4 - 1/2 = 2/8
    cout << "3/4 - 1/2 = ";
    result.Write(cout);
    cout << endl;

    result = f2.Multiply(3);  // 3/4 * 3 = 9/4
    cout << "3/4 * 3 = ";
    result.Write(cout);
    cout << endl;

    result = f2.Divide(3);  // 3/4 / 3 = 3/12
    cout << "3/4 / 3 = ";
    result.Write(cout);
    cout << endl;

    Fraction f3;
    f3.Read(cin);             // input format is up to you, e.g. "1 2" to represent 1/2
    cout << "Read = ";
    f3.Write(cout);
    cout << endl;

    system("pause");
}