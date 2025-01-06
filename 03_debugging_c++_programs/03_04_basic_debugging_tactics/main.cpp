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

#include <iostream>

#define ENABLE_DEBUG // comment out to disable debugging

int getUserInput()
{
#ifdef ENABLE_DEBUG
std::cerr << "getUserInput() called\n";
#endif
	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

int main()
{
#ifdef ENABLE_DEBUG
std::cerr << "main() called\n";
#endif
    int x{ getUserInput() };
    std::cout << "You entered: " << x << '\n';

    return 0;
}

/* Now we can enable debugging simply by commenting / uncommenting #define
ENABLE_DEBUG. This allows us to reuse previously added debug statements and then
just disable them when we’re done with them, rather than having to actually remove
them from the code. If this were a multi-file program, the #define ENABLE_DEBUG
would go in a header file that’s included into all code files so we can comment /
uncomment the #define in a single location and have it propagate to all code files.

This addresses the issue with having to remove debug statements and the risk in
doing so, but at the cost of even more code clutter. Another downside of this
approach is that if you make a typo (e.g. misspell “DEBUG”) or forget to include
the header into a code file, some or all of the debugging for that file may not be
enabled. So although this is better than the unconditionalized version, there’s
still room to improve. */