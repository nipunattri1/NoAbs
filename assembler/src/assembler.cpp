// ! Learn error management also...

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <bitset>
#include "preprocessor.h"
#include "processor.h"
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
    while (std::getline(inf, instruction))
    {
        // std::cout << instruction << std::endl;
        std::string a{};
        a = preprocessor(instruction);
        a = conv(a);
        
        std::cout << a;
        if (a != "") std::cout<< std::endl;
    }

    return 0;
}





