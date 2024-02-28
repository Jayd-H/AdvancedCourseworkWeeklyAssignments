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
	Fraction operator+(const Fraction& rhs) const { return Add(rhs); }

	Fraction Subtract(const Fraction& rhs) const;
	Fraction operator-(const Fraction& rhs) const { return Subtract(rhs); }

	Fraction Multiply(int scale) const;
	Fraction operator*(int scale) const { return Multiply(scale); }

	Fraction Divide(int scale) const;
	Fraction operator/(int scale) const { return Divide(scale); }

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

std::ostream& operator<<(std::ostream& out, const Fraction& f);
std::istream& operator>>(std::istream& in, Fraction& f);
Fraction operator*(int scale, const Fraction& f);
Fraction operator/(int scale, const Fraction& f);
Fraction operator+(int scale, const Fraction& f);
Fraction operator-(int scale, const Fraction& f);