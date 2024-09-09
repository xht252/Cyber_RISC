#pragma once
#ifndef Rtype

#include<iostream>

using namespace std;

class Rtype
{
    /*
        R-type指令
        一共有9条
    */
    public:
      static void ADD(int rd, int rs1, int rs2);
      static void SUB(int rd, int rs1, int rs2);
      static void XOR(int rd, int rs1, int rs2);
      static void SRL(int rd, int rs1, int rs2);
      static void OR(int rd, int rs1, int rs2);
      static void AND(int rd, int rs1, int rs2);
      static void SLL(int rd, int rs1, int rs2);
      static void SLT(int rd, int rs1, int rs2);
      static void SRA(int rd, int rs1, int rs2); 
};



#endif