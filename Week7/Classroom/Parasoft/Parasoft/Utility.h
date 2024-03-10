#pragma once
class Utility
{
public:
	Utility(void);
	~Utility(void);
	void SetSize(const int size);
	void Process() const;
	int Mult(int a, int b) const;

private:
	int *m_numberArray;
	int m_size;
};

