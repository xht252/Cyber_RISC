#pragma once 
#ifndef Stype

#include<iostream>
#include "CommonOperate.h"

class Stype
{
    /*
        S-type指令
        一共有3条
    */
    public:
      static void SB(int rs1, int rs2, int imm); 
      static void SH(int rs1, int rs2, int imm); 
      static void SW(int rs1, int rs2, int imm); 
};

void Stype::SB(int rs1, int rs2, int imm)
{
    // 寄存器间接寻址
    M[reg[rs2] + imm] = (char)reg[rs1];
    PC += 4;
}

void Stype::SH(int rs1, int rs2, int imm)
{
    short tmp = (short)reg[rs1];
    cout << tmp << endl;
    char lower = (char)tmp;
    char upper = (char)(tmp >> 8);
    M[reg[rs2] + imm] = lower; // 小端存储 低地址存放在低位
    M[reg[rs2] + imm + 1] = upper;
    PC += 4;
}


void Stype::SW(int rs1, int rs2, int imm)
{
    int tmp = reg[rs1];
    char lower = (char)tmp;
    char upper = (char)(tmp >> 8);
    char upper2 = (char)(tmp >> 16);
    char upper3 = (char)(tmp >> 24);
    M[reg[rs2] + imm] = lower; // 小端存储 低地址存放在低位
    M[reg[rs2] + imm + 1] = upper;
    M[reg[rs2] + imm + 2] = upper2;
    M[reg[rs2] + imm + 3] = upper3;
    PC += 4;
}

#endif