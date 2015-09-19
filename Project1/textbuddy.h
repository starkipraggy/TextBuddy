#ifndef __TEXTBUDDY_INCLUDED__
#define __TEXTBUDDY_INCLUDED__

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>

//namespaces
using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::endl;

class TextBuddy {

public:

	bool hasNoFilenameArg(int argc);
	void loadFileIntoVector(string filename);

	// Print Messages
	void printWelcomeMessage();
	void printCommandMessage();

	bool processCommand(string command);
	vector<string> readVector();

private:
	vector<string> textVector;
	string filename;

	// Command methods
	void clearCommand();
	void exitCommand();
	void displayCommand();
	void addCommand();
	void deleteCommand();
	void sortCommand();
	void rejectCommand();

};

#endif