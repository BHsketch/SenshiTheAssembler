#pragma once
#include<string>

class Instr{
	public:
	
	std::string addr = "";
	std::string label = "";
	std::string opCode = "";
	std::string operands = "";

	void printFullInstr(int e);
	void printFullInstrMachine(int e, std::string opCode, int operand);
	
};
