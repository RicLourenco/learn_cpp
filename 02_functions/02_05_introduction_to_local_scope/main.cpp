#include <iostream>

int add(int x, int y) {
    int z { x + y };
    return z;
} // z, y and x are destroyed here
/* The natural follow-up question is, “so when is an instantiated variable
destroyed?”. Local variables are destroyed in the opposite order of creation at the
end of the set of curly braces in which it is defined (or for a function parameter,
at the end of the function). */

/* Here’s a slightly more complex program demonstrating the lifetime of a variable
named x: */
void doSomething()
{
    std::cout << "Hello\n";
}

int main()
{
    int x { 0 }; // x's lifetime begins here

    doSomething(); // x is still alive during this function call

    return 0;
} // x's lifetime ends here