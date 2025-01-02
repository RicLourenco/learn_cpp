#include "square.h"

int getSquareSides() // actual definition for getSquareSides
{
    return 4;
}

int getSquarePerimeter(int sideLength)
{
    return sideLength * getSquareSides();
}

/* Can’t we just avoid definitions in header files?

We’ve generally told you not to include function definitions in your headers. So
you may be wondering why you should include header guards if they protect you from
something you shouldn’t do.

There are quite a few cases we’ll show you in the future where it’s necessary to
put non-function definitions in a header file. For example, C++ will let you create
your own types. These custom types are typically defined in header files, so the
type definitions can be propagated out to the code files that need to use them.
Without a header guard, a code file could end up with multiple (identical) copies
of a given type definition, which the compiler will flag as an error.

So even though it’s not strictly necessary to have header guards at this point in
the tutorial series, we’re establishing good habits now, so you don’t have to
unlearn bad habits later. */