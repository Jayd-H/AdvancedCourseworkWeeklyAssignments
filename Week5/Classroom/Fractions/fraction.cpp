#include <iostream>
#include <assert.h>
#include "fraction.h"

// default constructor
Fraction::Fraction() {
	Num(0); Den(1);
}

// specific constructor
Fraction::Fraction(int num, int den) {
	Num(num); Den(den);
}

// arithmetic operations
Fraction Fraction::Add(const Fraction& rhs) const {
	return Fraction(Num() * rhs.Den() + Den() * rhs.Num(), Den() * rhs.Den());
}

Fraction Fraction::Subtract(const Fraction& rhs) const {
	return Fraction(Num() * rhs.Den() - Den() * rhs.Num(), Den() * rhs.Den());
}

Fraction Fraction::Multiply(int scale) const {
	return Fraction(Num() * scale, Den());
}

Fraction Fraction::Divide(int scale) const {
	assert(scale != 0);
	return Fraction(Num(), Den() * scale);
}

Fraction operator*(int scale, const Fraction& f) {
	return f.Multiply(scale);
}

Fraction operator/(int scale, const Fraction& f) {
	return f.Divide(scale);
}

Fraction operator+(int scale, const Fraction& f) {
	return f.Add(Fraction(scale, 1));
}

Fraction operator-(int scale, const Fraction& f) {
	return f.Subtract(Fraction(scale, 1));
}

// getters and setters

int Fraction::Num() const {
	return m_num;
}

int Fraction::Den() const {
	return m_den;
}

void Fraction::Num(int num) {
	m_num = num;
}

void Fraction::Den(int den) {
	assert(den);
	m_den = den;
}

// input and output

void Fraction::Write(std::ostream& out) const {
	out << Num() << "/" << Den();
}

void Fraction::Read(std::istream& in) {
	int num, den;
	in >> num >> den;
	Num(num); Den(den);
}

std::ostream& operator<<(std::ostream& out, const Fraction& f) {
	f.Write(out);
	return out;
}

std::istream& operator>>(std::istream& in, Fraction& f) {
	f.Read(in);
	return in;
}