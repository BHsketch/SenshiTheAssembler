#include"../../include/lexer/instruction.h"
#include"../../include/assembler/conversions.h"
#include<fstream>

void Instr::printFullInstr(int e)
{
	static std::ofstream emitCode("emitInter.txt");
	if(e==0)
	{
		emitCode<<addr<<"\t"<<label<<"\t"<<opCode<<"\t"<<operands<<"\n";
	}else if(e==1)
	{
		// erroneous instruction; duplicate label
		emitCode<<addr<<"\t"<<label<<"\t"<<opCode<<"\t"<<operands<<"\tE=1\n";
	}
}

void Instr::printFullInstrMachine(int e, std::string opCodeMachine, int operandMachine)
{
	static std::ofstream emitMachineCode("emitMachineCode.txt");
	if(e==0)
	{
		emitMachineCode<<addr<<"\t"<<label<<"\t"<<opCodeMachine<<"\t"<<intToHex(operandMachine)<<"\n";
	}else if(e==1)
	{
		emitMachineCode<<addr<<"\t"<<label<<"\t"<<opCodeMachine<<"\t"<<intToHex(operandMachine)<<"\tE=1\n";
	}
}
