/* Macro defines

The #define directive can be used to create a macro. In C++, a macro is a rule that
defines how input text is converted into replacement output text.
There are two basic types of macros: object-like macros, and function-like macros.
Function-like macros act like functions, and serve a similar purpose. Their use is
generally considered unsafe, and almost anything they can do can be done by a
normal function.

Object-like macros can be defined in one of two ways:
#define IDENTIFIER
#define IDENTIFIER substitution_text
The top definition has no substitution text, whereas the bottom one does. Because
these are preprocessor directives (not statements), note that neither form ends
with a semicolon.
The identifier for a macro uses the same naming rules as normal identifiers: they
can use letters, numbers, and underscores, cannot start with a number, and should
not start with an underscore. By convention, macro names are typically all
upper-case, separated by underscores. */


/* Object-like macros with substitution text

When the preprocessor encounters this directive, an association is made between the 
macro identifier and substitution_text. All further occurrences of the macro
identifier (outside of use in other preprocessor commands) are replaced by the
substitution_text.
Consider the following program: */

#include <iostream>

#define MY_NAME "Alex"

int main()
{
    std::cout << "My name is: " << MY_NAME << '\n';

    return 0;
}

/* The preprocessor converts the above into the following:
/ The contents of iostream are inserted here */

int main()
{
    std::cout << "My name is: " << "Alex" << '\n';

    return 0;
}

/* Object-like macros without substitution text

Object-like macros can also be defined without substitution text.

For example:

#define USE_YEN
Macros of this form work like you might expect: most further occurrences of the
identifier is removed and replaced by nothing!
This might seem pretty useless, and it is useless for doing text substitution.
However, that’s not what this form of the directive is generally used for. We’ll
discuss the uses of this form in just a moment.
Unlike object-like macros with substitution text, macros of this form are generally
considered acceptable to use.

The conditional compilation preprocessor directives allow you to specify under what
conditions something will or won’t compile. There are quite a few different
conditional compilation directives, but we’ll only cover a few that are used the
most often: #ifdef, #ifndef, and #endif.
The #ifdef preprocessor directive allows the preprocessor to check whether an
identifier has been previously defined via #define. If so, the code between the
#ifdef and matching #endif is compiled. If not, the code is ignored.
Consider the following program: */

#include <iostream>

#define PRINT_JOE

int main()
{
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
#endif

#ifdef PRINT_BOB
    std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined
#endif

    return 0;
}

/* Because PRINT_JOE has been #defined, the line std::cout << "Joe\n" will be
compiled. Because PRINT_BOB has not been #defined, the line std::cout << "Bob\n"
will be ignored.
#ifndef is the opposite of #ifdef, in that it allows you to check whether an
identifier has NOT been #defined yet. */

#include <iostream>

int main()
{
#ifndef PRINT_BOB
    std::cout << "Bob\n";
#endif

    return 0;
}

/* This program prints “Bob”, because PRINT_BOB was never #defined.

In place of #ifdef PRINT_BOB and #ifndef PRINT_BOB, you’ll also see
#if defined(PRINT_BOB) and #if !defined(PRINT_BOB). These do the same, but use a
slightly more C++-style syntax. */

/* #if 0 

One more common use of conditional compilation involves using #if 0 to exclude a
block of code from being compiled (as if it were inside a comment block): */

#include <iostream>

int main()
{
    std::cout << "Joe\n";

#if 0 // Don't compile anything starting here
    std::cout << "Bob\n";
    std::cout << "Steve\n";
#endif // until this point

    return 0;
}

/* The above code only prints “Joe”, because “Bob” and “Steve” are excluded from
compilation by the #if 0 preprocessor directive.
This provides a convenient way to “comment out” code that contains multi-line
comments (which can’t be commented out using another multi-line comment due to
multi-line comments being non-nestable)

To temporarily re-enable code that has been wrapped in an #if 0, you can change the
#if 0 to #if 1: */