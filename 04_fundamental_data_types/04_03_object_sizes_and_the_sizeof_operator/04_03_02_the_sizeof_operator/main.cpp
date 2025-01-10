/* In order to determine the size of data types on a particular machine, C++
provides an operator named sizeof. The sizeof operator is a unary operator that
takes either a type or a variable, and returns the size of an object of that type
(in bytes). You can compile and run the following program to find out how large
some of your data types are: */

#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <iostream>
#include <climits> // for CHAR_BIT

int main()
{
    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    std::cout << std::left; // left justify output

    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

    /* Trying to use sizeof on an incomplete type (such as void) will result in a
    compilation error
    
    You can also use the sizeof operator on a variable name: */

    int x{};
    std::cout << "x is " << sizeof(x) << " bytes" << std::endl;

    return 0;
}

/* As an aside…
You might assume that types that use less memory would be faster than types that
use more memory. This is not always true. CPUs are often optimized to process data
of a certain size (e.g. 32 bits), and types that match that size may be processed
quicker. On such a machine, a 32-bit int could be faster than a 16-bit short or an
8-bit char */