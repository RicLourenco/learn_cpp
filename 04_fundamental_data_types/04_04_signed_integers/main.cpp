/* Overflow

What happens if we try to assign the value 140 to an 8-bit signed integer? This
number is outside the range that an 8-bit signed integer can hold. The number 140
requires 9 bits to represent (8 magnitude bits and 1 sign bit), but we only have 8
bits (7 magnitude bits and 1 sign bit) available in an 8-bit signed integer.

The C++20 standard makes this blanket statement: “If during the evaluation of an
expression, the result is not mathematically defined or not in the range of
representable values for its type, the behavior is undefined”. Colloquially, this
is called overflow.

Therefore, assigning value 140 to an 8-bit signed integer will result in undefined
behavior.

If an arithmetic operation (such as addition or multiplication) attempts to create
a value outside the range that can be represented, this is called integer overflow
(or arithmetic overflow). For signed integers, integer overflow will result in
undefined behavior. */

#include <iostream>

int main()
{
    // assume 4 byte integers
    int x { 2'147'483'647 }; // the maximum value of a 4-byte signed integer
    std::cout << x << '\n';

    x = x + 1; // integer overflow, undefined behavior
    std::cout << x << '\n';

    /* On the author’s machine, the above printed:
    2147483647
    -2147483648
    However, because the second output is the result of undefined behavior, the
    value output may vary on your machine.
    
     
    When doing division with two integers (called integer division), C++ always
    produces an integer result. Since integers can’t hold fractional values, any
    fractional portion is simply dropped (not rounded!).

    8 / 5 produces the value 1.6. The fractional part (0.6) is dropped, and the
    result of 1 remains. Alternatively, we can say 8 / 5 equals 1 remainder 3. The
    remainder is dropped, leaving 1.

    Similarly, -8 / 5 results in the value -1. */

    return 0;
}