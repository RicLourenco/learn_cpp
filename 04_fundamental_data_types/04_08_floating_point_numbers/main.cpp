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



/* Outputting floating point values

When outputting floating point numbers, std::cout has a default precision of 6 --
that is, it assumes all floating point variables are only significant to 6 digits
(the minimum precision of a float), and hence it will truncate anything after that

The following program shows std::cout truncating to 6 digits: */

void ex3()
{
    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << '\n';
}

/* This program outputs:
9.87654
987.654
987654
9.87654e+006
9.87654e-005

9.87654e+006 is the same as 9.87654e6, just with some padding 0’s (depends on
compiler used)

We can override the default precision that std::cout shows by using an output
manipulator function named std::setprecision(). Output manipulators alter how data
is output, and are defined in the iomanip header */

#include <iomanip>

void ex4()
{
    std::cout << std::setprecision(17); 
    std::cout << 3.33333333333333333333333333333333333333f <<'\n'; 
    std::cout << 3.33333333333333333333333333333333333333 << '\n';
}

/* Outputs:
3.3333332538604736
3.3333333333333335

Because we set the precision to 17 digits using std::setprecision(), each of the
above numbers is printed with 17 digits. But, as you can see, the numbers certainly
aren’t precise to 17 digits! And because floats are less precise than doubles, the
float has more error.

Tip
Output manipulators (and input manipulators) are sticky -- meaning if you set them,
they will remain set.
The one exception is std::setw. Some IO operations reset std::setw, so std::setw
should be used every time it is needed.

Precision issues don’t just impact fractional numbers, they impact any number with
too many significant digits. Let’s consider a big number: */

void ex5()
{
    float f { 123456789.0f };
    std::cout << std::setprecision(9);
    std::cout << f << '\n';
}

/* Output:

123456792

123456792 is greater than 123456789. The value 123456789.0 has 10 significant
digits, but float values typically have 7 digits of precision (and the result of
123456792 is precise only to 7 significant digits). We lost some precision! When
precision is lost because a number can’t be stored precisely, this is called a
rounding error.
Consequently, one has to be careful when using floating point numbers that require
more precision than the variables can hold.

Best practice
Favor double over float unless space is at a premium, as the lack of precision in a
float will often lead to inaccuracies. */

int main()
{
    ex1();
    ex2();
    ex3();
    ex4();
    ex5();

    return 0;
}