/* Header guards (also called an include guard)

Header guards are conditional compilation directives that take the following form: */


// #ifndef SOME_UNIQUE_NAME_HERE
// #define SOME_UNIQUE_NAME_HERE

/* your declarations (and certain types of definitions) here */

// #endif


/* When this header is #included, the preprocessor will check whether
SOME_UNIQUE_NAME_HERE has been previously defined in this translation unit. If this
is the first time we’re including the header, SOME_UNIQUE_NAME_HERE will not have
been defined. Consequently, it #defines SOME_UNIQUE_NAME_HERE and includes the
contents of the file. If the header is included again into the same file,
SOME_UNIQUE_NAME_HERE will already have been defined from the first time the
contents of the header were included, and the contents of the header will be
ignored (thanks to the #ifndef).

All of your header files should have header guards on them. SOME_UNIQUE_NAME_HERE
can be any name you want, but by convention is set to the full filename of the
header file, typed in all caps, using underscores for spaces or punctuation. */

// #include "square.h"
// #include "wave.h"

// int main()
// {
//     return 0;
// }

/* After the preprocessor resolves all of the #include directives, this program
looks like this: */

// Square.h included from main.cpp
#ifndef SQUARE_H // square.h included from main.cpp
#define SQUARE_H // SQUARE_H gets defined here

// and all this content gets included
int getSquareSides()
{
    return 4;
}

#endif // SQUARE_H

#ifndef WAVE_H // wave.h included from main.cpp
#define WAVE_H
#ifndef SQUARE_H // square.h included from wave.h, SQUARE_H is already defined from above
#define SQUARE_H // so none of this content gets included

int getSquareSides()
{
    return 4;
}

#endif // SQUARE_H
#endif // WAVE_H

int main()
{
    return 0;
}