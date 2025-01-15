/* C++ has three fundamental floating point data types: a single-precision float, a
double-precision double, and an extended-precision long double. As with integers,
C++ does not define the actual size of these types.

Tip
This tutorial series assumes your compiler is using an IEEE 754 compatible format
for float and double.

You can see if your floating point types are IEEE 754 compatible with the following
code: */

#include <iostream>
#include <limits>

void ex1()
{
    std::cout << std::boolalpha; // print bool as true or false rather than 1 or 0
    std::cout << "float: " << std::numeric_limits<float>::is_iec559 << '\n';
    std::cout << "double: " << std::numeric_limits<double>::is_iec559 << '\n';
    std::cout << "long double: " << std::numeric_limits<long double>::is_iec559 << '\n';
}

/* When using floating point literals, always include at least one decimal place
(even if the decimal is 0). This helps the compiler understand that the number is a
floating point number and not an integer. */

void ex2()
{
    int a { 5 };      // 5 means integer
    double b { 5.0 }; // 5.0 is a floating point literal (no suffix means double type by default)
    float c { 5.0f }; // 5.0 is a floating point literal, f suffix means float type

    int d { 0 };      // 0 is an integer
    double e { 0.0 }; // 0.0 is a double
}

/* Note that by default, floating point literals default to type double. An f
suffix is used to denote a literal of type float.

Best practice
Always make sure the type of your literals match the type of the variables they’re
being assigned to or used to initialize. Otherwise an unnecessary conversion will
result, possibly with a loss of precision. */



/* Floating point precision

The precision of a floating point type defines how many significant digits it can
represent without information loss.

he number of digits of precision a floating point type has depends on both the size
(floats have less precision than doubles) and the particular value being stored
(some values can be represented more precisely than others).

For example, a float has 6 to 9 digits of precision. This means that a float can
exactly represent any number with up to 6 significant digits. A number with 7 to 9
significant digits may or may not be represented exactly depending on the specific
value. And a number with more than 9 digits of precision will definitely not be
represented exactly.

Double values have between 15 and 18 digits of precision, with most double values
having at least 16 significant digits. Long double has a minimum precision of 15,
18, or 33 significant digits depending on how many bytes it occupies.

Key insight
A floating point type can only precisely represent a certain number of significant
digits. Using a value with more significant digits than the minimum may result in
the value being stored inexactly. */

int main()
{
    ex1();
    ex2();

    return 0;
}