/* Quiz time

Be sure to use your editor’s auto-formatting feature to keep your formatting
consistent and make your code easier to read.

Question #1

Write a single-file program (named main.cpp) that reads two separate integers from
the user, adds them together, and then outputs the answer. The program should use
three functions:

A function named “readNumber” should be used to get (and return) a single integer
from the user.
A function named “writeAnswer” should be used to output the answer. This function
should take a single parameter and have no return value.
A main() function should be used to glue the above functions together. */

#include <iostream>

int readNumber()
{
    std::cout << "Enter a number: ";
    int x;
    std::cin >> x;
    return x;
}

void writeAnswer(int x)
{
    std::cout << "The sum of the two numbers is: " << x << std::endl;
}

int main()
{
    int x = readNumber();
    int y = readNumber();

    int sum = x + y;
    writeAnswer(sum);

    return 0;
}