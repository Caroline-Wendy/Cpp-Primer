/*Programme from C++ Primer, By C.L.Wang*/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

size_t count_calls(){
	static size_t ctr = 0;
	return ++ctr;
}

void reset(int *ip){
	*ip = 121;
	ip = 0;
}

string::size_type find_char(const std::string &s, char c, 
							string::size_type &occurs)
{
	auto ret = s.size();
	occurs = 0;
	for(decltype(ret) i=0; i != s.size(); ++i){
		if(s[i] == c){
			if(ret == s.size())
				ret = i;
			++occurs;
		}
	}
	return ret;
}

int _tmain(int argc, _TCHAR* argv[]){
	
	for(size_t i=0; i != 10; ++i)
		std::cout << count_calls() << std::endl;
	
	int k=42;
	reset(&k);
	std::cout << "k = " << k << std::endl;

	std::string s = "afeabceaccsdc";
	unsigned int ctr;
	auto index = find_char(s, 'c', ctr);
	std::cout << " index = " << index << " ctd = " << ctr <<std::endl;

	return 0;

}