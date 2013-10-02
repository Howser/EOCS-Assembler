/* Source file for code module 

This module is implemented as functions only instead of a class
Because there aren't any member variables or state to keep track of

*/ 

#include "Code.h"

using namespace std;

string dest(string m){
	string rs;
	if (m == "null")
		rs = "000";
	else if (m == "M")
		rs = "001";
	else if (m == "D")
		rs = "010";
	else if (m == "MD")
		rs = "011";
	else if (m == "A")
		rs = "100";
	else if (m == "AM")
		rs = "101";
	else if (m == "AD")
		rs = "110";
	else if (m == "AMD")
		rs = "111";
	else 
		rs = "ERROR";
	return rs;
}

string comp(string m){
	string rs;
	 if (m == "0")
		 rs = "0101010";
	 else if (m == "1")
		 rs = "0111111";
	 else if (m == "-1")
		 rs = "0111010";
	 else if (m == "D")
		 rs = "0001100";
	 else if (m == "A")
		 rs = "0110000";
	 else if (m == "!D")
		 rs = "0001111";
	 else if (m == "!A")
		 rs = "0110001";
	 else if (m == "-D")
		 rs = "0001111";
	 else if (m == "-A")
		 rs = "0110011";
	 else if (m == "D+1")
		 rs = "0011111";
	 else if (m == "A+1")
		 rs = "0110111";
	 else if (m == "D-1")
		 rs = "0001110";
	 else if (m == "A-1")
		 rs = "0110010";
	 else if (m == "D+A")
		 rs = "0000010";
	 else if (m == "D-A")
		 rs = "0010011";
	 else if (m == "A-D")
		 rs = "0000111";
	 else if (m == "D&A")
		 rs = "0000000";
	 else if (m == "D|A")
		 rs = "0010101";
	 else if (m == "M")
		 rs = "1110000";
	 else if (m == "!M")
		 rs = "1110001";
	 else if (m == "-M")
		 rs = "1110011";
	 else if (m == "M+1")
		 rs = "1110111";
	 else if (m == "M-1")
		 rs = "1110010";
	 else if (m == "D+M")
		 rs = "1000010";
	 else if (m == "D-M")
		 rs = "1010011";
	 else if (m == "M-D")
		 rs = "1000111";
	 else if (m == "D&M")
		 rs = "1000000";
	 else if (m == "D|M")
		 rs = "1010101";
	 else 
		 rs = "ERROR";
	 return rs;
}

string jump(string m){
	string rs;
	if (m == "null")
		rs = "000";
	else if (m == "JGT")
		rs = "001";
	else if (m == "JEQ")
		rs = "010";
	else if (m == "JGE")
		rs = "011";
	else if (m == "JLT")
		rs = "100";
	else if (m == "JNE")
		rs = "101";
	else if (m == "JLE")
		rs = "110";
	else if (m == "JMP")
		rs = "111";
	else 
		rs = "ERROR";
	return rs;
}