/* Main  */

#include "Code.h"
#include "Parser.h"
#include <iostream>
#include <bitset>
using namespace std;

bitset<16> decimalToBinary(int n);

int main(int argc, const char* argv[]){
	string filename = argv[1];
	Parser p(filename);

	filename.erase(filename.find(".asm"));

	filename += ".hack";
	ofstream outfile(filename);
	while (p.hasMoreCommands()){
		string c;
		if (p.commandType() == C_COMMAND){
			c = ("111");
			c += comp(p.comp());
			c += dest(p.dest());
			c += jump(p.jump());
			outfile << c << endl;
		} else if (p.commandType() == A_COMMAND){
			outfile << decimalToBinary(atoi(p.symbol().c_str())) << endl;
		}
		
		p.advance();
	}
	outfile.close();
	system("pause");
	return 0;
}

bitset<16> decimalToBinary(int n){
	
	return bitset<16>(n);
}