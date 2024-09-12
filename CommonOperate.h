#pragma once
#ifndef CommonOperate

#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<unordered_map>

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



#endif