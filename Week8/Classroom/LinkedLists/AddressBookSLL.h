#pragma once

#include "PersonNode.h"

class AddressBookSLL
{
public:
	AddressBookSLL(void);
	~AddressBookSLL(void);

	void AddPerson(const string& name, int age);
	void DisplayAll() const;
	const PersonNode* FindPerson(const string& name) const;
	void DisplayPerson(const string& name) const;
	// bool DeletePerson(const string& name);

private:
	PersonNode* m_head;
};
