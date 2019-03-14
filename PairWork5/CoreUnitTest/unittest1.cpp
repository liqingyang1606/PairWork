#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include "..\\PairWork5\\FileInput.h"
#include "..\\PairWork5\\wordHandler.h"
#include <vector>
#include <string>
#include <exception>
using namespace std;

namespace CoreUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			FileInput fin;
			fin.readFile("D:\\word_chain\\01.txt");
			wordHandler wh(fin);
			char *words[20];
			vector<string> result;
			wh.gen_chain_word(words, 0, result, 0, 0, false);
			Assert::IsTrue(result.at(0) == "apple");
			Assert::IsTrue(result.at(1) == "elephant");
			Assert::IsTrue(result.at(2) == "toad");
		}

		TEST_METHOD(TestMethod2) {
			FileInput fin;
			fin.readFile("D:\\word_chain\\02.txt");
			wordHandler wh(fin);
			char *words[20];
			vector<string> result;
			wh.gen_chain_char(words, 0, result, 0, 0, false);
			Assert::IsTrue(result.at(0) == "pseudonym");
			Assert::IsTrue(result.at(1) == "moon");
		}

		TEST_METHOD(TestMethod3) {//wrong
			FileInput fin;
			fin.readFile("D:\\word_chain\\03.txt");
			wordHandler wh(fin);
			char *words[20];
			vector<string> result;
			wh.gen_chain_word(words, 0, result, 0, 0, true);
			Assert::IsTrue(result.at(0) == "table");
			Assert::IsTrue(result.at(1) == "element");
			Assert::IsTrue(result.at(2) == "teach");
			//Assert::IsTrue(result.size() == 4);
			//Assert::IsTrue(result.at(3) == "heaven");
		}

		TEST_METHOD(TestMethod4) {
			// to test the function 'meet_req()'
			vector<string> words;
			words.push_back("leaf");
			words.push_back("fox");
			FileInput fin;
			fin.readFile("D:\\word_chain\\02.txt");
			wordHandler wh(fin);
			Assert::IsTrue( wh.meet_req('l', 0, words) );
			Assert::IsTrue(wh.meet_req(0, 'x', words));
			Assert::IsTrue(wh.meet_req('l', 'x', words));
			Assert::IsFalse(wh.meet_req('a', 0, words));
		}

		TEST_METHOD(TestMethod5) {
			FileInput fin;
			fin.readFile("D:\\word_chain\\02.txt");
			wordHandler wh(fin);
			char *words[20];
			vector<string> result;
			wh.gen_chain_word(words, 0, result, 'l', 0, false);
			Assert::IsTrue(result[0] == "leaf");
			Assert::IsTrue(result[1] == "fox");
		}

		TEST_METHOD(TestMethod6) {
			FileInput fin;
			fin.readFile("D:\\word_chain\\04.txt");
			wordHandler wh(fin);
			char *words[20];
			vector<string> result;
			wh.gen_chain_word(words, 0, result, '\0', '\0', false);
			Assert::IsTrue(result[0] == "algebra");
			Assert::IsTrue(result[1] == "apple");
			Assert::IsTrue(result[2] == "elephant");
			Assert::IsTrue(result.size() == 3);
		}
	};
}