#include "textbuddy.h"

int main(int argc, char* argv[]) {
	TextBuddy library;

	if (library.hasNoFilenameArg(argc)) {
		return 1;
	}

	string filename = argv[1];
	library.loadFileIntoVector(filename);
	library.printWelcomeMessage();

	while (true) {
		library.printCommandMessage();

		string command;
		cin >> command;

		bool isExitCommand = library.processCommand(command);

		if (isExitCommand) {
			return 0;
		}
	}
}