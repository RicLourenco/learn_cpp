/* To help address the above downsides, C++ also defines two alternative sets of
integers that are guaranteed to exist.

std::int_fast8/16/32/64_t and std::uint_fast8/16/32/64_t will give you the fastest
integer type that’s at least X-bits. By fastest, we mean the integral type that can
be processed most quickly by the CPU.

std::int_least8/16/32/64_t and std::uint_least8/16/32/64_t will give you the
smallest integer type that’s at least 32-bits.

Here’s an example from the author’s Visual Studio (32-bit console application): */

#include <cstdint> // for fast and least types
#include <iostream>

int ex1()
{
	std::cout << "least 8:  " << sizeof(std::int_least8_t)  * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  "  << sizeof(std::int_fast8_t)   * 8 << " bits\n";
	std::cout << "fast 16: "  << sizeof(std::int_fast16_t)  * 8 << " bits\n";
	std::cout << "fast 32: "  << sizeof(std::int_fast32_t)  * 8 << " bits\n";

	return 0;
}

/* This produced the result:

least 8:  8 bits
least 16: 16 bits
least 32: 32 bits

fast 8:  8 bits
fast 16: 32 bits
fast 32: 32 bits

You can see that std::int_least16_t is 16-bits, whereas std::int_fast16_t is
actually 32-bits. This is because on the author’s machine, 32-bit integers are
faster to process than 16-bit integers.

As another example, let’s assume we’re on an architecture that has only 16-bit and
64-bit integral types. std::int32_t would not exist, whereas std::least_int32_t
(and std::fast_int32_t) would be 64 bits.

Most seriously, because the size of the fast/least integers is
implementation-defined, your program may exhibit different behaviors on
architectures where they resolve to different sizes. For example: */

int ex2()
{
    std::uint_fast16_t sometype { 0 };
    sometype = sometype - 1; // intentionally overflow to invoke wraparound behavior

    std::cout << sometype << '\n';

    return 0;
}

/* This code will produce different results depending on whether std::uint_fast16_t
is 16, 32, or 64 bits! This is exactly what we were trying to avoid by using
fixed-width integers in the first place!

Best practice
Avoid the fast and least integral types because they may exhibit different
behaviors on architectures where they resolve to different sizes.


Best practice
- Prefer int when the size of the integer doesn’t matter (e.g. the number will always
fit within the range of a 2-byte signed integer). For example, if you’re asking the
user to enter their age, or counting from 1 to 10, it doesn’t matter whether int is
16-bits or 32-bits (the numbers will fit either way). This will cover the vast
majority of the cases you’re likely to run across.
- Prefer std::int#_t when storing a quantity that needs a guaranteed range.
- Prefer std::uint#_t when doing bit manipulation or well-defined wrap-around
behavior is required (e.g. for cryptography or random number generation).

Avoid the following when possible:
- short and long integers (prefer a fixed-width integer type instead).
- The fast and least integral types (prefer a fixed-width integer type instead).
- Unsigned types for holding quantities (prefer a signed integer type instead).
- The 8-bit fixed-width integer types (prefer a 16-bit fixed-width integer type
instead).
- Any compiler-specific fixed-width integers (for example, Visual Studio defines
__int8, __int16, etc…) */