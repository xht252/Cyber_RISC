#pragma once 
#ifndef Itype

#include<iostream>

#include "CommonOperate.h"

using namespace std;

class Itype
{
    /*
        I-type指令
        一共有9条
    */
    public:
        static void LB(int rd, int rs1, int imm);
        static void LH(int rd, int rs1, int imm);
        static void LW(int rd, int rs1, int imm);
        static void LBU(int rd, int rs1, int imm);
        static void LHU(int rd, int rs1, int imm);
        static void ADDI(int rd, int rs1, int imm);
        static void XORI(int rd, int rs1, int imm);
        static void ANDI(int rd, int rs1, int imm);
        static void ORI(int rd, int rs1, int imm);
};

void Itype::LB(int rd, int rs1, int imm)
{
    // 从存储器种读出1个字节的数据按符号位扩展后，送入rd
    reg[rd] = (char)(M[reg[rs1] + imm]);
    PC += 4;
}

void Itype::LH(int rd, int rs1, int imm)
{
    // 从存储器种读出2个字节的数据按符号位扩展后，送入rd
    char tmp = M[reg[rs1] + imm];
    char tmp1 = M[reg[rs1] + imm + 1]; // 高地址在高位
    reg[rd] = (tmp1 << 8) | tmp; // 小端存储
    PC += 4;
}

void Itype::LW(int rd, int rs1, int imm)
{
    // 从存储器种读出4个字节的数据送入rd
    char tmp = M[reg[rs1] + imm];
    char tmp1 = M[reg[rs1] + imm + 1];
    char tmp2 = M[reg[rs1] + imm + 2];
    char tmp3 = M[reg[rs1] + imm + 3];
    reg[rd] = (tmp3 << 24) | (tmp2 << 16) | (tmp1 << 8) | tmp;
    PC += 4;
}

void Itype::LBU(int rd, int rs1, int imm)
{
    reg[rd] = (unsigned char)(M[reg[rs1] + imm]);
    PC += 4;
}


void Itype::LHU(int rd, int rs1, int imm)
{
    unsigned char tmp = (unsigned char)M[reg[rs1] + imm];
    unsigned char tmp1 = (unsigned char)M[reg[rs1] + imm + 1];
    reg[rd] = (unsigned short int)(tmp1 << 8) | tmp;
    PC += 4;
}


void Itype::ADDI(int rd, int rs1, int imm)
{
    reg[rd] = reg[rs1] + imm;
    PC += 4;
}


void Itype::XORI(int rd, int rs1, int imm)
{
    reg[rd] = reg[rs1] ^ imm;
    PC += 4;
}


void Itype::ANDI(int rd, int rs1, int imm)
{
    reg[rd] = reg[rs1] & imm;
    PC += 4;
}


void Itype::ORI(int rd, int rs1, int imm)
{
    reg[rd] = reg[rs1] | imm;
    PC += 4;
}


#endif