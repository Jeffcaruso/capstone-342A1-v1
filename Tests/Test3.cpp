//============================================================================
// Name        : Test2
// Test Desc.  : trivial test that is still using the 'student' code
// Author      : Jeffrey Caruso
// Date    	   : Fall 2023
//============================================================================

#include <gtest/gtest.h>
#include "Inc/Source1.h"

using namespace std;

TEST(Test1, ReturnHelloWorld)
{
	ASSERT_TRUE(HelloWorld());
}

TEST(Test2, TestFailure)
{
	ASSERT_TRUE(true); // to make it pass, change it from false to true.
}

TEST(Test3, TestPass)
{
	ASSERT_TRUE(true);
}
