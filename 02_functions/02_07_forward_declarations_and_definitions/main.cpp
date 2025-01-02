#include <iostream>

// int main()
// {
//     std::cout << "The sum of 4 and 3 is: " << add(4, 3) << '\n';

//     return 0;
// }

// int add(int x, int y)
// {
//     return x + y;
// }

/* The reason this program doesn’t compile is because the compiler compiles the
contents of code files sequentially. */

/* Best practice:
When addressing compilation errors or warnings in your programs, resolve the first
issue listed and then compile again. */

/* One way to address the issue is to reorder the function definitions so add is
defined before main...

We can also fix this by using a forward declaration.

A forward declaration allows us to tell the compiler about the existence of an
identifier before actually defining the identifier.

In the case of functions, this allows us to tell the compiler about the existence
of a function before we define the function’s body. This way, when the compiler
encounters a call to the function, it’ll understand that we’re making a function
call, and can check to ensure we’re calling the function correctly, even if it
doesn’t yet know how or where the function is defined.

To write a forward declaration for a function, we use a function declaration
statement (also called a function prototype). The function declaration consists of
the function’s return type, name, and parameter types, terminated with a semicolon.
The names of the parameters can be optionally included. The function body is not
included in the declaration. */

// int add(int x, int y);
/* function declaration includes return type, name, parameters, and semicolon.  No
function body! */

#include <iostream>

int add(int x, int y);
// forward declaration of add() (using a functiondeclaration)

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    // this works because we forward declared add() above
    return 0;
}

int add(int x, int y)
// even though the body of add() isn't defined until here
{
    return x + y;
}

/* It is worth noting that function declarations do not need to specify the names
of the parameters (as they are not considered to be part of the function
declaration). In the above code, you can also forward declare your function like
this: */
// int add(int, int); // valid function declaration

/* However, we prefer to name our parameters (using the same names as the actual
function). */
