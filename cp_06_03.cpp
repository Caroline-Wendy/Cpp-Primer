/*Programme from C++ Primer, By C.L.Wang*/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>

//#define  NDEBUG

using namespace std;

int _tmain(int argc, _TCHAR* argv[]){
	std::string word = "SB xiaomeng";
#ifndef NDEBUG
	if(word.size() < 100)
		std::cerr << "Error: " << __FILE__ << std::endl
		<< ": in function " << __FUNCTION__ << std::endl
		<< " at line " << __LINE__ << std::endl
		<< " Compiled on " << __DATE__ << std::endl
		<< " at " << __TIME__ << std::endl
		<< " Word read was \"" << word << "\": Length too short. " << std::endl;
#endif // !NDEBUG
}