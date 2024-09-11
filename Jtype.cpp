#pragma once 
#ifndef Jtype

#include<iostream>

#include "CommonOperate.h"


class Jtype
{
    public:
        static void JAL(int rd, int imm);
};

void Jtype::JAL(int rd, int imm)
{
    reg[rd] = PC;
    PC = PC + imm;
}

#endif