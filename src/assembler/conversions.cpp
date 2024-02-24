#include"../../include/assembler/conversions.h"
#include<sstream>
#include<string>

int hexToInt(std::string str)
{
        unsigned int x;
        int answer;
        std::stringstream ss;
        ss << std::hex << str;
        ss >> x;
        answer = static_cast<int>(x);
        return answer;
}

std::string intToHex(int num)
{
        std::stringstream ss;
        ss << "0x" << std::hex << num;
        return ss.str();
}

