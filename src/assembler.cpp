#include "preprocessor.h"
#include "processor.h"
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <bitset>
#include <string>

// define error codes;
// eg code 1 invalid address

int main(int argc, char const *argv[])
{
    std::ifstream inf{argv[1]};
    if (!inf)
    {
        std::cout << "Error Reading the Input file " << argv[1] << std::endl;
        return 1;
    }
    std::string instruction{};
    while (std::getline(inf, instruction)){
        std::string a{};
        a = preprocessor(instruction, true);
    }
std::ifstream inf2{argv[1]};
    if (!inf2)
    {
        std::cout << "Error Reading the Input file " << argv[1] << std::endl;
        return 1;
    }
    while (std::getline(inf2, instruction))
    {
        // std::cout << instruction << std::endl;
        std::string a{};
        a = preprocessor(instruction, false);
        // std::transform(a.begin(), a.end(), a.begin(), ::toupper);
        if (a.compare(""))
        {
            a = conv(a);
            std::cout << a;
            std::cout << std::endl;
        }
    }

    return 0;
}
