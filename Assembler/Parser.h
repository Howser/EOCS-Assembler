#ifndef GUARD_PARSER_H
#define GUARD_PARSER_H

/* Header file for the parser module */ 
#include <string>
#include <fstream>
#include <vector>

enum CommandType{
	A_COMMAND,
	C_COMMAND,
	L_COMMAND
};

class Parser{
public:
	Parser(std::string path);
	~Parser();

	bool hasMoreCommands();		// True if there are more commands to parse
	void advance();				// Reads the next command from the input and makes it the current command
	CommandType commandType();	// Returns the type of the current command
	std::string symbol();		// Returns the symbol of the current command. Called only when commandType is A or L command
	std::string dest();			// Returns the dest mnemonic in the current C-command. Called only when commandType is C command
	std::string comp();			// Returns the comp mnemonic in the current C-command. Called only when commandType is C command
	std::string jump();			// Returns the jump mnemonic in the current C-command. Called only when commandType is C command
private:
	// Member functions
	void removeWhitespace(std::string& s); 

	// member variables
	std::vector<std::string> commands;
	std::vector<std::string>::iterator currentCommand;
};

#endif