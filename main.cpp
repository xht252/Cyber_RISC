/*
RISC-V ISA Simulator
Created by: xht
Time: 2024-09-08
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "CommonOperate.h"

using namespace std;

void Get_Instruction(string path);
void ParseInstruction(string I);

int main()
{
    Get_Instruction("D:\\pro_of_program\\RISC-V\\Cyber_RISC\\ok.txt");
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
            if(t.size() == 0) continue;
            else
            {
                // 可能标号和代码在同一行
                instruction.push_back(make_pair(t, start_pos));
                start_pos += 4; // 32位按字节编址
            }
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
        cout << i.first << " " << i.second << endl;
}
