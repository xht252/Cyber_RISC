/*
RISC-V ISA Simulator
Created by: xht
Time: 2024-09-08
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stdlib.h>

#include "CommonOperate.h"
#include "Rtype.cpp"
#include "Utype.cpp"
#include "Itype.cpp"
#include "Stype.cpp"
#include "Jtype.cpp"
#include "Btype.cpp"

using namespace std;

void Get_Instruction(string path);
void ParseInstruction(string I);

int main()
{
    // int x = 15621;
    // string hex = dec_to_hex(x);
    // cout << hex << endl;
    // string bin = dec_to_bin(x);
    // cout << bin << endl;

    // string w = hex_to_bin(hex);
    // cout << w << endl;

    // int y = hex_to_dec(hex);
    // cout << y << endl;
    // int z = bin_to_dec(bin);
    // cout << z << endl;

    init_reg(); // 初始化寄存器
    init_type(); // 初始化指令类型
    Get_Instruction("D:\\pro_of_program\\RISC-V\\Cyber_RISC\\test\\btest.txt");

    for(int i = 0;i < 32;i ++)
        cout << reg_map2[i] << ": " << reg[i] << endl;

    cout << endl;
    for(auto i : M)
        cout << i.first << ": " << (int)i.second << endl;

    return 0;
}

int check(string s)
{
    for(auto i : s)
    {
        // 检查当前行是否有指令
        if(isalnum(i))
            return i;
    }
    return -1;
}

void Get_Instruction(string path)
{
    int start_pos = 0;
    vector<pair<string , int>>instruction; // 指令+对应的地址
    ifstream infile;
    infile.open(path);
    if (!infile.is_open())
    {
        cout << "open file failed!" << endl;
    }
    string line;

    while(getline(infile, line))
    {
        int i = 0;
        while (line[i] == ' ') i ++; // 去除前导的空格
        line = line.substr(i);

        if (line.find('#') != string::npos) // 有注释
            line = line.substr(0 , line.find("#"));

        if(line.size() == 0 || (line.size() == 1 && (line[0] == '\0' || line[0] == ' ' || line[0] == '\n'))) // 空行
            continue;

        if(line.find(':') != string::npos) // 有标号
        {
            string s = line.substr(0, line.find(":"));
            Label[s] = start_pos;
            string t = line.substr(line.find(":") + 1);
            if(check(t) != -1)
            {
                // 可能标号和代码在同一行
                instruction.push_back(make_pair(t, start_pos));
                start_pos += 4; // 32位按字节编址
            }
            // else Label[s] = start_pos + 4; // 当前指令的下一条指令
        }
        else
        {
            instruction.push_back(make_pair(line, start_pos));
            start_pos += 4;
        }
    }
    infile.close();

    // for(auto i : instruction)
    //     cout << i.second << ": " << i.first << endl;

    // for(auto i : Label)
    //     cout << i.first << ": " << i.second << endl;
    // 解析指令
    while(1)
    {
        for(int i = 0;i < instruction.size();i ++)
            if(instruction[i].second == PC) 
            {
                ParseInstruction(instruction[i].first);
            }
        
        if(PC >= start_pos) break;
    }
}


void ParseInstruction(string I)
{
    // 解析指令
    // 指令操作码大小写任意
    string op = I.substr(0, I.find(' ')); // 去除操作码
    I = I.substr(I.find(' ') + 1);
    string tmp = "";
    for(int i = 0;i < (int)I.size();i ++)
        if(I[i] == ' ') continue;
        else tmp.push_back(I[i]);

    I = tmp;// 去除空格

    transform(op.begin(), op.end(), op.begin(), ::toupper); // 操作码转为大写
    string type = TYPE[op]; // 指令类型

    if(type[0] == 'R') // R-type指令
    {
        // op rd rs1 rs2
        int rd = reg_map[I.substr(0 , I.find(","))];
        I = I.substr(I.find(",") + 1);
        int rs1 = reg_map[I.substr(0 , I.find(","))];
        I = I.substr(I.find(",") + 1);
        int rs2 = reg_map[I];

        if(op == "ADD") Rtype::ADD(rd, rs1, rs2);
        else if(op == "SUB") Rtype::SUB(rd, rs1, rs2);
        else if(op == "XOR") Rtype::XOR(rd, rs1, rs2);
        else if(op == "SRL") Rtype::SRL(rd, rs1, rs2);
        else if(op == "OR") Rtype::OR(rd, rs1, rs2);
        else if(op == "AND") Rtype::AND(rd, rs1, rs2);
        else if(op == "SLL") Rtype::SLL(rd, rs1, rs2);
        else if(op == "SLT") Rtype::SLT(rd, rs1, rs2);
        else if(op == "SRA") Rtype::SRA(rd, rs1, rs2);
    }
    else if (type[0] == 'I')
    {
        // op rd rs1 imm
        int rd = reg_map[I.substr(0 , I.find(","))];
        I = I.substr(I.find(",") + 1);
        int rs1 = reg_map[I.substr(0 , I.find(","))];
        I = I.substr(I.find(",") + 1);
        int imm = stoi(I);

        if(op == "LB") Itype::LB(rd, rs1, imm);
        else if(op == "LH") Itype::LH(rd, rs1, imm);
        else if(op == "LW") Itype::LW(rd, rs1, imm);
        else if(op == "LBU") Itype::LBU(rd, rs1, imm);
        else if(op == "LHU") Itype::LHU(rd, rs1, imm);  
        else if(op == "ADDI") Itype::ADDI(rd, rs1, imm);
        else if(op == "XORI") Itype::XORI(rd, rs1, imm);
        else if(op == "ANDI") Itype::ANDI(rd, rs1, imm);
        else if(op == "ORI") Itype::ORI(rd, rs1, imm);
    }
    else if (type[0] == 'S')
    {
        // op rs1 rs2 imm
        int rs1 = reg_map[I.substr(0 , I.find(","))];
        I = I.substr(I.find(",") + 1);
        int rs2 = reg_map[I.substr(0 , I.find(","))];
        I = I.substr(I.find(",") + 1);
        int imm = stoi(I);

        if(op == "SB") Stype::SB(rs1, rs2, imm);
        else if(op == "SH") Stype::SH(rs1, rs2, imm);
        else if(op == "SW") Stype::SW(rs1, rs2, imm);
    }
    else if (type[0] == 'B')
    {
        // op rs1, rs2, imm
        int rs1 = reg_map[I.substr(0 , I.find(","))];
        I = I.substr(I.find(",") + 1);
        int rs2 = reg_map[I.substr(0 , I.find(","))];
        I = I.substr(I.find(",") + 1);
        int imm = Label[I] - PC;

        if(op == "BEQ") Btype::BEQ(rs1, rs2, imm);
        else if(op == "BNE") Btype::BNE(rs1, rs2, imm);
        else if(op == "BLT") Btype::BLT(rs1, rs2, imm);
        else if(op == "BGE") Btype::BGE(rs1, rs2, imm);
        else if(op == "BGEU") Btype::BGEU(rs1, rs2, imm);
        else if(op == "BLTU") Btype::BLTU(rs1, rs2, imm);
    }
    else if(type[0] == 'U')
    {
        // op rd imm
        int rd = reg_map[I.substr(0 , I.find(","))];
        I = I.substr(I.find(",") + 1);
        int imm = stoi(I);

        if(op == "LUI") Utype::LUI(rd, imm);
        else if(op == "AUIPC") Utype::AUIPC(rd, imm);
    }
    else 
    {
        // op rd imm
        int rd = reg_map[I.substr(0 , I.find(","))];
        I = I.substr(I.find(",") + 1);
        int imm = Label[I] - PC;

        if(op == "JAL") Jtype::JAL(rd, imm);
    }
    
}