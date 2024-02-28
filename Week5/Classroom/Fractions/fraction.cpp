#include "fraction.h"
#include <iostream>
#include <cassert>

// Default constructor
Fraction::Fraction() : m_num(0), m_den(1) {}

// Constructor with parameters (and also a conversion constructor for int to Fraction)
Fraction::Fraction(int num, int den) : m_num(num), m_den(den) {
    assert(den != 0);
}

// Overloaded operators for Fraction + Fraction, Fraction - Fraction, etc.
Fraction Fraction::operator+(const Fraction& rhs) const {
    return Fraction(m_num * rhs.m_den + m_den * rhs.m_num, m_den * rhs.m_den);
}

Fraction Fraction::operator-(const Fraction& rhs) const {
    return Fraction(m_num * rhs.m_den - m_den * rhs.m_num, m_den * rhs.m_den);
}

Fraction Fraction::operator*(const Fraction& rhs) const {
    return Fraction(m_num * rhs.m_num, m_den * rhs.m_den);
}

Fraction Fraction::operator/(const Fraction& rhs) const {
    assert(rhs.m_num != 0); // Prevent division by zero
    return Fraction(m_num * rhs.m_den, m_den * rhs.m_num);
}

// Overloaded operators for Fraction + int, Fraction - int, etc.
Fraction Fraction::operator+(int rhs) const {
    return *this + Fraction(rhs);
}

Fraction Fraction::operator-(int rhs) const {
    return *this - Fraction(rhs);
}

Fraction Fraction::operator*(int rhs) const {
    return *this * Fraction(rhs);
}

Fraction Fraction::operator/(int rhs) const {
    return *this / Fraction(rhs);
}

// Friend functions for int + Fraction, int - Fraction, etc.
Fraction operator+(int lhs, const Fraction& rhs) {
    return Fraction(lhs) + rhs;
}

Fraction operator-(int lhs, const Fraction& rhs) {
    Fraction lhsAsFraction(lhs);
    return lhsAsFraction - rhs;
}

Fraction operator*(int lhs, const Fraction& rhs) {
    return Fraction(lhs) * rhs;
}

Fraction operator/(int lhs, const Fraction& rhs) {
    assert(rhs.Num() != 0);
    return Fraction(lhs) / rhs;
}

// Accessors
int Fraction::Num() const { return m_num; }
int Fraction::Den() const { return m_den; }

// Mutators
void Fraction::Num(int num) { m_num = num; }
void Fraction::Den(int den) {
    assert(den != 0);
    m_den = den;
}

// Stream insertion and extraction overloads
std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    out << f.Num() << '/' << f.Den();
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& f) {
    int num, den;
    in >> num;

    if (in.peek() == '/') {
        in.get();
        in >> den;
    }

    else {
        den = 1;
    }
    f.Num(num);
    f.Den(den);
    return in;
}
