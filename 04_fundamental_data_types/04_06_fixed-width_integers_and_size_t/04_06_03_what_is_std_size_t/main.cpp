#include <iostream>

int ex1()
{
    std::cout << sizeof(int) << '\n';

    return 0;
}

/* We can infer that operator sizeof returns an integer value -- but what integral
type is that return value? An int? A short? The answer is that sizeof returns a
value of type std::size_t. std::size_t is an alias for an implementation-defined
unsigned integral type. In other words, the compiler decides if std::size_t is an
unsigned int, an unsigned long, an unsigned long long, etc…

std::size_t is defined in a number of different headers. If you need to use
std::size_t, <cstddef> is the best header to include, as it contains the least
number of other defined identifiers. */

#include <cstddef>  // for std::size_t

int ex2()
{
    int x { 5 };
    std::size_t s { sizeof(x) }; // sizeof returns a value of type std::size_t, so that should be the type of s
    std::cout << s << '\n';

    return 0;
}

/* Best practice
If you use std::size_t explicitly in your code, #include one of the headers that
defines std::size_t (we recommend <cstddef>).

Using sizeof does not require a header (even though it returns a value whose type
is std::size_t).

Much like an integer can vary in size depending on the system, std::size_t also
varies in size. std::size_t is guaranteed to be unsigned and at least 16 bits, but
on most systems will be equivalent to the address-width of the application. That
is, for 32-bit applications, std::size_t will typically be a 32-bit unsigned
integer, and for a 64-bit application, std::size_t will typically be a 64-bit
unsigned integer. */