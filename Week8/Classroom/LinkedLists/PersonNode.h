#pragma once

#include <string>
using namespace std;

class PersonNode
{
public:
	PersonNode(void);
	PersonNode(const string& name, int age);
	~PersonNode(void);

	void SetName(const string& name) { m_name = name; }
	string GetName() const { return m_name; }

	void SetAge(int age) { m_age = age; }
	int GetAge() const { return m_age; }

	void SetNext(PersonNode* next) { m_next = next; }
	PersonNode* GetNext() const { return m_next; }

	friend class AddressBookSLL;



private:
	string m_name;
	int m_age;
	PersonNode* m_next;
};
