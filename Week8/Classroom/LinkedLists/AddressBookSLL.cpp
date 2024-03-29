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
	if (m_head == nullptr)
	{
		m_head = newPerson;
	}
	else
	{
		PersonNode* current = m_head;
		while (current->GetNext() != nullptr)
		{
			current = current->GetNext();
		}
		current->SetNext(newPerson);
	}
}

void AddressBookSLL::DisplayAll() const
{
	PersonNode* current = m_head;
	int index = 1;

	while (current != nullptr)
	{
		std::cout << "Person " << index++ << "\n";
		std::cout << "Name: " << current->GetName() << "\n";
		std::cout << "Age: " << current->GetAge() << "\n" << std::endl;
		current = current->GetNext();
	}
}

const PersonNode* AddressBookSLL::FindPerson(const string& name) const
{
	PersonNode* current = m_head;

	while (current != nullptr)
	{
		if (current->GetName() == name)
		{
			return current;
		}
		current = current->GetNext();
	}
	return nullptr;
}

void AddressBookSLL::DisplayPerson(const string& name) const
{
	const PersonNode* person = FindPerson(name);
	if (person != nullptr)
	{
		std::cout << "Name: " << person->GetName() << "\n";
		std::cout << "Age: " << person->GetAge() << "\n" << std::endl;
	}
	else
	{
		std::cout << "Person not found" << std::endl;
	}
}

bool AddressBookSLL::DeletePerson(const string& name)
{
	PersonNode* current = m_head;
	PersonNode* previous = nullptr;

	while (current != nullptr)
	{
		if (current->GetName() == name)
		{
			if (previous != nullptr)
			{
				previous->SetNext(current->GetNext());
			}
			else
			{
				m_head = current->GetNext();
			}
			delete current;
			return true;
		}
		previous = current;
		current = current->GetNext();
	}
	return false;
}	
