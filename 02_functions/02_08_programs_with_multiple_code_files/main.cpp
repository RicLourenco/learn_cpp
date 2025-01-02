#include <iostream>

int add(int x, int y); // needed so main.cpp knows that add() is a function defined elsewhere

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}

/* when the compiler is compiling main.cpp, it will know what identifier add is and
be satisfied. The linker will connect the function call to add in main.cpp to the
definition of function add in add.cpp.
Using this method, we can give files access to functions that live in another
file.

Tip:
Because the compiler compiles each code file individually (and then forgets what it
has seen), each code file that uses std::cout or std::cin needs to
#include <iostream>.
In the above example, if add.cpp had used std::cout or std::cin, it would have
needed to #include <iostream>.

Key insight
When an identifier is used in an expression, the identifier must be connected to
its definition.
- If the compiler has seen neither a forward declaration nor a definition for the
identifier in the file being compiled, it will error at the point where the
identifier is used.
- Otherwise, if a definition exists in the same file, the compiler will connect the
use of the identifier to its definition.
- Otherwise, if a definition exists in a different file (and is visible to the
linker), the linker will connect the use of the identifier to its definition.
- Otherwise, the linker will issue an error indicating that it couldn’t find a
definition for the identifier. */