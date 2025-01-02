/* Question #2

Modify the program you wrote in exercise #1 so that readNumber() and writeAnswer()
live in a separate file called “io.cpp”. Use a forward declaration to access them
from main().

If you’re having problems, make sure “io.cpp” is properly added to your project so
it gets compiled. */

#include "./io.h"

int main()
{
    int x = readNumber();
    int y = readNumber();

    int sum = x + y;
    writeAnswer(sum);

    return 0;
}