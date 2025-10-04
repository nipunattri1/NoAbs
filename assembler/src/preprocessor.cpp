#include "preprocessor.h"
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <bitset>


std::string removeComments(std::string &instruction)
{
    std::string proInst = instruction; // processsed instrctions

    std::size_t pos = instruction.find("//");

    if (pos != std::string::npos)
        proInst = instruction.substr(0, pos);

    return proInst;
}


std::string preprocessor(std::string instruction)
{

    /*
    Chnage the values of constants to integers or other flags
    R0 - 0
    R1 - 1
    R2 - 2
    R3 - 3
    R4 - 4
    R5 - 5
    ....
    R15 - 15

    SCREEN 16384
    KBD 24576
    */
    // check of instruction is A if A then, check for flags, else go for declaraton of a var
    static std::map<std::string, size_t> constants{
        {"R0", 0},
        {"R1", 1},
        {"R2", 2},
        {"R3", 3},
        {"R4", 4},
        {"R5", 5},
        {"R6", 6},
        {"R7", 7},
        {"R8", 8},
        {"R9", 9},
        {"R10", 10},
        {"R11", 11},
        {"R12", 12},
        {"R13", 13},
        {"R14", 14},
        {"R15", 15},
        {"SCREEN", 16384},
        {"KBD", 24576},
    };
    static size_t addressCounter = 15;
    static size_t lineIndex = 1;
    // strip of all spaces in code
    instruction.erase(std::remove(instruction.begin(), instruction.end(), ' '), instruction.end());
    instruction = removeComments(instruction);

    // if starts with @ (64) it's a A instruction
    if (instruction[0] == 64)
    {
        if (!(instruction[1] <= 57 && instruction[1] >= 47))
        {
            std::string key = instruction.substr(1); // for A instruction @Key "key" is var key

            if (constants.find(key) == constants.end()) // check if key in map
                constants[key] = ++addressCounter;
            lineIndex++;
            return "@" + std::to_string(constants[key]);
        }
        else
        {
            for (int i = 1; i < instruction.length(); i++)
            {
                if (!(instruction[i] <= 57 && instruction[i] >= 47))
                {
                    throw 1; // Invalid Instruction...
                }
            }
        }
        lineIndex++;
    }
    else if(instruction[0] == '(' && instruction[instruction.length() -1] == ')')
    {
        constants[instruction.substr(1, instruction.length() -1)] = ++lineIndex;
        return "";
    }
    return instruction;
}