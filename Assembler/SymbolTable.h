#ifndef GUARD_SYMBOL_TABLE_H
#define GUARD_SYMBOL_TABLE_H

/* SymbolTable header file */ 

#include <string>
#include <map>

class SymbolTable{
public:
	SymbolTable();
	~SymbolTable();

	void addEntry(std::string symbol, int adress);	// Adds the pain (symbol, adress) to the table
	bool contains(std::string symbol);				// True if the symbol exists in the table
	int GetAdress(std::string symbol);				// Returns the adress associated with the symbol

private:
	std::map<std::string, int> table;
};

#endif