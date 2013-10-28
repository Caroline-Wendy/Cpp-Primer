/*Programme from C++ Primer, By C.L.Wang*/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>

using namespace std;

int main(void) {

	/*insert是插入在给定位置之前*/
	std::array<int, 4> ai = {1, 2, 3, 4};
	std::list<int> lst;
	for(const auto& i : ai)
		lst.push_back(i);
	lst.insert(++lst.begin(), 5);
	std::cout << "lst: ";
	for(const auto& i : lst)
		std::cout << i << " ";
	std::cout << std::endl;

	/*reverse迭代器*/
	std::array<int, 10> ai2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> vec;
	for(const auto& i : ai2)
		vec.push_back(i);
	std::sort(vec.begin(), vec.end());
	std::cout << "sort order: ";
	for(const auto& i : vec)
		std::cout << i << " ";
	std::cout << std::endl;
	std::sort(vec.rbegin(), vec.rend());
	std::cout << "sort reverse: ";
	for(const auto& i : vec)
		std::cout << i << " ";
	std::cout << std::endl;

	/*string类型的问题*/
	std::string line("FIRST,MIDDLE,LAST");
	auto comma = std::find(line.cbegin(), line.cend(), ',');
	std::cout << std::string(line.cbegin(), comma) << std::endl;
	auto rcomma = std::find(line.crbegin(), line.crend(), ',');
	std::cout << std::string(line.crbegin(), rcomma) << std::endl;
	std::cout << std::string(rcomma.base(), line.cend()) << std::endl; //正序

	return 0;

}