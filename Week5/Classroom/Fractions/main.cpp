
#include "fraction.h"
#include <iostream>
using namespace std;

void FractionTest() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction result = f1 + f2;     // 1/2 + 3/4 = 10/8
    cout << "1/2 + 3/4 = " << result << endl;

    result = f2 - f1;     // 3/4 - 1/2 = 2/8
    cout << "3/4 - 1/2 = " << result << endl;

    result = f1 * f2;     // 1/2 * 3/4 = 3/8 

    result = f2 * 3;      // 3/4 * 3 = 9/4
    cout << "3/4 * 3 = " << result << endl;

    result = 3 * f2;      // 3/4 * 3 = 9/4
    cout << "3 * 3/4 = " << result << endl;

    result = f2 / f1;     // 3/4 / 1/2 = 3/2

    result = f2 / 3;      // 3/4 / 3 = 3/12
    cout << "3/4 / 3 = " << result << endl;

    result = 3 / f2;      // 4 / 3.4 = 12/3
    cout << "3 / 3/4 = " << result << endl;

    Fraction f4;
    cin >> f4;            // input format is up to you, e.g. "1 2" to represent 1/2
    cout << "Read = " << f4 << endl;

    system("pause");
}

void FractionCalculator() {
    cout << "This is a fraction calculator (integers also work)" << endl;
    cout << "Enter a fraction followed by an operator, followed by another fraction" << endl;
    cout << "Example: 'a/b + c/d'" << endl;
    cout << "Operators: +, -, *, /" << endl;
    while (true) {
        Fraction f1, f2;
        char op;

        cin >> f1;
        if (cin.fail()) {
            cout << "Invalid input. Please enter fractions in the format a/b." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin >> op;
        if (cin.fail() || (op != '+' && op != '-' && op != '*' && op != '/')) {
            cout << "Invalid operator. Please use one of the following: +, -, *, /" << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin >> f2;
        if (cin.fail()) {
            cout << "Invalid input. Please enter fractions in the format a/b." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (op) {
        case '+':
            cout << "Result: "<< f1 << " + " << f2 << " = " << f1 + f2 << endl;
            break;
        case '-':
            cout << "Result: " << f1 << " - " << f2 << " = " << f1 - f2 << endl;
            break;
        case '*':
            cout << "Result: " << f1 << " * " << f2 << " = " << f1 * f2 << endl;
            break;
        case '/':
            cout << "Result: " << f1 << " / " << f2 << " = " << f1 / f2 << endl;
            break;
        default:
            cout << "Invalid operator" << endl;
            break;
        }
    }
}

int main(int args, char** argv)
{
    FractionTest();
    //FractionCalculator();
    return 0;
}
