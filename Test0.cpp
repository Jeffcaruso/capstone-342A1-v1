//============================================================================
// Name        : Test1
// Test Desc.  : Test that the methods to determine empty are correct
//				 	(coverage for old test 1 method) the 'student' code
// Author      : Jeffrey Caruso
// Date    	   : Fall 2023
//============================================================================

#include <gtest/gtest.h>
#include "applib/pokedex.h"

using namespace std;

TEST(Test0, TrivialTest)
{
	//Make Pokedex class pdx
    //test the build
	Pokedex pdx;

	//always true
	EXPECT_EQ(0, 0);
}