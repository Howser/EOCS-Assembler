/* Main  */

#include "Code.h"
#include "Parser.h"
#include <iostream>
#include <bitset>
using namespace std;

bitset<16> decimalToBinary(int n);

int main(int argc, const char* argv[]){

	string filename = argv[1];
	size_t extension = filename.find(".asm");
	if (extension != string::npos){
		Parser p(filename);
		filename.erase(filename.find(".asm"));

		filename += ".hack";
		ofstream outfile(filename);
		while (p.hasMoreCommands()){
			if (p.commandType() == C_COMMAND){
				string c("111");
				c += comp(p.comp());
				c += dest(p.dest());
				c += jump(p.jump());	
				outfile << c << endl;
			} else if (p.commandType() == A_COMMAND){
				outfile << decimalToBinary(atoi(p.symbol().c_str())) << endl;
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