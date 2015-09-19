#include "textbuddy.h"

int main(int argc, char* argv[]) {
	TextBuddy library;

	if (library.hasNoFilenameArg(argc)) {
		return 1;
	}

	string filename = argv[1];

	library.loadFileIntoVector(filename);

	library.printWelcomeMessage();
	library.printCommandMessage();

	while (true) {
		string command;
		cin >> command;

		if (command.compare("exit") == 0) {
			library.exitCommand();
			return 0;  //exit program
		} else if (command.compare("add") == 0) {
			library.addCommand();
		} else if (command.compare("display") == 0) {
			library.displayCommand();
		} else if (command.compare("clear") == 0) {
			library.clearCommand();
		} else if (command.compare("delete") == 0) {
			library.deleteCommand();
		} else {
			library.rejectCommand();
		}

		library.printCommandMessage();
	}
}