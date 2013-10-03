/* Main  */

#include "Code.h"
#include "Parser.h"
#include "SymbolTable.h"
#include <iostream>
#include <bitset>
using namespace std;

bitset<16> decimalToBinary(int n);

int main(int argc, const char* argv[]){

	string filename = argv[1];
	size_t extension = filename.find(".asm");
	if (extension != string::npos){
		Parser p(filename);
		filename.erase(filename.find(".asm")); // remove the extension so we can create the new file with .hack instead

		// Generate Symbol table
		SymbolTable sTable = SymbolTable();
		int cAdress = 0;
		while (p.hasMoreCommands()){
			if (p.commandType() == L_COMMAND){
				sTable.addEntry(p.symbol(), cAdress);
			} else if (p.commandType() == A_COMMAND || p.commandType() == C_COMMAND) {
				++cAdress;
			}
			p.advance();
		}

		// Generate code
		filename += ".hack";
		ofstream outfile(filename);
		int nextRAMAdress = 16;
		p.reset();
		while (p.hasMoreCommands()){
			if (p.commandType() == C_COMMAND){

				string c("111");
				c += comp(p.comp());
				c += dest(p.dest());
				c += jump(p.jump());	
				outfile << c << endl;

			} else if (p.commandType() == A_COMMAND){
				string symbol = p.symbol();

				if (symbol.substr(0, 1).find_first_of("0123456789") != string::npos){ // If symbol starts with a digit.. it is a number
					outfile << decimalToBinary(atoi(p.symbol().c_str())) << endl;

				} else {  
					// else we need to find it in the symbol table
					if (!sTable.contains(symbol)){
						sTable.addEntry(symbol, nextRAMAdress);
						++nextRAMAdress;
					}
					outfile << decimalToBinary(sTable.GetAdress(symbol)) << endl;
				}
			}
			p.advance(); // if this is at the beginning of the loop the program will skip the first instruction
		}
		outfile.close();
	} else {
		cout << "Could not assemble program, incorrect file format/extension!" << endl;
		cout << "Exiting.. ";
	}
	return 0;
}

bitset<16> decimalToBinary(int n){
	return bitset<16>(n);
}