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
map<int , char>M; // 用于模拟存储器数据
int PC; // 程序计数器
unordered_map<string , int>Label; // 存储标号和对应的位置


// 初始化寄存器
void init_reg()
{
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
}



#endif