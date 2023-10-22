//============================================================================
// Name        : Source1
// Test Desc.  : Code for the tests to accesss to demo accessing student code file(S).
// Author      : Jeffrey Caruso
// Date    	   : Fall 2023
//============================================================================

#include <iostream>
#include "Inc/Source1.h"


bool HelloWorld(void)
{
	 std::cout << "Hello World!\r\n";

	 if(HELLO_WORLD==10)
	 {
		 std::cout << "Hello World = 10\r\n";
	 }		
	 else
	 {
		 return false;
	 }
	 return true;
}


