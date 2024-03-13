#include "AddressBookSLL.h"
#include <iostream>

AddressBookSLL::AddressBookSLL(void) : m_head(nullptr)
{
}

AddressBookSLL::~AddressBookSLL(void)
{
	PersonNode* current = m_head;
	PersonNode* next = nullptr;

	while (current != nullptr)
	{
		next = current->GetNext();
		delete current;
		current = next;
	}
}

void AddressBookSLL::AddPerson(const string& name, int age)
{
	PersonNode* newPerson = new PersonNode(name, age);
	newPerson->SetNext(m_head);
	m_head = newPerson;
}

void AddressBookSLL::RemovePerson(const string& name)
{
	PersonNode* current = m_head;
	PersonNode* previous = nullptr;

	while (current != nullptr)
	{
		if (current->GetName() == name)
		{
			if (previous == nullptr)
			{
				m_head = current->GetNext();
			}
			else
			{
				previous->SetNext(current->GetNext());
			}

			delete current;
			return;
		}

		previous = current;
		current = current->GetNext();
	}
}

void AddressBookSLL::DisplayAll() const
{
	PersonNode* current = m_head;

	while (current != nullptr)
	{
		cout << current->GetName() << " is " << current->GetAge() << " years old." << endl;
		current = current->GetNext();
	}
}

