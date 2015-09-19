#include "stdafx.h"
#include "CppUnitTest.h"
#include "textbuddy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextBuddyTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(AddTask) {
			std::istringstream spoofInput("some blah\nno blah\nvery blah");
			cin.rdbuf(spoofInput.rdbuf());

			vector<string> expectedResult = {"some blah", "no blah", "very blah"};

			TextBuddy library;
			for (int i = 0; i < 3; i++) {
				library.processCommand("add");
			}

			for (int i = 0; i < 3; i++) {
				string blah = library.readVector().at(i);
				Logger::WriteMessage(blah.c_str());
			}
			
			Assert::IsTrue(expectedResult == library.readVector());
		}

	};
}