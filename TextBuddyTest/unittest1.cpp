#include "stdafx.h"
#include "CppUnitTest.h"
#include "textbuddy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextBuddyTest
{		
	TEST_CLASS(AddTaskTest) {
	private:
		TextBuddy library;

	public:
		TEST_METHOD(AddTask) {
			std::istringstream spoofInput("some blah\nno blah\nvery blah");
			cin.rdbuf(spoofInput.rdbuf());

			for (int i = 0; i < 3; i++) {
				library.addCommand();
			}

			vector<string> expectedResult = {"some blah", "no blah", "very blah"};

			Assert::IsTrue(expectedResult == library.readVector());
		}
	};

	TEST_CLASS(SortTaskTest) {
	private:
		TextBuddy library;
	
	public:
		TEST_METHOD(SortTask) {
			std::istringstream spoofInput("zambot\ntrider\ndaitarn\n");
			cin.rdbuf(spoofInput.rdbuf());

			for (int i = 0; i < 3; i++) {
				library.addCommand();
			}

			library.sortCommand();

			vector<string> expectedResult = {"daitarn", "trider", "zambot"};

			Assert::IsTrue(expectedResult == library.readVector());
		}
	};

	TEST_CLASS(ClearTaskTest) {
	private:
		TextBuddy library;

	public:
		TEST_METHOD(ClearTask) {
			std::istringstream spoofInput("zambot\ntrider\ndaitarn\n");
			cin.rdbuf(spoofInput.rdbuf());

			for (int i = 0; i < 3; i++) {
				library.addCommand();
			}

			library.clearCommand();

			vector<string> expectedResult = {};

			Assert::IsTrue(expectedResult == library.readVector());
		}
	};

	TEST_CLASS(DeleteTaskTest) {
	private:
		TextBuddy library;
		std::istringstream spoofInput;

	public:
		TEST_METHOD_INITIALIZE(Startup) {
			spoofInput.str("zambot\ntrider\ndaitarn\n");
			cin.rdbuf(spoofInput.rdbuf());

			for (int i = 0; i < 3; i++) {
				library.addCommand();
			}
		}

		TEST_METHOD(DeleteFirstTask) {
			spoofInput.str("1\n");
			library.deleteCommand();

			vector<string> expectedResult = {"trider", "daitarn"};

			Assert::IsTrue(expectedResult == library.readVector());
		}

		TEST_METHOD(DeleteMiddleTask) {
			spoofInput.str("2\n");
			library.deleteCommand();

			vector<string> expectedResult = { "zambot", "daitarn" };

			Assert::IsTrue(expectedResult == library.readVector());
		}

		TEST_METHOD(DeleteLastTask) {
			spoofInput.str("3\n");
			library.deleteCommand();

			vector<string> expectedResult = { "zambot", "trider" };

			Assert::IsTrue(expectedResult == library.readVector());
		}

		TEST_METHOD(DeleteInvalidTask) {
			spoofInput.str("0\n");
			auto deleteInvalidIndex = [this] {library.deleteCommand(); };
			Assert::ExpectException<std::out_of_range>(deleteInvalidIndex);
		}

		TEST_METHOD(DeleteUntilEmpty) {
			spoofInput.str("1\n1\n1\n");

			for (int i = 0; i < 3; i++) {
				library.deleteCommand();
			}

			vector<string> expectedResult = {};

			Assert::IsTrue(expectedResult == library.readVector());
		}
	};

	TEST_CLASS(SearchTaskTest) {
	private:
		TextBuddy library;
		std::istringstream spoofInput;

	public:
		TEST_METHOD_INITIALIZE(Standby) {
			cin.rdbuf(spoofInput.rdbuf());
			spoofInput.str("So zetta slow\nAttention all yoctograms!\nslow poke\n");

			for (int i = 0; i < 3; i++) {
				library.addCommand();
			}
		}

		TEST_METHOD(SearchTasks) {
			spoofInput.str("slow\n");

			vector<string> obtainedResult = library.searchCommand();

			vector<string> expectedResult = {"So zetta slow", "slow poke"};

			Assert::IsTrue(expectedResult == obtainedResult);
		}
	};
}