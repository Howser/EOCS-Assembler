/* SymbolTable source file */

#include "SymbolTable.h"

using namespace std;

SymbolTable::SymbolTable(){

	// initialize predefined symbols of the language
	table.emplace("SP",   0x0000);
	table.emplace("LCL",  0x0001);
	table.emplace("ARG",  0x0002);
	table.emplace("THIS", 0x0003);
	table.emplace("THAT", 0x0004);

	table.emplace("R0",  0x0000);
	table.emplace("R1",  0x0001);
	table.emplace("R2",  0x0002);
	table.emplace("R3",  0x0003);
	table.emplace("R4",  0x0004);
	table.emplace("R5",  0x0005);
	table.emplace("R6",  0x0006);
	table.emplace("R7",  0x0007);
	table.emplace("R8",  0x0008);
	table.emplace("R9",  0x0009);
	table.emplace("R10", 0x000A);
	table.emplace("R11", 0x000B);
	table.emplace("R12", 0x000C);
	table.emplace("R13", 0x000D);
	table.emplace("R14", 0x000E);
	table.emplace("R15", 0x000F);

	table.emplace("SCREEN", 0x4000);
	table.emplace("KBD",    0x6000);
}

SymbolTable::~SymbolTable(){}

void SymbolTable::addEntry(string symbol, int adress){
	table.emplace(symbol, adress);
}

bool SymbolTable::contains(string symbol){
	return table.find(symbol) != table.end();
}

// Must be called after SymbolTable::contains or out_of_range is possible
int SymbolTable::GetAdress(string symbol){
	return table.at(symbol);
}