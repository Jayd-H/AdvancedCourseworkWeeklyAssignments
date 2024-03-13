#pragma once

#include <string>
using namespace std;

class PersonNode
{
public:
	PersonNode(void);
	PersonNode(const string& name, int age);
	~PersonNode(void);



private:
	string m_name;
	int m_age;
	PersonNode* m_next;
};
