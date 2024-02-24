#include"../../include/lexer/lexer.h"
#include<fstream>
#include<memory>
#include<vector>
#include<iostream>
#include<string>

char Lexer::readChar()
{
	static std::ifstream asmFile("test.asm");
	if(asmFile.is_open())
	{
		//std::cout<<"opened file"<<"\n";
		if(!asmFile.get(curChar))
		{
			curChar = '$';
		}
		//std::cout<<"stored char"<<"\n";
	}

	if(curChar != '$')
	{
		std::cout<<"returning character "<<curChar<<"\n";
		return curChar;
	}else{
		asmFile.close();
		//std::cout<<"DOLLARRRRRRR\n";
		curChar = '$';
		return curChar;
	}
	return curChar;
}

std::shared_ptr<Instr> Lexer::getInstr()
{
	std::shared_ptr<Instr> instructionBuf = std::make_shared<Instr>();
	int whiteSpaceCount = 0;
	std::vector<std::string> inputBuffer = {""};
	//int i = 0;

	

	while((std::isspace(static_cast<unsigned char>(curChar))) || (curChar == '.'))
	{
		if(curChar == '.')
		{
			while(curChar != '\n')
			{
				std::cout<<"reading comment\n";
				readChar();
			}	
			std::cout<<"comment done\n";
		}
		readChar();	
	}

	if(curChar == '$')
	{
		//std::cout<<"returning nullptr\n";
		return nullptr;
	}

	while(curChar != '\n')
	{
		if(std::isspace(static_cast<unsigned char>(curChar)))
		{
			if(curChar=='\n')
			{	
				std::cout<<"new line\n";
				break;
			}
			whiteSpaceCount++;
			inputBuffer.push_back("");
		}else{
			inputBuffer[whiteSpaceCount].push_back(curChar);
		}
		readChar();
	}
	if(curChar=='\n')
	{	
		std::cout<<"new line\n";
	}


	// at the end of the above loop, inputBuffer will have either two or three elements, depending on whether or not Label is there
	
	if(inputBuffer.size() == 3)
	{
		std::cout<<"decision\n";
		instructionBuf->label = inputBuffer[0];
		instructionBuf->opCode = inputBuffer[1];
		instructionBuf->operands = inputBuffer[2];

		std::cout<<"label: "<<inputBuffer[0]<<"		opCode: "<<inputBuffer[1]<<"	operands: "<<inputBuffer[2]<<"\n";
	}else if(inputBuffer.size() == 2){
		instructionBuf->opCode = inputBuffer[0];
		instructionBuf->operands = inputBuffer[1];
		std::cout<<"opCode: "<<inputBuffer[0]<<"	operands: "<<inputBuffer[1]<<"\n";
	}
	
	return instructionBuf;
}
/*
int main()
{
	Lexer lex;
	std::shared_ptr<Instr> test = std::make_shared<Instr>();
	while(test!=nullptr)
	{
		test = lex.getInstr();
	};
}*/
