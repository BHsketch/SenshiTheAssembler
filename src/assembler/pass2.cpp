#include"../../include/lexer/lexer.h"
#include"../../include/assembler/pass1.h"
#include"../../include/assembler/pass2.h"
#include"../../include/assembler/conversions.h"
#include<sstream>
#include<iostream>
#include<memory>
#include<unordered_map>
#include<string>

void pass2(std::shared_ptr<Lexer> lexer, std::shared_ptr<SymTab> symTab, std::shared_ptr<OpTab> opTab)
{
	int LOCCTR;
	std::shared_ptr<Instr> curInstruction = std::make_shared<Instr>();
	int startAddr;

	std::cout<<"hello\n";
	curInstruction = lexer->getInstr();
	std::cout<<"hello2\n";
	
	std::cout<<"opcode of first instr: "<<curInstruction->opCode<<"\n";

	if( (curInstruction->opCode == "start")) 
	{
		//std::cout<<"FOUND START INSTRUCTION\n";
		startAddr = hexToInt(curInstruction->operands);
		// start address stored as integer version of our hex string.
		LOCCTR = startAddr;
		curInstruction->printFullInstr(0);
		// print the instruction along with its address

		curInstruction = lexer->getInstr();
	}else if((curInstruction->opCode == "origin"))
	{
		LOCCTR = hexToInt(curInstruction->operands);

	}else{
		LOCCTR = 0;
	}

	while(curInstruction->opCode != "end")
	{
		std::string curLabel = curInstruction->label;
		std::string curOpCode = curInstruction->opCode;
		std::string curOperands = curInstruction->operands;
		// update address of current instruction to LOCCTR (location counter)

		std::string curOpCodeMachine="";
		curInstruction->addr = intToHex(LOCCTR); 
		int err = 0;
		int operandsMachineCode=0;

		if(opTab->opTable.find(curOpCode) != opTab->opTable.end())
		{
			curOpCodeMachine = (opTab->opTable)[curOpCode];
			if(symTab->symbolTable.find(curOperands) != symTab->symbolTable.end())
			{
				//this is a symbol
				operandsMachineCode = (symTab->symbolTable)[curOperands]; 
			}else{
				//this is a number
				//operandsMachineCode = curOperands;
			}
			//curInstruction->printFullInstr(1);
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
			curInstruction->printFullInstrMachine(1, curOpCodeMachine, operandsMachineCode);
		}else{

			curInstruction->printFullInstrMachine(0, curOpCodeMachine, operandsMachineCode);

		}

		curInstruction = lexer->getInstr();
	}
}
