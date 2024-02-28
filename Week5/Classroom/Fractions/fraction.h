#pragma once

class Fraction {
public:
	Fraction();
	Fraction(int num, int den);

	Fraction Add(const Fraction &rhs) const;
	Fraction Subtract(const Fraction &rhs) const;
	Fraction Multiply(int scale) const;
	Fraction Divide(int scale) const;

	int Num() const;
	int Den() const;

	void Num(int num);
	void Den(int den);

	void Write(std::ostream& out) const;
	void Read(std::istream& in);
};