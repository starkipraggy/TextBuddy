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

	void loadFileIntoVector(string filename);

	// Print Messages
	void printWelcomeMessage(string filename);
	void printCommandMessage();
	
	// Command methods
	void clearCommand();
	void exitCommand(string filename);
	void displayCommand(string filename);
	void addCommand();
	void deleteCommand(string* data);

private:
	vector<string> textVector;
	string filename;
};
