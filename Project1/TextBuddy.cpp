#include "textbuddy.h"

//Vector to store lines from file. Reserve some space prematurely for performance improvement
vector<string> textVector(30);

void TextBuddy::printWelcomeMessage(string filename) {
	cout << "Welcome to TextBuddy. " << filename << " is ready for use" << endl;
}

void TextBuddy::printCommandMessage() {
	cout << "Command: ";
}

void TextBuddy::loadFileIntoVector(string filename) {
	std::fstream saveFile;
	string line;
	saveFile.open(filename, std::fstream::in);
	if (saveFile.is_open()) {
		while (std::getline(saveFile, line)) {
			textVector.push_back(line);
		}
	}
	saveFile.close();
}

void TextBuddy::clearCommand() {
	textVector.clear();
}

void TextBuddy::exitCommand(string filename) {
	std::fstream saveFile;
	saveFile.open(filename, std::fstream::out);
	for (unsigned int i = 0; i < textVector.size(); i++) {
		saveFile << textVector.at(i) << endl;
	}
	saveFile.close();
}

void TextBuddy::displayCommand(string filename) {
	if (textVector.size() <= 0) {
		cout << filename << " is empty" << endl;
	} else { 
		//C++ iterators textVector.begin() ... 
		for (unsigned int i = 0; i < textVector.size(); i++) {
			cout << i + 1 << ". " << textVector.at(i) << endl;
		}
	}
}

void TextBuddy::addCommand(string* line) {
	//grab rest of line
	std::getline(cin, (*line));

	//strip leading whitespace
	(*line) = std::regex_replace((*line), std::regex("^ +"), "");
	textVector.push_back((*line));
}

void TextBuddy::deleteCommand(string* data) {
	int index;
	cin >> index;
	string line = textVector.at(index - 1);
	textVector.erase(textVector.begin() + index - 1);
	(*data) = line;
}