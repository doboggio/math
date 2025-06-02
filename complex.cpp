#include "complex.hpp"

Complex::Complex(double real, double im) : real(real), im(im) {}
Complex::Complex() : real(0), im(0) {}

Complex Complex::operator+=(const Complex &rhs)
{
    this->real += rhs.real;
    this->im += rhs.im;
    return *this;
}

Complex operator+(Complex lhs, const Complex &rhs)
{
    return lhs += rhs;
}

Complex Complex::operator+=(const double &rhs)
{
    this->real += rhs;
    return *this;
}

Complex operator+(Complex lhs, const double &rhs)
{
    return lhs += rhs;
}
Complex operator+(double lhs, const Complex &rhs)
{
    return Complex(lhs + rhs.real, rhs.im);
}

Complex Complex::operator*=(const Complex &rhs)
{
    //                      ac           -           bd
    auto a = this->real;
    auto b = this->im;
    auto c = rhs.real;
    auto d = rhs.im;
    this->real = (a * c) - (b * d);
    this->im = (b * c) + (a * d);
    return *this;
}

Complex Complex::operator*=(const double &rhs)
{
    this->im *= rhs;
    this->real *= rhs;
    return *this;
}

Complex operator*(Complex lhs, const Complex &rhs)
{
    return lhs *= rhs;
}
Complex operator*(Complex lhs, const double &rhs)
{
    return lhs *= rhs;
}
Complex operator*(double lhs, const Complex &rhs)
{
    return Complex(rhs.real * lhs, rhs.im * lhs);
}

Complex Complex::operator-=(const Complex &rhs)
{
    this->real -= rhs.real;
    this->im -= rhs.im;
    return *this;
}
Complex Complex::operator-=(const double &rhs)
{
    this->real -= rhs;
    return *this;
}
Complex operator-(Complex lhs, const Complex &rhs)
{
    return lhs -= rhs;
}
Complex operator-(Complex lhs, const double &rhs)
{
    lhs.real -= rhs;
    return lhs;
}
Complex operator-(double lhs, const Complex &rhs)
{
    return Complex(lhs - rhs.real, 0 - rhs.im);
}

Complex Complex::operator/=(const Complex &rhs)
{
    auto a = this->real;
    auto b = this->im;
    auto c = rhs.real;
    auto d = rhs.im;
    auto conj = (c * c) + (d * d);
    if (conj == 0)
        throw std::domain_error("Divide by zero");
    this->real = ((a * c) + (b * d)) / conj;
    this->im = ((b * c) - (a * d)) / conj;

    return *this;
}
Complex Complex::operator/=(const double &rhs)
{
    this->real /= rhs;
    this->im /= rhs;
    return *this;
}
Complex operator/(Complex lhs, const Complex &rhs)
{
    return lhs /= rhs;
}
Complex operator/(Complex lhs, const double &rhs)
{
    return lhs /= rhs;
}
Complex operator/(double lhs, const Complex &rhs)
{
    return Complex(lhs, 0) / rhs;
}

std::ostream &operator<<(std::ostream &os, const Complex &z)
{
    const double epsilon = std::numeric_limits<double>::epsilon();
    if (z.im > -epsilon && z.im < epsilon)
    {
        os << z.real;
    }
    else if (z.real > -epsilon && z.real < epsilon)
    {
        os << z.im << "i";
    }
    else if (z.im < -epsilon)
    {
        os << z.real << " - " << -z.im << "i";
    }
    else
    {
        os << z.real << " + " << z.im << "i";
    }
    return os;
}