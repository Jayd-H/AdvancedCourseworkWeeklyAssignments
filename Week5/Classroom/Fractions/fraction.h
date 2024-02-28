#pragma once
#include <iostream>

class Fraction {
public:
    // Default constructor
    Fraction();

    // Constructor with parameters
    // Also acts as a conversion constructor for int to Fraction
    Fraction(int num, int den = 1); // Default denominator is 1 for whole numbers

    // Overloaded operators
    // Arithmetic operations with Fraction on both sides
    Fraction operator+(const Fraction& rhs) const;
    Fraction operator-(const Fraction& rhs) const;
    Fraction operator*(const Fraction& rhs) const;
    Fraction operator/(const Fraction& rhs) const;

    // Arithmetic operations with int on the right-hand side
    Fraction operator+(int rhs) const;
    Fraction operator-(int rhs) const;
    Fraction operator*(int rhs) const;
    Fraction operator/(int rhs) const;

    // Arithmetic operations with int on the left-hand side
    friend Fraction operator+(int lhs, const Fraction& rhs);
    friend Fraction operator-(int lhs, const Fraction& rhs);
    friend Fraction operator*(int lhs, const Fraction& rhs);
    friend Fraction operator/(int lhs, const Fraction& rhs);

    // Accessors and mutators
    int Num() const;
    int Den() const;
    void Num(int num);
    void Den(int den);

    // Friend functions for stream insertion and extraction
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
    friend std::istream& operator>>(std::istream& in, Fraction& f);

private:
    int m_num; // Numerator
    int m_den; // Denominator, should not be zero
};
