#pragma once 
#ifndef Btype

#include<iostream>
#include "CommonOperate.h"

using namespace std;

class Btype
{
    /*
        B-type指令
        一共有6条
    */
    public:
      static void BEQ(int rs1, int rs2, int imm);
      static void BNE(int rs1, int rs2, int imm);
      static void BLT(int rs1, int rs2, int imm);
      static void BGE(int rs1, int rs2, int imm);
      static void BGEU(int rs1, int rs2, int imm);
      static void BLTU(int rs1, int rs2, int imm);
};

void Btype::BEQ(int rs1, int rs2, int imm)
{
    if (reg[rs1] == reg[rs2])
        PC += imm; // 正常的偏移量需要 x 4(4个指令单位)
    else
    {
        PC += 4;
    }
}

void Btype::BNE(int rs1, int rs2, int imm)
{
    if (reg[rs1] != reg[rs2])
        PC += imm;
    else
    {
        PC += 4;
    }
}

void Btype::BLT(int rs1, int rs2, int imm)
{
    if (reg[rs1] < reg[rs2])
        PC += imm;
    else
    {
        PC += 4;
    }
}

void Btype::BGE(int rs1, int rs2, int imm)
{
    if (reg[rs1] >= reg[rs2])
        PC += imm;
    else
    {
        PC += 4;
    }
}

void Btype::BGEU(int rs1, int rs2, int imm)
{
    uint32_t tmp = reg[rs1];
    uint32_t tmp1 = reg[rs2];
    if (tmp >= tmp1)
        PC += imm;
    else
    {
        PC += 4;
    }
}

void Btype::BLTU(int rs1, int rs2, int imm)
{
    uint32_t tmp = reg[rs1];
    uint32_t tmp1 = reg[rs2];
    if (tmp < tmp1)
        PC += imm;
    else
    {
        PC += 4;
    }
}


#endif