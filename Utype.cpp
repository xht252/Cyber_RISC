#pragma once
#ifndef Utype

#include<iostream>
#include "CommonOperate.h"

using namespace std;

class Utype
{
    /*
        U-type指令
        一共有2条
    */
    public:
      static void LUI(int rd, int imm);
      static void AUIPC(int rd, int imm);
};

void Utype::LUI(int rd, int imm)
{
    // 一个20位的立即数加载到寄存器rd的高20位，低12位为0
    reg[rd] = imm << 12;
    PC += 4;
}

void Utype::AUIPC(int rd, int imm)
{
    // 一个20位的立即数加载到寄存器rd的高20位，低12位为0
    reg[rd] = PC + (imm << 12);
    PC += 4;
}


#endif