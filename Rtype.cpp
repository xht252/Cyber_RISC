#pragma once
#ifndef Rtype

#include "CommonOperate.h"

class Rtype
{
    /*
        R-type指令
        一共有9条
    */
    public:
        static void ADD(int rd, int rs1, int rs2); // 32位加法
        static void SUB(int rd, int rs1, int rs2); // 32位减法
        static void XOR(int rd, int rs1, int rs2); // 逻辑异或
        static void SRL(int rd, int rs1, int rs2); // 逻辑右移
        static void OR(int rd, int rs1, int rs2); // 逻辑或
        static void AND(int rd, int rs1, int rs2); // 逻辑与
        static void SLL(int rd, int rs1, int rs2); // 逻辑左移
        static void SLT(int rd, int rs1, int rs2); // 比较
        static void SRA(int rd, int rs1, int rs2); // 逻辑右移
};

void Rtype::ADD(int rd, int rs1, int rs2)
{
    reg[rd] = reg[rs1] + reg[rs2];
    PC += 4; // 32位按字节编址，指令长度为4
}

void Rtype::SUB(int rd, int rs1, int rs2)
{
    reg[rd] = reg[rs1] - reg[rs2];
    PC += 4;
}

void Rtype::XOR(int rd, int rs1, int rs2)
{
    reg[rd] = reg[rs1] ^ reg[rs2];
    PC += 4;
}

void Rtype::SRL(int rd, int rs1, int rs2)
{
    // 逻辑右移，将数据作为无符号数进行右移
    reg[rd] = (unsigned int)reg[rs1] >> reg[rs2];
    PC += 4;
}

void Rtype::OR(int rd, int rs1, int rs2)
{
    reg[rd] = reg[rs1] | reg[rs2];
    PC += 4;
}

void Rtype::AND(int rd, int rs1, int rs2)
{
    reg[rd] = reg[rs1] & reg[rs2];
    PC += 4;
}

void Rtype::SLL(int rd, int rs1, int rs2)
{
    // 逻辑左移，将数据作为无符号数进行左移
    reg[rd] = (unsigned int)reg[rs1] << reg[rs2];
    PC += 4;
}

void Rtype::SLT(int rd, int rs1, int rs2)
{
    if (reg[rs1] < reg[rs2])
    {
        reg[rd] = 1;
    }
    else
    {
        reg[rd] = 0;
    }
    PC += 4;
}

void Rtype::SRA(int rd, int rs1, int rs2)
{
    // 右移算术逻辑运算
    reg[rd] = reg[rs1] >> reg[rs2];
    PC += 4;
}


#endif