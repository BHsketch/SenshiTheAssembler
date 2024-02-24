#include"../../include/lexer/instruction.h"
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

