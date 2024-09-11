/*
RISC-V ISA Simulator
Created by: xht
Time: 2024-09-08
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void Get_Instruction(string path);
void ParseInstruction(vector<string> instruction);

int main()
{
    Get_Instruction("D:\\pro_of_program\\RISC-V\\Cyber_RISC\\ok.txt");
}


void Get_Instruction(string path)
{
    vector<string>instruction;
    ifstream infile;
    infile.open(path);
    if (!infile.is_open())
    {
        cout << "open file failed!" << endl;
    }
    string line;

    while(getline(infile, line))
        instruction.push_back(line);
    infile.close();

    // 解析指令
    ParseInstruction(instruction);
}


void ParseInstruction(vector<string> instruction)
{

}