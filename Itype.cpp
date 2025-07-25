#pragma once 
#ifndef Itype


#include "CommonOperate.h"


class Itype
{
    /*
        I-type指令
        一共有15条
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
        static void SLTI(int rd, int rs1, int imm);
        static void SLTIU(int rd, int rs1, int imm);
        static void SLLI(int rd, int rs1, int imm);
        static void SRLI(int rd, int rs1, int imm);
        static void SRAI(int rd, int rs1, int imm);
        static void JALR(int rd, int rs1, int imm);
};


void Itype::LB(int rd, int rs1, int imm)
{
    // 从存储器种读出1个字节的数据按符号位扩展后，送入rd
    reg[rd] = (unsigned char)(M[reg[rs1] + imm]);
    PC += 4;
}


void Itype::LH(int rd, int rs1, int imm)
{
    // 从存储器种读出2个字节的数据按符号位扩展后，送入rd
    char tmp = M[reg[rs1] + imm];
    char tmp1 = M[reg[rs1] + imm + 1]; // 高地址在高位
    // cout << (int)tmp << " " << (int)tmp1 << endl;
    int tmp2 = ((unsigned char)tmp1 << 8) | (unsigned char)tmp; // 小端存储
    reg[rd] = tmp2;
    PC += 4;
}



void Itype::LW(int rd, int rs1, int imm)
{
    // 从存储器种读出4个字节的数据送入rd
    char tmp = M[reg[rs1] + imm];
    char tmp1 = M[reg[rs1] + imm + 1];
    char tmp2 = M[reg[rs1] + imm + 2];
    char tmp3 = M[reg[rs1] + imm + 3];
    reg[rd] = ((unsigned char)tmp3 << 24) | ((unsigned char)tmp2 << 16) | ((unsigned char)tmp1 << 8) | (unsigned char)tmp;
    PC += 4;
}


void Itype::LBU(int rd, int rs1, int imm)
{
    // 无符号从存储器种读出1个字节的数据送入rd
    reg[rd] = (unsigned char)(M[reg[rs1] + imm]);
    PC += 4;
}


void Itype::LHU(int rd, int rs1, int imm)
{
    // 无符号从存储器种读出2个字节的数据送入rd
    unsigned char tmp = (unsigned char)M[reg[rs1] + imm];
    unsigned char tmp1 = (unsigned char)M[reg[rs1] + imm + 1];
    reg[rd] = (unsigned short int)(tmp1 << 8) | tmp;
    PC += 4;
}


void Itype::ADDI(int rd, int rs1, int imm)
{
    // 立即数加法
    reg[rd] = reg[rs1] + imm;
    PC += 4;
}


void Itype::XORI(int rd, int rs1, int imm)
{
    // 立即数异或
    reg[rd] = reg[rs1] ^ imm;
    PC += 4;
}


void Itype::ANDI(int rd, int rs1, int imm)
{
    // 立即数与
    reg[rd] = reg[rs1] & imm;
    PC += 4;
}


void Itype::ORI(int rd, int rs1, int imm)
{
    // 立即数或
    reg[rd] = reg[rs1] | imm;
    PC += 4;
}

void Itype::SLTI(int rd, int rs1, int imm)
{
    // slti rd, rs1, imm
    if(reg[rs1] < imm)
        reg[rd] = 1; 
    else
        reg[rd] = 0; 
    PC += 4;
}

void Itype::SLTIU(int rd, int rs1, int imm)
{
    // sltiu rd, rs1, imm
    if((unsigned int)reg[rs1] < (unsigned int)imm)
        reg[rd] = 1; 
    else
        reg[rd] = 1; 
    PC += 4;
}

void Itype::SLLI(int rd, int rs1, int imm)
{
    // slli rd, rs1, imm
    reg[rd] = reg[rs1] << imm;
    PC += 4;
}

void Itype::SRLI(int rd, int rs1, int imm)
{
    // srli rd, rs1, imm
    reg[rd] = (unsigned int)reg[rs1] >> imm;
    PC += 4;
}

void Itype::SRAI(int rd, int rs1, int imm)
{
    // srai rd, rs1, imm
    reg[rd] = reg[rs1] >> imm;
    PC += 4;
}

void Itype::JALR(int rd, int rs1, int imm)
{
    // jalr rd, rs1 , imm
    PC = reg[rs1] + imm;
    reg[rd] = PC + 4;
}


#endif