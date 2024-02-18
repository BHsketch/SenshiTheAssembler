#pragma once
#include "instruction.h"
#include<memory>
#include<string>

class Lexer{
	public:
	
	int LOCCTR = 0x0000;
	char curChar= ' ';


	char readChar();
	std::shared_ptr<Instr> getInstr();

};
