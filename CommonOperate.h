#pragma once
#ifndef CommonOperate

#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <bitset>
#include <sstream>

using namespace std;

// 32位机 int即可
int reg[32] = {0}; // RISC-V 32个通用寄存器
unordered_map<string , int> reg_map; // 用于寄存器名到寄存器编号的映射
unordered_map<int , string> reg_map2; // 用于寄存器编号到寄存器名的映射
map<int , int>M; // 用于模拟存储器数据
int PC; // 程序计数器
unordered_map<string , int>Label; // 存储标号和对应的位置
unordered_map<string , string>TYPE; // 指令类型

// 初始化寄存器
void init_reg()
{
    reg_map2.clear();reg_map.clear();
    M.clear();Label.clear();TYPE.clear();
    memset(reg, 0, sizeof(reg));
    // 用于寄存器名到寄存器编号的映射
    // 解析指令时使用
    reg_map["zero"]= 0;
    reg_map ["ra"] = 1;
    reg_map ["sp"] = 2; 
    reg_map ["gp"] = 3;
    reg_map ["tp"] = 4;
    reg_map ["t0"] = 5;
    reg_map ["t1"] = 6;
    reg_map ["t2"] = 7;
    reg_map ["s0"] = 8;
    reg_map ["s1"] = 9;
    reg_map ["a0"] = 10;
    reg_map ["a1"] = 11;
    reg_map ["a2"] = 12;
    reg_map ["a3"] = 13;
    reg_map ["a4"] = 14;
    reg_map ["a5"] = 15;
    reg_map ["a6"] = 16;
    reg_map ["a7"] = 17;
    reg_map ["s2"] = 18;
    reg_map ["s3"] = 19;
    reg_map ["s4"] = 20;
    reg_map ["s5"] = 21;
    reg_map ["s6"] = 22;
    reg_map ["s7"] = 23;
    reg_map ["s8"] = 24;
    reg_map ["s9"] = 25;
    reg_map ["s10"] = 26;
    reg_map ["s11"] = 27;
    reg_map ["t3"] = 28;
    reg_map ["t4"] = 29;
    reg_map ["t5"] = 30;
    reg_map ["t6"] = 31;

    for(auto i : reg_map)
        reg_map2[i.second] = i.first;
}

void init_type()
{
    TYPE["ADD"] = "Rtype";TYPE["SUB"] = "Rtype";
    TYPE["XOR"] = "Rtype";TYPE["SRL"] = "Rtype";
    TYPE["OR"] = "Rtype";TYPE["AND"] = "Rtype";
    TYPE["SLL"] = "Rtype";TYPE["SLT"] = "Rtype";TYPE["SRA"] = "Rtype";

    TYPE["LB"] = "Itype";TYPE["LH"] = "Itype";
    TYPE["LW"] = "Itype";TYPE["LBU"] = "Itype";
    TYPE["LHU"] = "Itype";TYPE["ADDI"] = "Itype";
    TYPE["XORI"] = "Itype";TYPE["ORI"] = "Itype";
    TYPE["ANDI"] = "Itype";

    TYPE["JAL"] = "Jtype";

    TYPE["BEQ"] = "Btype";TYPE["BNE"] = "Btype";
    TYPE["BLT"] = "Btype";TYPE["BGE"] = "Btype";
    TYPE["BLTU"] = "Btype";TYPE["BGEU"] = "Btype";

    TYPE["SB"] = "Stype";TYPE["SH"] = "Stype";
    TYPE["SW"] = "Stype";

    TYPE["LUI"] = "Utype";TYPE["AUIPC"] = "Utype";
}


string dec_to_hex(int dec)
{
    stringstream ss;
    ss << hex << dec;
    return ss.str();
}

string dec_to_bin(int dec)
{
    stringstream ss;
    ss << bitset<32>(dec);
    return ss.str();
}

string hex_to_bin(string hex)
{
    string bin;
    for (char c : hex)
    {
        switch (c)
        {
            case '0': bin += "0000"; break;
            case '1': bin += "0001"; break;
            case '2': bin += "0010"; break;
            case '3': bin += "0011"; break;
            case '4': bin += "0100"; break;
            case '5': bin += "0101"; break;
            case '6': bin += "0110"; break;
            case '7': bin += "0111"; break;
            case '8': bin += "1000"; break;
            case '9': bin += "1001"; break;
            case 'A': bin += "1010"; break;
            case 'B': bin += "1011"; break;
            case 'C': bin += "1100"; break;
            case 'D': bin += "1101"; break;
            case 'E': bin += "1110"; break;
            case 'F': bin += "1111"; break;
            case 'a': bin += "1010"; break;
            case 'b': bin += "1011"; break;
            case 'c': bin += "1100"; break;
            case 'd': bin += "1101"; break;
            case 'e': bin += "1110"; break;
            case 'f': bin += "1111"; break;
        }
    }
    return bin;
}

int bin_to_dec(string bin)
{
    int sign = 1;
    int dec = 0;
    if(bin[0] == '1') 
    {
        sign = -1;
        bin = bin.substr(1, bin.size() - 1);
        int i = bin.size() - 1;
        while(i >= 0 && bin[i] == '0') i --;
        for(int j = 0;j < i;j ++)
            if(bin[j] == '1') dec = dec * 2;
            else dec = dec * 2 + 1;
        
        for(int j = i; j < bin.size(); j ++)
            dec = dec * 2 + (bin[j] - '0');
    }
    else
    {
        for(int j = 0; j < bin.size(); j ++)
            dec = dec * 2 + (bin[j] - '0');
    }

    return dec * sign;
}

int hex_to_dec(string hex)
{
    string bin = hex_to_bin(hex);
    return bin_to_dec(bin);
}


#endif