#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::cout << "Insert string: ";
    std::string name;
    std::getline(std::cin, name);

    std::replace(name.begin(), name.end(), ' ', '_');

    for(int i = 0; i < name.length(); i++){
        name[i] = std::tolower(name[i]);
    };

    std::cout << name << std::endl;

    return 0;
}