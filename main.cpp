#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>
#include "textbuddylib.h"

//namespaces
using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::endl;

void loadFileIntoVector(vector<string> * textVector, string filename) {
	std::fstream saveFile;
	string line;
	saveFile.open(filename, std::fstream::in);
	if (saveFile.is_open()) {
		while (std::getline(saveFile, line)) {
			(*textVector).push_back(line);
		}
	}
	saveFile.close();
}

void clearCommand(vector<string> * textVector) {
	(*textVector).clear();
}

void exitCommand(vector<string> * textVector, string filename) {
	std::fstream saveFile;
	saveFile.open(filename, std::fstream::out);
	for (int i = 0; i < (*textVector).size(); i++) {
		saveFile << (*textVector).at(i) << endl;
	}
	saveFile.close();
}

void displayCommand(vector<string> * textVector, string filename) {
	if ((*textVector).size() <= 0) {
		cout << filename << " is empty" << endl;
	} else { //C++ iterators textVector.begin() ... 
		for (int i = 0; i < (*textVector).size(); i++) {
			cout << i + 1 << ". " << (*textVector).at(i) << endl;
		}
	}
}

void addCommand(vector<string> * textVector, string* line) {
	//grab rest of line
	std::getline(cin, (*line));
	//strip leading whitespace
	(*line) = std::regex_replace((*line), std::regex("^ +"), "");
	(*textVector).push_back((*line));
}

void deleteCommand(vector<string> * textVector, string* data) {
	int index;
	cin >> index;
	string line = (*textVector).at(index - 1);
	(*textVector).erase((*textVector).begin() + index - 1);
	(*data) = line;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Please specify the filename" << endl;
		return 1;
	}

	string filename = argv[1];  //filename
	vector<string> textVector;  //vector to store lines from file

	//reserve some space prematurely for performance improvement
	textVector.reserve(30);

	loadFileIntoVector(&textVector, filename);

	cout << "Welcome to TextBuddy. " << filename << " is ready for use" << endl;
	cout << "Command: ";

	while (true) {
		string command;
		cin >> command;

		if (command.compare("exit") == 0) {
			exitCommand(&textVector, filename);
			//exit program
			return 0;
		} else if (command.compare("add") == 0) {
			string line;
			addCommand(&textVector, &line);
			cout << "added to " << filename << ": \"" << line << "\"" << endl;
		} else if (command.compare("display") == 0) {
			displayCommand(&textVector, filename);
		} else if (command.compare("clear") == 0) {
			clearCommand(&textVector);
			cout << "all content deleted from " << filename << endl;
		} else if (command.compare("delete") == 0) {
			string data;
			deleteCommand(&textVector, &data);
			cout << "deleted from " << filename << ": \"" << data << "\"" << endl;
		} else {
			cout << "invalid command" << endl;
		}

		cout << "Command: ";
	}
}