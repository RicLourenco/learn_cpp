#include "add.h"
/* Insert contents of add.h at this point.  Note use of double quotes here. */
#include <iostream>

int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}

/* When the preprocessor processes the #include "add.h" line, it copies the
contents of add.h into the current file at that point. Because our add.h contains a
forward declaration for function add(), that forward declaration will be copied
into main.cpp. The end result is a program that is functionally the same as the one
where we manually added the forward declaration at the top of main.cpp. */


/* Important:
For now, you should avoid putting function or variable definitions in header files.
Doing so will generally result in a violation of the one-definition rule (ODR) in
cases where the header file is included into more than one source file. */


/* - Source files should include their paired header -

In C++, it is a best practice for code files to #include their paired header
file (if one exists). In the example above, add.cpp includes add.h.

This allows the compiler to catch certain kinds of errors at compile time instead
of link time. For example:

something.h: */

// int something(int);
// return type of forward declaration is int

/* something.cpp: */

// #include "something.h"

// void something(int) // error: wrong return type
// {
// }

/* Because something.cpp #includes something.h, the compiler will notice that
function something() has a mismatched return type and give us a compile error. If
something.cpp did not #include something.h, we’d have to wait until the linker
discovered the discrepancy, which wastes time. */


/* - Do not #include .cpp files -

Although the preprocessor will happily do so, you should generally not #include
.cpp files. These should be added to your project and compiled.

There are number of reasons for this:
- Doing so can cause naming collisions between source files.
- In a large project it can be hard to avoid one definition rules (ODR) issues.
- Any change to such a .cpp file will cause both the .cpp file and any other .cpp
file that includes it to recompile, which can take a long time. Headers tend to
change less often than source files.
- It is non-conventional to do so. */


/* - Including header files from other directories -

Another common question involves how to include header files from other
directories.

One (bad) way to do this is to include a relative path to the header file you want
to include as part of the #include line.

A better method is to tell your compiler or IDE that you have a bunch of header
files in some other location, so that it will look there when it can’t find them in
the current directory. This can generally be done by setting an include path or
search directory in your IDE project settings. */


/* - Headers may include other headers -

It’s common that a header file will need a declaration or definition that lives in
a different header file. Because of this, header files will often #include other
header files.

When your code file #includes the first header file, you’ll also get any other
header files that the first header file includes (and any header files those
include, and so on). These additional header files are sometimes called transitive
includes, as they’re included implicitly rather than explicitly.

Best practice:
Each file should explicitly #include all of the header files it needs to compile.
Do not rely on headers included transitively from other headers.

Q: I didn’t include <someheader> and my program worked anyway! Why?
This is one of the most commonly asked questions on this site. The answer is: it’s
likely working, because you included some other header (e.g. <iostream>), which
itself included <someheader>. Although your program will compile, per the best
practice above, you should not rely on this. What compiles for you might not
compile on a friend’s machine. */


/* - The order of inclusion for header files -

If your header files are written properly and #include everything they need, the
order of inclusion shouldn’t matter.
Now consider the following scenario: let’s say header A needs declarations from
header B, but forgets to include it. In our code file, if we include header B
before header A, our code will still compile! This is because the compiler will
compile all the declarations from B before it compiles the code from A that depends
on those declarations.
However, if we include header A first, then the compiler will complain because the
code from A will be compiled before the compiler has seen the declarations from B.
This is actually preferable, because the error has been surfaced, and we can then
fix it.

Best practice:
To maximize the chance that missing includes will be flagged by compiler, order
your #includes as follows (skipping any that are not relevant):
- The paired header file for this code file (e.g. add.cpp should #include "add.h")
- Other headers from the same project (e.g. #include "mymath.h")
- 3rd party library headers (e.g. #include <boost/tuple/tuple.hpp>)
- Standard library headers (e.g. #include <iostream>)
The headers for each grouping should be sorted alphabetically (unless the
documentation for a 3rd party library instructs you to do otherwise). */


/* Prefer putting documentation on what something does or how to use it in the
header. It’s more likely to be seen there. Documentation describing how something
works should remain in the source files. */