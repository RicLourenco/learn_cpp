/* Note that the goal of header guards is to prevent a code file from receiving
more than one copy of a guarded header. By design, header guards do not prevent a
given header file from being included (once) into separate code files. This can
also cause unexpected problems. Consider: */

#include "square.h" // square.h is also included once here
#include <iostream>

int main()
{
    std::cout << "a square has " << getSquareSides() << " sides\n";
    std::cout << "a square of length 5 has perimeter length " << getSquarePerimeter(5) << '\n';

    return 0;
}

/* Note that square.h is included from both main.cpp and square.cpp. This means
the contents of square.h will be included once into square.cpp and once into
main.cpp.

Let’s examine why this happens in more detail. When square.h is included from
square.cpp, SQUARE_H is defined until the end of square.cpp. This define prevents
square.h from being included into square.cpp a second time (which is the point of
header guards). However, once square.cpp is finished, SQUARE_H is no longer
considered defined. This means that when the preprocessor runs on main.cpp,
SQUARE_H is not initially defined in main.cpp.

The end result is that both square.cpp and main.cpp get a copy of the definition of
getSquareSides. This program will compile, but the linker will complain about your
program having multiple definitions for identifier getSquareSides! */

