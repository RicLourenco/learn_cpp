/* C++ contains an output stream named std::clog that is intended to be used for
writing logging information. However, by default, std::clog writes to the standard
error stream (the same as std::cerr). And while you can redirect it to file
instead, this is one area where you’re generally better off using one of the many
existing third-party logging tools available. Which one you use is up to you

For illustrative purposes, we’ll show what outputting to a logger looks like using
the plog logger. Plog is implemented as a set of header files, so it’s easy to
include anywhere you need it, and it’s lightweight and easy to use. */

#include <plog/Log.h> // Step 1: include the logger headers
#include <plog/Initializers/RollingFileInitializer.h>
#include <iostream>

int getUserInput()
{
	PLOGD << "getUserInput() called"; // PLOGD is defined by the plog library

	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

int main()
{
	plog::init(plog::debug, "Logfile.txt"); // Step 2: initialize the logger

	PLOGD << "main() called"; // Step 3: Output to the log as if you were writing to the console

	int x{ getUserInput() };
	std::cout << "You entered: " << x << '\n';

	return 0;
}

/* Note that conditional compilation directives are also not required using this
method, as most loggers have a method to reduce/eliminate writing output to the
log. This makes the code a lot easier to read, as the conditional compilation lines
add a lot of clutter. With plog, logging can be temporarily disabled by changing
the init statement to the following: */

plog::init(plog::none , "Logfile.txt"); // plog::none eliminates writing of most messages, essentially turning logging off