// ! Learn error management also...

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <bitset>
#include "preprocessor.h"
// define error codes;
// eg code 1 invalid address

std::string preprocessor(std::string instruction);

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
        
        std::cout << a;
        if (a != "") std::cout<< std::endl;
    }

    return 0;
}





std::string dInstConv(std::string &instruction)
{
    std::bitset<3> dest = 0b000;
    std::bitset<3> jump = 0b000;
    std::bitset<6> comp = 0b101010;
    int a = 0;

    int equalPos = instruction.find('=');

    // dest c1 c2 c3; c1-A c2-D c3-M
    if (equalPos != std::string::npos)
    {
        std::string destStr = instruction.substr(0, equalPos);
        if (destStr.find('A') != std::string::npos)
            dest |= 0b100;
        if (destStr.find('D') != std::string::npos)
            dest |= 0b010;
        if (destStr.find('M') != std::string::npos)
            dest |= 0b001;
    }

    // 111accccdddjjj basic instrction set
    return "111" + std::to_string(a) + comp.to_string() + dest.to_string() + jump.to_string();
}