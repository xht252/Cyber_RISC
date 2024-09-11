#pragma once 
#ifndef Btype

#include<iostream>
#include "CommonOperate.h"

using namespace std;

class Btype
{
    /*
        B-type指令
        一共有2条
    */
    public:
      static void BEQ(int rs1, int rs2, int imm);
      static void BNE(int rs1, int rs2, int imm);
};



#endif