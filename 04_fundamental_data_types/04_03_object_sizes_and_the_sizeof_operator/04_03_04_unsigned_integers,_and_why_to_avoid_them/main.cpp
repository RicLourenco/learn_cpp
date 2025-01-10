/* Unsigned integer overflow

If an unsigned value is out of range, it is divided by one greater than the largest
number of the type, and only the remainder kept.

The number 280 is too big to fit in our 1-byte range of 0 to 255. 1 greater than
the largest number of the type is 256. Therefore, we divide 280 by 256, getting 1
remainder 24. The remainder of 24 is what is stored.

Here’s another way to think about the same thing. Any number bigger than the
largest number representable by the type simply “wraps around” (sometimes called
“modulo wrapping”). 255 is in range of a 1-byte integer, so 255 is fine. 256,
however, is outside the range, so it wraps around to the value 0. 257 wraps around
to the value 1. 280 wraps around to the value 24. */

#include <iostream>

void ex1()
{
    unsigned short x{ 65535 }; // largest 16-bit unsigned value possible
    std::cout << "x was: " << x << '\n';

    x = 65536; // 65536 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n';

    x = 65537; // 65537 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n' << '\n';

    /* Result:
    x was: 65535
    x is now: 0
    x is now: 1 */
}

void ex2()
{
    /* It’s possible to wrap around the other direction as well. 0 is
    representable in a 2-byte unsigned integer, so that’s fine. -1 is not
    representable, so it wraps around to the top of the range, producing the value
    65535. -2 wraps around to 65534. And so forth. */

    unsigned short x = 0; 
    std::cout << "x was: " << x << '\n';

    x = -1; 
    std::cout << "x is now: " << x << '\n';

    x = -2; 
    std::cout << "x is now: " << x << '\n';
}

void ex3()
{
    /* unexpected behavior can result when you mix signed and unsigned integers.
    In C++, if a mathematical operation (e.g. arithmetic or comparison) has one
    signed integer and one unsigned integer, the signed integer will usually be
    converted to an unsigned integer. And the result will thus be unsigned. For
    example: */

    unsigned int u{ 2 };
	signed int s{ 3 };

	std::cout << u - s << '\n';

    /* Result:
    4294967295
    
    In this case, if u was signed, the correct result would be produced. But
    because u is unsigned (which is easy to miss), s gets converted to unsigned,
    and the result (-1) is treated as an unsigned value. Since -1 can’t be stored
    in an unsigned value, so we get overflow and an unexpected answer. */
}

void ex4()
{
    signed int s { -1 };
    unsigned int u { 1 };

    if (s < u) 
        std::cout << "-1 is less than 1\n";
    else
        std::cout << "1 is less than -1\n";

    /* This program is well formed, compiles, and is logically consistent to the
    eye. But it prints the wrong answer. And while your compiler should warn you
    about a signed/unsigned mismatch in this case, your compiler will also generate
    identical warnings for other cases that do not suffer from this problem(e.g.
    when both numbers are positive), making it hard to detect when there is an
    actual problem. */
}

// assume int is 4 bytes
void doSomething(unsigned int x)
{
    // Run some code x times
    std::cout << "x is " << x << '\n';
}

void ex5()
{
    doSomething(-1);
    /* The signed argument of -1 gets implicitly converted to an unsigned
    parameter. -1 isn’t in the range of an unsigned number, so it wraps around to
    4294967295 */
}

int main()
{
    ex1();
    ex2();
    ex3();
    ex4();
    ex5();

    /* Best practice:
    Favor signed numbers over unsigned numbers for holding quantities (even
    quantities that should be non-negative) and mathematical operations. Avoid
    mixing signed and unsigned numbers.
    
    
    
    So when should you use unsigned numbers?

    There are still a few cases in C++ where it’s okay / necessary to use unsigned
    numbers.

    First, unsigned numbers are preferred when dealing with bit manipulation
    (covered in chapter O -- that’s a capital ‘o’, not a ‘0’). They are also useful
    when well-defined wrap-around behavior is required (useful in some algorithms
    like encryption and random number generation).
    
    Second, use of unsigned numbers is still unavoidable in some cases, mainly
    those having to do with array indexing.
    
    Also note that if you’re developing for an embedded system (e.g. an Arduino) or
    some other processor/memory limited context, use of unsigned numbers is more
    common and accepted (and in some cases, unavoidable) for performance reasons.
    */

    return 0;
}