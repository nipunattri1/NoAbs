#include "processor.h"
#include <iostream>
#include <bitset>
std::string dInstConv(std::string &instruction);
std::string AInstConv(std::string &instruction);

std::string conv(std::string &instruction)
{
    // divide by = ;
    if (instruction[0] == 64)
        return AInstConv(instruction);
    else
        return dInstConv(instruction);
    return instruction;
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
std::string AInstConv(std::string &instruction)
{
    int a = std::stoi(instruction.substr(1));

    return "0" + (std::bitset<15>(a)).to_string();
}