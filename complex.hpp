#pragma once
#include <iostream>
#include <limits>
#include <stdexcept>

class Complex
{
private:
    double real, im;

public:
    Complex(double real, double im);
    Complex();
    inline constexpr double Real() { return this->real; }
    inline constexpr double Imaginary() { return this->im; }

    // PLUS

    Complex operator+=(const Complex &rhs);
    Complex operator+=(const double &rhs);
    friend Complex operator+(Complex lhs, const Complex &rhs);
    friend Complex operator+(Complex lhs, const double &rhs);
    friend Complex operator+(double lhs, const Complex &rhs);

    // TIMES

    Complex operator*=(const Complex &rhs);
    Complex operator*=(const double &rhs);
    friend Complex operator*(Complex lhs, const Complex &rhs);
    friend Complex operator*(Complex lhs, const double &rhs);
    friend Complex operator*(double lhs, const Complex &rhs);

    // MINUS

    Complex operator-=(const Complex &rhs);
    Complex operator-=(const double &rhs);
    friend Complex operator-(Complex lhs, const Complex &rhs);
    friend Complex operator-(Complex lhs, const double &rhs);
    friend Complex operator-(double lhs, const Complex &rhs);

    Complex operator/=(const Complex &rhs);
    Complex operator/=(const double &rhs);
    friend Complex operator/(Complex lhs, const Complex &rhs);
    friend Complex operator/(Complex lhs, const double &rhs);
    friend Complex operator/(double lhs, const Complex &rhs);

    // PRINT

    friend std::ostream &operator<<(std::ostream &os, const Complex &z);
};

static const Complex CONST_I = Complex(0, 1);