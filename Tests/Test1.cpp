//============================================================================
// Name        : Test1
// Test Desc.  : Test that the methods to determine empty are correct
//				 	(coverage for old test 1 method) the 'student' code
// Author      : Jeffrey Caruso
// Date    	   : Fall 2023
//============================================================================

#include <gtest/gtest.h>
#include "Inc/Source1.h"
#include "Inc/pokedex.h"

using namespace std;

TEST(Test1, CheckSize4Empty)
{
	//Make Pokedex class pdx
	Pokedex pdx;

	//check it starts with size 0 as expected
	EXPECT_EQ(pdx.size(), 0);
}

TEST(Test1, CheckEmpty4Empty)
{
	//Make Pokedex class pdx
	Pokedex pdx;

	//Check empty method. expecting it to be empty
	EXPECT_EQ(pdx.empty(), 0);
}

TEST(Test1, CheckOutStr4Empty)
{	
	//Make Pokedex class pdx
	Pokedex pdx;

	//check output is an empty set "[]" as expected
	ostringstream outStrStr;
	outStrStr << pdx;
	EXPECT_EQ(outStrStr.str(), "[]");
}
