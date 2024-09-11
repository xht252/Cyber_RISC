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

#include "CommonOperate.h"

using namespace std;

void Get_Instruction(string path);
void ParseInstruction(string I);

int main()
{
    init_reg(); // 初始化寄存器
    init_type(); // 初始化指令类型
    Get_Instruction("D:\\pro_of_program\\RISC-V\\Cyber_RISC\\ok.txt");

}

int check(string s)
{
    for(auto i : s)
    {
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

        if(line.size() == 0) // 空行
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
            }
            start_pos += 4; // 32位按字节编址
        }
        else
        {
            instruction.push_back(make_pair(line, start_pos));
            start_pos += 4;
        }
    }
    infile.close();

    // 解析指令
    for(auto i : instruction)
        ParseInstruction(i.first);
}


void ParseInstruction(string I)
{
    // 解析指令
    // 指令操作码大小写任意
    string op = I.substr(0, I.find(' ')); // 去除操作码
    I = I.substr(I.find(' ') + 1);
    string tmp = "";
    for(int i = 0;i < I.size();i ++)
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
    }
}