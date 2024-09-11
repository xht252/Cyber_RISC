#pragma once 
#ifndef Jtype

#include<iostream>

#include "CommonOperate.h"

using namespace std;

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