
#include <iostream>
using namespace std;
#include "AddressBookSLL.h"

/*
	This program will act as a Contacts Address Book using a Single Linked Lists
*/

int main(int argc, char **argv) {

	AddressBookSLL book;

	book.AddPerson("John", 25);
	book.AddPerson("Jane", 30);
	book.AddPerson("Jim", 35);
	book.AddPerson("Jill", 40);

	book.DisplayAll();

	system("PAUSE");
}



