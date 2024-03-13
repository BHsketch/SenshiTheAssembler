#pragma once
#include<memory>
#include"../lexer/lexer.h"
#include"symTab.h"
#include"opTab.h"

void pass2(std::shared_ptr<Lexer> lexer, std::shared_ptr<SymTab> symTab, std::shared_ptr<OpTab> opTab);
