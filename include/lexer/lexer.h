#pragma once
#include "instruction.h"
#include<memory>
#include<string>
#include<fstream>

class Lexer{
	public:
	
	int LOCCTR = 0x0000;
	char curChar= ' ';
	static std::ifstream asmFile;	


	char readChar();
	std::shared_ptr<Instr> getInstr();

	Lexer();
	~Lexer();

};
