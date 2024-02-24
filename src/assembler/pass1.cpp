#include"../../include/lexer/lexer.h"
#include"../../include/assembler/pass1.h"
#include"../../include/assembler/conversions.h"
#include<sstream>
#include<iostream>
#include<memory>
#include<unordered_map>
#include<string>

void pass1(std::shared_ptr<Lexer> lexer, std::shared_ptr<SymTab> symTab, std::shared_ptr<OpTab> opTab)
{
	int LOCCTR;
	std::shared_ptr<Instr> curInstruction = std::make_shared<Instr>();
	int startAddr;

	curInstruction = lexer->getInstr();
	if(curInstruction->opCode == "start")
	{
		//std::cout<<"FOUND START INSTRUCTION\n";
		startAddr = hexToInt(curInstruction->operands);
		// start address stored as integer version of our hex string.
		LOCCTR = startAddr;
		curInstruction->printFullInstr(0);
		// print the instruction along with its address

		curInstruction = lexer->getInstr();
	}else{
		LOCCTR = 0;
	}

	while(curInstruction->opCode != "end")
	{
		std::string curLabel = curInstruction->label;
		std::string curOpCode = curInstruction->opCode;
		std::string curOperands = curInstruction->operands;
		// update address of current instruction to LOCCTR (location counter)
		curInstruction->addr = intToHex(LOCCTR); 
		int err = 0;

		if(curInstruction->label != "")
		{
			if(symTab->symbolTable.find(curLabel) != symTab->symbolTable.end())
			{
				// argument 1 sets error condition 1: duplicate symbol
				curInstruction->printFullInstr(1);	
			}else{
				(symTab->symbolTable)[curLabel] = LOCCTR;
			}
		}

		if(opTab->opTable.find(curOpCode) != opTab->opTable.end())
		{
			LOCCTR += 3;
		}else if(curOpCode == "WORD")
		{
			LOCCTR += 3;

		}else if(curOpCode == "RESW")
		{
			LOCCTR += (3*std::stoi(curOperands));

		}else if(curOpCode == "RESB")
		{
			LOCCTR += (std::stoi(curOperands));

		}else if(curOpCode == "BYTE")
		{

			// LEAVING THIS FUNCTIONALITY FOR NOW
		}else{

			err = 1;	
		}
		// print instruction to intermediate file
		if(err ==1)
		{

			curInstruction->printFullInstr(1);	
		}else{

			curInstruction->printFullInstr(0);	

		}

		curInstruction = lexer->getInstr();
	}


}
