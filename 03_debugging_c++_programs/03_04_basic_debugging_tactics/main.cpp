/* Debugging tactic #2: Validating your code flow

Tip:
When printing information for debugging purposes, use std::cerr instead of
std::cout. One reason for this is that std::cout may be buffered, which means a bit
of time may pass between when you ask std::cout to output text and when it actually
does. If you output using std::cout and then your program crashes immediately
afterward, std::cout may or may not have actually output yet. This can mislead you
about where the issue is. On the other hand, std::cerr is unbuffered, which means
anything you send to it will output immediately. This helps ensure all debug output
appears as soon as possible (at the cost of some performance, which we usually
don’t care about when debugging).

Using std::cerr also helps make clear that the information being output is for an
error case rather than a normal case.

We discuss when to use std::cout vs std::cerr further in
lesson 9.4 -- Detecting and handling errors.

Consider the following simple program that doesn’t work correctly: */

// #include <iostream>

// int getValue()
// {
// 	return 4;
// }

// int main()
// {
//     std::cout << getValue << '\n';

//     return 0;
// }

/* Let’s add some debugging statements to these functions: */

#include <iostream>

int getValue()
{
std::cerr << "getValue() called\n";
	return 4;
}

int main()
{
std::cerr << "main() called\n";
    std::cout << getValue << '\n';

    return 0;
}

/* Tip:

When adding temporary debug statements, it can be helpful to not indent them. This
makes them easier to find for removal later.

If you are using clang-format to format your code, it will try to auto-indent these
lines. You can suppress the automatic formatting like this:

// clang-format off
std::cerr << "main() called\n";
// clang-format on */