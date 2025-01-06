#include <iostream>
#include <algorithm>
#include <cctype>
#include <locale>
#include <string>

// trim from start (in place)
inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

void toLower(std::string &name)
{
    for (int i = 0; i < name.length(); i++)
    {
        name[i] = std::tolower(name[i]);
    }
}

void normalize_name(std::string &name)
{
    ltrim(name);
    rtrim(name);
    toLower(name);

    std::replace(name.begin(), name.end(), ' ', '_');
}

int main()
{
    std::cout << "Insert string: ";
    std::string name;
    std::getline(std::cin, name);

    normalize_name(name);

    std::cout << name << std::endl;

    return 0;
}