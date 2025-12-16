#include "processor.h"
#include <iostream>
#include <bitset>
#include <unordered_map>
enum errors
{
    WRONG_COMP,
    WRONG_JUMP,
};
const std::unordered_map<std::string_view, std::bitset<6>> compMap = {
    {"0", std::bitset<6>(0b101010)},   // zx=1,nx=0,zy=1,ny=0,f=1,no=0
    {"1", std::bitset<6>(0b111111)},   // 1,1,1,1,1,1
    {"-1", std::bitset<6>(0b111010)},  // 1,1,1,0,1,0
    {"D", std::bitset<6>(0b001100)},   // 0,0,1,1,0,0
    {"A", std::bitset<6>(0b110000)},   // 1,1,0,0,0,0
    {"M", std::bitset<6>(0b110000)},   // 1,1,0,0,0,0
    {"!D", std::bitset<6>(0b001101)},  // 0,0,1,1,0,1
    {"!A", std::bitset<6>(0b110001)},  // 1,1,0,0,0,1
    {"!M", std::bitset<6>(0b110001)},  // 1,1,0,0,0,1
    {"-D", std::bitset<6>(0b001111)},  // 0,0,1,1,1,1
    {"-A", std::bitset<6>(0b110011)},  // 1,1,0,0,1,1
    {"-M", std::bitset<6>(0b110011)},  // 1,1,0,0,1,1
    {"D+1", std::bitset<6>(0b011111)}, // 0,1,1,1,1,1
    {"A+1", std::bitset<6>(0b110111)}, // 1,1,0,1,1,1
    {"M+1", std::bitset<6>(0b110111)}, // 1,1,0,1,1,1
    {"D-1", std::bitset<6>(0b001110)}, // 0,0,1,1,1,0
    {"A-1", std::bitset<6>(0b110010)}, // 1,1,0,0,1,0
    {"M-1", std::bitset<6>(0b110010)}, // 1,1,0,0,1,0
    {"D+A", std::bitset<6>(0b000010)}, // 0,0,0,0,1,0
    {"D+M", std::bitset<6>(0b000010)}, // 0,0,0,0,1,0
    {"D-A", std::bitset<6>(0b010011)}, // 0,1,0,0,1,1
    {"D-M", std::bitset<6>(0b010011)}, // 0,1,0,0,1,1
    {"A-D", std::bitset<6>(0b000111)}, // 0,0,0,1,1,1
    {"M-D", std::bitset<6>(0b000111)}, // 0,0,0,1,1,1
    {"D&A", std::bitset<6>(0b000000)}, // 0,0,0,0,0,0
    {"D&M", std::bitset<6>(0b000000)}, // 0,0,0,0,0,0
    {"D|A", std::bitset<6>(0b010101)}, // 0,1,0,1,0,1
    {"D|M", std::bitset<6>(0b010101)}  // 0,1,0,1,0,1
};
std::unordered_map<std::string_view, std::bitset<3>> jumpMap = {
    {"", std::bitset<3>(0b000)},      // null: no jump
    {"JGT", std::bitset<3>(0b001)},   // Jump if greater than 0: !zr & !ng
    {"JEQ", std::bitset<3>(0b010)},   // Jump if equal to 0: zr
    {"JGE", std::bitset<3>(0b011)},   // Jump if greater or equal: !ng
    {"JLT", std::bitset<3>(0b100)},   // Jump if less than 0: ng
    {"JNE", std::bitset<3>(0b101)},   // Jump if not equal: !zr
    {"JLE", std::bitset<3>(0b110)},   // Jump if less or equal: zr | ng
    {"JMP", std::bitset<3>(0b111)}    // Unconditional jump: always
};
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
    int semiPos = instruction.find(';');
    int equalPos = instruction.find('=');

    // dest c1 c2 c3; c1-A c2-D c3-M
    if (equalPos != std::string::npos)
    {
        std::string_view destStr = instruction.substr(0, equalPos);
        if (destStr.find('A') != std::string::npos)
            dest |= 0b100;
        if (destStr.find('D') != std::string::npos)
            dest |= 0b010;
        if (destStr.find('M') != std::string::npos)
            dest |= 0b001;
    }

    int compSize = (semiPos == std::string::npos ? instruction.length() : (semiPos)) - (equalPos == std::string::npos ? 0 : equalPos + 1);
    std::string_view compStr = (instruction.substr(equalPos == std::string::npos ? 0 : equalPos + 1, compSize));

    auto compKey = compMap.find(compStr);
    if (compKey == compMap.end())
        throw WRONG_COMP;
    
    comp = compKey->second;
    a = compStr.find('M') == std::string::npos ? 0 : 1;

    if (semiPos != std::string::npos && (instruction.length() -semiPos) == 4)
    {
        // auto jumpKey = jumpMap.find()
        auto jumpKey = jumpMap.find(instruction.substr(semiPos+1, 3));
        if(jumpKey == jumpMap.end())
            throw WRONG_JUMP;
        jump = jumpKey->second;
    }
    

    // 111accccdddjjj basic instrction set
    return "111" + std::to_string(a) + comp.to_string() + dest.to_string() + jump.to_string();
}
std::string AInstConv(std::string &instruction)
{
    int a = std::stoi(instruction.substr(1));

    return "0" + (std::bitset<15>(a)).to_string();
}
