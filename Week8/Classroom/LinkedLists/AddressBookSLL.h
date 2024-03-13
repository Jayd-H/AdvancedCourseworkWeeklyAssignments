#pragma once

#include "PersonNode.h"

class AddressBookSLL
{
public:
	AddressBookSLL(void);
	~AddressBookSLL(void);

	void AddPerson(const string& name, int age);
	void RemovePerson(const string& name);
	void DisplayAll() const;

private:
	PersonNode* m_head;
};
