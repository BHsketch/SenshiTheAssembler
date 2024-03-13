#include"../../include/lexer/lexer.h"
#include"../../include/assembler/pass1.h"
#include"../../include/assembler/pass2.h"
#include"../../include/assembler/symTab.h"
#include"../../include/assembler/opTab.h"
#include"../../include/assembler/conversions.h"
#include<memory>
#include<iostream>

int main()
{
	std::shared_ptr<Lexer> lexer = std::make_shared<Lexer>();
	std::shared_ptr<SymTab> symTab = std::make_shared<SymTab>();
	std::shared_ptr<OpTab> opTab = std::make_shared<OpTab>();

	(opTab->opTable)["add"] = "18";
	(opTab->opTable)["and"] = "40";
	(opTab->opTable)["comp"] = "28";
	(opTab->opTable)["div"] = "24";
	(opTab->opTable)["j"] = "3c";
	(opTab->opTable)["jeq"] = "30";
	(opTab->opTable)["jgt"] = "34";
	(opTab->opTable)["jlt"] = "38";
	(opTab->opTable)["jsub"] = "48";
	(opTab->opTable)["lda"] = "00";
	(opTab->opTable)["ldl"] = "08";
	(opTab->opTable)["ldx"] = "04";
	(opTab->opTable)["or"] = "44";
	(opTab->opTable)["rd"] = "d8";
	(opTab->opTable)["rsub"] = "4c";
	(opTab->opTable)["sta"] = "0c";
	(opTab->opTable)["stch"] = "54";
	(opTab->opTable)["stl"] = "14";
	(opTab->opTable)["stx"] = "10";
	(opTab->opTable)["sub"] = "1c";
	(opTab->opTable)["td"] = "e0";
	(opTab->opTable)["tix"] = "2c";
	(opTab->opTable)["wd"] = "dc";

	pass1(lexer, symTab, opTab);
	
	std::cout<<"PASS 2 ABOUT TO BEGIN\n";

	lexer.reset(); //lexer's destructor is called
	std::shared_ptr<Lexer> lexer2 = std::make_shared<Lexer>();
	pass2(lexer2, symTab, opTab);
}

