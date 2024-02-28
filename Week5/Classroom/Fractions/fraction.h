#pragma once
#include <iostream>

class Fraction {
public:
	// default constructor
	Fraction();
	// specific constructor
	Fraction(int num, int den);

	// arithmetic operations
	Fraction Add(const Fraction& rhs) const;
	Fraction Subtract(const Fraction& rhs) const;
	Fraction Multiply(int scale) const;
	Fraction Divide(int scale) const;

	// getters and setters
	int Num() const;
	int Den() const;

	void Num(int num);
	void Den(int den);

	// input and output
	void Write(std::ostream& out) const;
	void Read(std::istream& in);

	private:
		int m_num;
		int m_den;
};