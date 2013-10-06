#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[]){

	/*range for C++11*/
	int ia[3][4] = {0};
	size_t cnt = 0;
	for(auto &row : ia){
		for(auto &col : row){
			col = cnt;
			++cnt;
		}
	}

	for(const auto &row : ia)
		for(const auto col : row)
			std::cout << col << std::endl;

	/*²âÊÔi++ºÍ++i*/
	int i=0, j;
	j = ++i;
	std::cout << " i = " << i << "\t" << " j = " << j << std::endl;
	j = i++;
	std::cout << " i = " << i << "\t" << " j = " << j << std::endl;

	/*²âÊÔ*iter++*/
	int t(0);
	std::vector<int> v;
	for(unsigned int i=0; i<10; ++i)
		v.push_back(++t);
	auto pbeg = v.begin();
	while(pbeg!=v.end() && *pbeg>=0 )
		std::cout << *pbeg++ << std::endl;


	return 0;
}

