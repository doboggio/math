#include "complex.hpp"
#include <cassert>

void test_basic_arithmetic()
{
    Complex a(1, 2);
    Complex b(3, -4);
    Complex result;

    result = a + b;
    assert(result.Real() == 4 && result.Imaginary() == -2);

    result = a - b;
    assert(result.Real() == -2 && result.Imaginary() == 6);

    result = a * b;
    assert(result.Real() == 11 && result.Imaginary() == 2);

    result = a / b;
    assert(std::abs(result.Real() - (-0.2)) < 1e-12);
    assert(std::abs(result.Imaginary() - (0.4)) < 1e-12);
}

void test_scalar_operations()
{
    Complex c(2, 3);

    Complex result = c + 5.0;
    assert(result.Real() == 7 && result.Imaginary() == 3);

    result = c - 1.5;
    assert(result.Real() == 0.5 && result.Imaginary() == 3);

    result = c * 2.0;
    assert(result.Real() == 4 && result.Imaginary() == 6);

    result = c / 2.0;
    assert(result.Real() == 1 && result.Imaginary() == 1.5);

    result = 2.0 * c;
    assert(result.Real() == 4 && result.Imaginary() == 6);

    result = 2.0 + c;
    assert(result.Real() == 4 && result.Imaginary() == 3);

    result = 2.0 - c;
    assert(result.Real() == 0 && result.Imaginary() == -3);
}

void test_compound_assignments()
{
    Complex d(1, 1);
    Complex e(2, -3);

    d += e;
    assert(d.Real() == 3 && d.Imaginary() == -2);

    d *= e;
    assert(d.Real() == 0 && d.Imaginary() == -13);

    d -= e;
    assert(d.Real() == -2 && d.Imaginary() == -10);

    d /= e;
    assert(std::abs(d.Real() - 2.0) < 1e-12);
    assert(std::abs(d.Imaginary() + 2.0) < 1e-12);
}

void test_division_by_zero()
{
    try
    {
        Complex f(1, 1);
        Complex zero(0, 0);
        f / zero;
        assert(false && "Expected domain_error not thrown");
    }
    catch (const std::domain_error &e)
    {
        assert(std::string(e.what()) == "Divide by zero");
    }
}

void test_real_imag_only()
{
    Complex real_only(5, 0);
    Complex imag_only(0, 3);
    Complex result;

    assert(real_only.Real() == 5 && real_only.Imaginary() == 0);
    assert(imag_only.Real() == 0 && imag_only.Imaginary() == 3);

    result = real_only + imag_only;
    assert(result.Real() == 5 && result.Imaginary() == 3);
}

int main()
{
    std::cout << "Running tests...\n";

    test_basic_arithmetic();
    test_scalar_operations();
    test_compound_assignments();
    test_division_by_zero();
    test_real_imag_only();

    std::cout << "All tests passed.\n";
    return 0;
}
