#include "gtest/gtest.h"
#include<string>


class TextBuddy;
using namespace std;
TextBuddy test;

TEST(SearchTest,words)
{	
	//checking a word which occurs in MULTIPLE sentences
	test.Add("Hello");
	test.Add("Hello World");
	test.Add("This is unit testing");
	test.Add("Hello Kitty");
	string result=test.Search("Hello");
	ASSERT_EQ("Hello Hello World Hello Kitty",result);
	
	//checking a word which occurs in a sentence only ONCE
	result=test.Search("World");
	ASSERT_EQ("Hello World",result);

	//checking a word which occurs in NO sentence
	result=test.Search("Error");
	ASSERT_EQ("",result);
}
	TEST(SortTest,AlphaSort)
	{
		//checking normal sorting function
		string result=test.Sort();
		ASSERT_EQ("Hello Hello Kitty Hello World This is unit testing",result);
		
		//sorting empty vector and checking
		test.Clear();
		result=test.Sort();
		ASSERT_EQ("",result);
	}
		
	
void runTest(int argument_count, char** argument_vars)

{
  
//initialize GTest
testing::InitGoogleTest(&argument_count, argument_vars);

RUN_ALL_TESTS();

//pause the program after all the testing
std::getchar();

}


	
	
	