
#include <iostream>
using namespace std;
#include "AddressBookSLL.h"

/*
	This program will act as a Contacts Address Book using a Single Linked Lists
*/

int main(int argc, char **argv) {

	AddressBookSLL book;

	book.AddPerson("Darren", 21);
	book.AddPerson("Dawn", 42);
	book.AddPerson("Steven", 18);
	book.AddPerson("Sue", 27);

	book.DisplayAll();

	system("PAUSE");
}



