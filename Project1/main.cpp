#include "textbuddy.h"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Please specify the filename" << endl;
		return 1;
	}

	TextBuddy library;

	string filename = argv[1];  //filename
	

	library.loadFileIntoVector(filename);

	library.printWelcomeMessage(filename);
	library.printCommandMessage();

	while (true) {
		string command;
		cin >> command;

		if (command.compare("exit") == 0) {
			library.exitCommand(filename);
			
			return 0;  //exit program
		} else if (command.compare("add") == 0) {
			string line;
			library.addCommand();
		} else if (command.compare("display") == 0) {
			library.displayCommand(filename);
		} else if (command.compare("clear") == 0) {
			library.clearCommand();
			cout << "all content deleted from " << filename << endl;
		} else if (command.compare("delete") == 0) {
			string data;
			library.deleteCommand(&data);
			cout << "deleted from " << filename << ": \"" << data << "\"" << endl;
		} else {
			cout << "invalid command" << endl;
		}

		library.printCommandMessage();
	}
}