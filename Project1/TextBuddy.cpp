#include "textbuddy.h"

//Intitialise with some space prematurely for performance improvement
vector<string> textVector(30);

bool TextBuddy::hasNoFilenameArg(int argc) {
	if (argc < 2) {
		cout << "Please specify the filename" << endl;
		return true;
	} else {
		return false;
	}
}

void TextBuddy::printWelcomeMessage() {
	cout << "Welcome to TextBuddy. " << filename << " is ready for use" << endl;
}

void TextBuddy::printCommandMessage() {
	cout << "Command: ";
}

void TextBuddy::loadFileIntoVector(string fileToOpen) {
	std::fstream saveFile;
	string line;
	saveFile.open(fileToOpen, std::fstream::in);
	if (saveFile.is_open()) {
		while (std::getline(saveFile, line)) {
			textVector.push_back(line);
		}
	}
	saveFile.close();
	filename = fileToOpen;
}

void TextBuddy::clearCommand() {
	textVector.clear();
	cout << "all content deleted from " << filename << endl;
}

void TextBuddy::exitCommand() {
	std::fstream saveFile;
	saveFile.open(filename, std::fstream::out);
	for (unsigned int i = 0; i < textVector.size(); i++) {
		saveFile << textVector.at(i) << endl;
	}
	saveFile.close();
}

void TextBuddy::displayCommand() {
	if (textVector.size() <= 0) {
		cout << filename << " is empty" << endl;
	} else { 
		//C++ iterators textVector.begin() ... 
		for (unsigned int i = 0; i < textVector.size(); i++) {
			cout << i + 1 << ". " << textVector.at(i) << endl;
		}
	}
}

void TextBuddy::addCommand() {
	string line;

	//grab rest of line
	std::getline(cin, line);

	//strip leading whitespace
	line = std::regex_replace(line, std::regex("^ +"), "");
	textVector.push_back(line);
	cout << "added to " << filename << ": \"" << line << "\"" << endl;
}

void TextBuddy::deleteCommand() {
	int index;
	cin >> index;
	string line = textVector.at(index - 1);
	textVector.erase(textVector.begin() + index - 1);
	cout << "deleted from " << filename << ": \"" << line << "\"" << endl;
}

void TextBuddy::rejectCommand() {
	cout << "invalid command" << endl;
}