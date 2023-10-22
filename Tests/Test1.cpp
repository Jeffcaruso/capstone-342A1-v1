//============================================================================
// Name        : Test2
// Test Desc.  : trivial test that is still using the 'student' code
// Author      : Jeffrey Caruso
// Date    	   : Fall 2023
//============================================================================

#include <gtest/gtest.h>
#include "Inc/Source1.h"
#include "Inc/pokedex.h"

using namespace std;

TEST(Test1, CheckSize4Empty)
{
	//ASSERT_TRUE(HelloWorld());
	Pokedex pdx;

	//check it starts empty as expected
	EXPECT_EQ(pdx.size(), 0);
	// EXPECT_EQ(pdx.empty(), 0);

	// ostringstream outStrStr;
	// outStrStr << pdx;
	// EXPECT_EQ(outStrStr.str(), "[]");

}

TEST(Test1, CheckEmpty4Empty)
{
	//ASSERT_TRUE(HelloWorld());
	Pokedex pdx;

	//check it starts empty as expected
	//EXPECT_EQ(pdx.size(), 0);
	EXPECT_EQ(pdx.empty(), 0);

	// ostringstream outStrStr;
	// outStrStr << pdx;
	// EXPECT_EQ(outStrStr.str(), "[]");

}

TEST(Test1, CheckOutStr4Empty)
{
	//ASSERT_TRUE(HelloWorld());
	Pokedex pdx;

	//check it starts empty as expected
	// EXPECT_EQ(pdx.size(), 0);
	// EXPECT_EQ(pdx.empty(), 0);

	ostringstream outStrStr;
	outStrStr << pdx;
	EXPECT_EQ(outStrStr.str(), "[]");

}



// TEST(Test1, TestFailure)
// {
// 	ASSERT_TRUE(true); // to make it pass, change it from false to true.
// }

// TEST(Test1, TestPass)
// {
// 	ASSERT_TRUE(true);
// }
