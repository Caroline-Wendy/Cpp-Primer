/*Programme from C++ Primer, By C.L.Wang*/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <new>
#include <typeinfo>

using namespace std;

int _tmain(int argc, _TCHAR* argv[]){

	/*go to ÓÃ·¨*/
	int j = 12;
	for(unsigned int i=0; i< 10; i++){
		std::cout << "i = " << i << std::endl;
		goto another;
	}
another:
	std::cout << "j = " << j << std::endl;

	string s = "file:///abc";
	s = s.substr(8,(s.length()-1));
	std::cout << "s = " << s << std::endl;

	/*try, catch*/
	int a, b;
	while(std::cin >> a >> b){
		try{
			if(a != b){
				throw runtime_error("hello");
			}
		}catch (runtime_error err){
			std::cout << err.what() << std::endl;
			break;
		}
	}

	return 0;

}