/*Programme from C++ Primer, By C.L.Wang*/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <cstdarg> // needed to use ellipses 

using namespace std;

// The ellipses must be the last parameter by others
double FindAverage(int nCount, ...) 
{ 
	long lSum = 0; 

	// We access the ellipses through a va_list, so let's declare one 
	va_list list; 

	// We initialize the va_list using va_start.  The first parameter is 
	// the list to initialize.  The second parameter is the last non-ellipse 
	// parameter. 
	va_start(list, nCount); 

	// Loop nCount times 
	for (int nArg=0; nArg < nCount; nArg++) 
		// We use va_arg to get parameters out of our ellipses 
			// The first parameter is the va_list we're using 
				// The second parameter is the type of the parameter 
					lSum += va_arg(list, int); 

	// Cleanup the va_list when we're done. 
	va_end(list); 

	return static_cast<double>(lSum) / nCount; 
} 

const string& shorterString(const string& s1, const string& s2){
	return s1.size() <= s2.size() ? s1 : s2;
}

int _tmain(int argc, _TCHAR* argv[]){
	
	/*const在指针的两处使用*/
	int a = 5;
	int b = 12;
	const int* ci = &a; //不能通过指针修改值
	int * const pi = &a; //不能修改指针指向的地址
	std::cout << "a = " << a << std::endl;

	/*编译器不会检查省略参数, 尽量避免使用*/
	cout << FindAverage(5, 1, 2, 3, 4, 5) << endl; 
	cout << FindAverage(6, 1, 2, 3, 4, 5, 6) << endl; 
	cout << FindAverage(6, 1.0, 2, 3, 4, 5, 6) << endl; //bad

	/*返回引用类型*/
	string s1 = "Hello";
	string s2 = "WorldYou";
	std::cout << shorterString(s1, s2) << std::endl;
}