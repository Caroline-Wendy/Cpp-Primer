/*Programme from C++ Primer, By C.L.Wang*/

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <array>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

bool comp(const int& i, const int& j){
	return i > j;
}

int main(void) {
	
	/*map[subscript]*/
	std::map<std::string, size_t> word_count;
	std::string word;
	std::array<std::string, 9> aword = 
	{"boy", "girl", "ladyboy", "lady", "girl", "female", "lady", "boy", "queen"};
	std::array<std::string, 2> aexclude = {"boy", "girl"};
	std::set<std::string> exclude; 
	for(const auto& i : aexclude)
		exclude.insert(i);
	for(const auto& i : aword)
		if(exclude.find(i) == exclude.end())
			++word_count[i];
	/*while (std::cin >> word) 
		++word_count[word];*/
	for(const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times. " : " time. ") << std::endl;

	/*multiset*/
	std::vector<int> ivec;
	for (size_t i=0; i!=10; ++i) {
		ivec.push_back(i);
		ivec.push_back(i);
	}
	std::set<int> iset(ivec.begin(), ivec.end());
	std::multiset<int> miset(ivec.begin(), ivec.end());
	std::cout << ivec.size() << std::endl;
	std::cout << iset.size() << std::endl;
	std::cout << miset.size() << std::endl;

	/*自定义集合排列顺序*/
	multiset<int, decltype(comp)*> ims(&comp);
	for (size_t i=0; i!=10; ++i) {
		ims.insert(i);
	}
	std::cout << " comp(>) : ";
	for(const auto& i : ims)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;

}