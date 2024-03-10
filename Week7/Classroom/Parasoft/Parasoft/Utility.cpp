#include "Utility.h"


Utility::Utility(void) : m_numberArray(nullptr), m_size(0)
{
}

Utility::~Utility(void)
{
	if (m_numberArray) {
		delete[] m_numberArray;
		m_numberArray = nullptr;
	}
}

void Utility::SetSize(const int size)
{
	if(m_numberArray) delete [] m_numberArray;
	m_size = size;
	m_numberArray = new int[m_size];
}

void Utility::Process() const
{
	for(int n = 0; n < m_size-1; ++n)
	{
		int result = Mult(m_numberArray[n], m_numberArray[n+1]);
	}
}

int Utility::Mult(int a, int b) const
{
	return a * b;
}