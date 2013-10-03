/* Parser module source file */

#include "Parser.h"
#include <iostream>
using namespace std;

// Loads the file into a vector
Parser::Parser(string path){
	ifstream file(path, ios::in);
	string s;
	while (file.good()){
		getline(file, s);
		removeWhitespace(s);
		if (!s.empty())
			commands.push_back(s);
	}
	file.close();
	currentCommand = commands.begin();
}

Parser::~Parser(){};

bool Parser::hasMoreCommands(){
	return (currentCommand != commands.end());
}

// Must be called after the command is parsed since currentCommand is initailized in the constructor
void Parser::advance(){
	currentCommand++;
}

CommandType Parser::commandType(){
	if (currentCommand->at(0) == '@'){
		return A_COMMAND;
	} else {
		return C_COMMAND;
	}
}

string Parser::symbol(){
	return currentCommand->substr(1, currentCommand->size());
}

string Parser::dest(){
	size_t s = currentCommand->find("=");
	if (s == string::npos)
		return "null";
	else 
		return currentCommand->substr(0, s);
}

string Parser::comp(){
	size_t s = currentCommand->find("=");
	size_t e = currentCommand->find(";");
	if (s!= string::npos)
		return currentCommand->substr(s+1, e-s);
	return currentCommand->substr(0, e);
}

string Parser::jump(){
	size_t s = currentCommand->find(";");
	if (s == string::npos)
		return "null";
	else 
		return currentCommand->substr(s+1);
}

void Parser::removeWhitespace(string& s){
	string::iterator i = s.begin();
	string newString;
	while (i != s.end()){
		if (*i == '/' && i+1 != s.end()){
			if (*(i+1) == '/')
				break;
		}
		if (*i != ' '){
			newString.push_back(*i);
		}
		++i;
	}
	s = newString;
}