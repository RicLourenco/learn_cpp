/* If you assume an int is 32-bits because that’s most likely, then your program
will probably misbehave on architectures where int is actually 16-bits (since you
will probably be storing values that require 32-bits of storage in a variable with
only 16-bits of storage, which will cause overflow or undefined behavior). */

#include <iostream>

void ex1()
{
    int x { 32767 };        // x may be 16-bits or 32-bits
    x = x + 1;              // 32768 overflows if int is 16-bits, okay if int is 32-bits
    std::cout << x << '\n'; // what will this print?
}

/* On a machine where int is 32-bits, the value 32768 fits within the range of an
int, and therefore can be stored in x without issue. On such a machine, this
program will print 32768. However, on a machine where int is 16-bits, the value
32768 does not fit within the range of a 16-bit integer (which has range -32,768 to
32,767). On such a machine, x = x + 1 will cause overflow, and the value -32768
will be stored in x and then printed.

Instead, if you assume an int is only 16-bits to ensure your program will behave on
all architectures, then the range of values you can safely store in an int is
significantly limited. And on systems where int is actually 32-bits, you’re not
making use of half of the memory allocated per int.



Fixed-width integers

To address the above issues, C++11 provides an alternate set of integer types that
are guaranteed to be the same size on any architecture. Because the size of these
integers is fixed, they are called fixed-width integers. In the<cstdint> header

std::uint8/16/32/62_t: 1/2/4/8 byte unsigned integers
std::int8/16/32/62_t: 1/2/4/8 byte signed integers */

#include <cstdint> // for fixed-width integers

void ex2()
{
    std::int32_t x { 32767 }; // x is always a 32-bit integer
    x = x + 1;                // so 32768 will always fit
    std::cout << x << '\n';
}

/* Warning: std::int8_t and std::uint8_t typically behave like chars

Due to an oversight in the C++ specification, modern compilers typically treat
std::int8_t and std::uint8_t (and the corresponding fast and least fixed-width
types, which we’ll introduce in a moment) the same as signed char and unsigned char
respectively. Thus on most modern systems, the 8-bit fixed-width integral types
will behave like char types. */

void ex3()
{
    std::int8_t x { 65 };   // initialize 8-bit integral type with value 65
    std::cout << x << '\n'; // You're probably expecting this to print 65
}


int main()
{
    ex1();
    ex2();
    ex3();

    return 0;
}
