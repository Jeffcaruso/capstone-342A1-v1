//============================================================================
// Name        : Test2
// Test Desc.  : trivial test that is still using the 'student' code
// Author      : Jeffrey Caruso
// Date    	   : Fall 2023
//============================================================================

#include <gtest/gtest.h>
#include "Inc/pokedex.h"

using namespace std;

TEST(Test3, LifecycleFor2PokemonEntries)
{
	//Make Pokedex class pdx
	Pokedex pdx;

	//string stream for output testing
	stringstream strs;

	//insert 2 Pokemon, Pikachu first
	pdx.insert("Pikachu");
	pdx.insert("Charmander");

	//check its size 2 as expected after 2 adds
	EXPECT_EQ(pdx.size(), 2);

	//verifying front and back (2 and only 2 entries present)
	EXPECT_EQ(pdx.at(0), pdx.front());
	EXPECT_EQ(pdx.at(1), pdx.back());

	//init str stream to empty
	strs.str("");
	//load output to str stream
	strs << pdx;
	//string of expected output for comparison
	string expectedOutput1 = "[Charmander, Pikachu]";
	//check output is expected result
	EXPECT_EQ(strs.str(), expectedOutput1);


	//now being erasing and verifying that is working as expected...
	//erase front (b/c alpha order, delete charamander)
	pdx.erase(0);
	EXPECT_EQ(pdx.front(), pdx.back());

	//set str stream to empty
	strs.str("");
	//load in output
	strs << pdx;
	//string of expected output for comparison
	string expectedOutput2 = "[Pikachu]";
	//check output is expected result
	EXPECT_EQ(strs.str(), expectedOutput2);
}
