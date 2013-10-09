/*Programme from C++ Primer, By C.L.Wang*/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[]){

	/*while的用法*/
	/*std::vector<int> v;
	int i;
	while (std::cin >> i)
	{
		v.push_back(i);
	}
	auto beg = v.begin();
	while (beg != v.end() && *beg >= 0)
	{
		++beg;
	}
	if(beg == v.end())
		std::cout << "They are all natural numbers. " << std::endl;*/

	/*for初始化类型必须相同*/
	for(double k=0, long i=0; i<10; i++){
		std::cout << k << std::endl;
	}

	return 0;

}