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


/* Rounding errors make floating point comparisons tricky

Floating point numbers are tricky to work with due to non-obvious differences
between binary (how data is stored) and decimal (how we think) numbers. Consider
the fraction 1/10. In decimal, this is easily represented as 0.1, and we are used
to thinking of 0.1 as an easily representable number with 1 significant digit.
However, in binary, decimal value 0.1 is represented by the infinite sequence:
0.00011001100110011… Because of this, when we assign 0.1 to a floating point
number, we’ll run into precision problems. */

void ex6()
{
    double d{0.1};
    std::cout << d << '\n'; 
    std::cout << std::setprecision(17);
    std::cout << d << '\n';
}

/* This outputs:
0.1
0.10000000000000001

On the top line, std::cout prints 0.1, as we expect.
On the bottom line, where we have std::cout show us 17 digits of precision, we see
that d is actually not quite 0.1! This is because the double had to truncate the
approximation due to its limited memory. The result is a number that is precise to
16 significant digits (which type double guarantees), but the number is not exactly
0.1. Rounding errors may make a number either slightly smaller or slightly larger,
depending on where the truncation happens.

Rounding errors can have unexpected consequences: */

void ex7()
{
    std::cout << std::setprecision(17);

    double d1{ 1.0 };
    std::cout << d1 << '\n';

    double d2{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 }; 
    std::cout << d2 << '\n';
}

/* 1
0.99999999999999989

If we were to compare d1 and d2 in a program, the program would probably not
perform as expected. Because floating point numbers tend to be inexact, comparing
floating point numbers is generally problematic
One last note on rounding errors: mathematical operations (such as addition and
multiplication) tend to make rounding errors grow. So even though 0.1 has a
rounding error in the 17th significant digit, when we add 0.1 ten times, the
rounding error has crept into the 16th significant digit. Continued operations
would cause this error to become increasingly significant.

Key insight
Rounding errors occur when a number can’t be stored precisely. This can happen even
with simple numbers, like 0.1. Therefore, rounding errors can, and do, happen all
the time. Rounding errors aren’t the exception -- they’re the norm. Never assume
your floating point numbers are exact.
A corollary of this rule is: be wary of using floating point numbers for financial
or currency data. */


/* NaN and Inf

EEE 754 compatible formats additionally support some special values:
- Inf, which represents infinity. Inf is signed, and can be positive (+Inf) or
negative (-Inf).
- NaN, which stands for “Not a Number”. There are several different kinds of NaN
(which we won’t discuss here).
- Signed zero, meaning there are separate representations for “positive zero”
(+0.0) and “negative zero” (-0.0).

Formats that are not compatible with IEEE 754 may not support some (or any) of
these values. In such cases, code that uses or generates these special values will
produce implementation-defined behavior. */

void ex8()
{
    double zero { 0.0 };

    double posinf { 5.0 / zero }; 
    std::cout << posinf << '\n';

    double neginf { -5.0 / zero }; 
    std::cout << neginf << '\n';

    double z1 { 0.0 / posinf }; 
    std::cout << z1 << '\n';

    double z2 { -0.0 / posinf }; 
    std::cout << z2 << '\n';

    double nan { zero / zero }; 
    std::cout << nan << '\n';
}

/* And the results using Clang:
inf
-inf
0
-0
nan

Note that the results of printing Inf and NaN are platform specific, so your
results may vary (e.g. Visual Studio prints the last result as -nan(ind)).

Best practice
Avoid division by 0.0, even if your compiler supports it. */


/* Conclusion

To summarize, the two things you should remember about floating point numbers:
- Floating point numbers are useful for storing very large or very small numbers,
including those with fractional components.
- Floating point numbers often have small rounding errors, even when the number has
fewer significant digits than the precision. Many times these go unnoticed because
they are so small, and because the numbers are truncated for output. However,
comparisons of floating point numbers may not give the expected results. Performing
mathematical operations on these values will cause the rounding errors to grow
larger. */

int main()
{
    ex1();
    ex2();
    ex3();
    ex4();
    ex5();
    ex6();
    ex7();
    ex8();

    return 0;
}