#include "textbuddy.h"

//*****Attributes*****//

//Intitialise with some space prematurely for performance improvement
vector<string> textVector(30);

//*****Public Methods*****//

vector<string> TextBuddy::readVector() {
	return textVector;
}

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

bool TextBuddy::processCommand(string command) {
	if (command.compare("exit") == 0) {
		exitCommand();
		return true;
	} else if (command.compare("add") == 0) {
		addCommand();
		return false;
	} else if (command.compare("display") == 0) {
		displayCommand();
		return false;
	} else if (command.compare("clear") == 0) {
		clearCommand();
		return false;
	} else if (command.compare("delete") == 0) {
		deleteCommand();
		return false;
	} else if (command.compare("sort") == 0) {
		sortCommand();
		return false;
	} else if (command.compare("search") == 0) {
		searchCommand();
		return false;
	} else {
		rejectCommand();
		return false;
	}
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

void TextBuddy::sortCommand() {
	std::sort(textVector.begin(), textVector.end());
}

void TextBuddy::rejectCommand() {
	cout << "invalid command" << endl;
}

vector<string> TextBuddy::searchCommand() {
	string wordToFind;
	//grab rest of line
	cin >> wordToFind;

	vector<string> result;
	int foundCount = 1;

	for (unsigned int i = 0; i < textVector.size(); i++) {
		if (textVector.at(i).find(wordToFind) != string::npos) {
			cout << foundCount++ << ". " << textVector.at(i) << endl;
			result.push_back(textVector.at(i));
		}
	}

	/*for (int i = 0; i < result.size(); i++) {
		cout << result.at(i);
	}*/

	/*result.push_back(wordToFind);
	result.push_back("bicycle rider");*/

	return result;
}

//*****Private Methods*****//