/*Programme from C++ Primer, By C.L.Wang*/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <array>
#include <forward_list>

using namespace std;

int main(void) {

	/*deque的用法*/
	std::deque<int> mydeque;
	mydeque.push_back(1);
	mydeque.push_back(2);
	mydeque.push_front(3);
	for(const auto&i : mydeque)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << "mydeque[0] = " << mydeque[0] << std::endl;

	/*emplace的用法*/
	std::vector<std::string> vec;
	vec.emplace_back("Hello"); // moves
	std::string s = " World!";
	vec.emplace_back(s); //copy
	for(const auto& i : vec)
		std::cout << i << " ";
	std::cout << std::endl;

	/*向前插入*/
	std::list<string> lst;
	auto iter = lst.begin();
	std::array<string, 5> as = {"Girl", "Boy", "Woman", "Man", "Baby"};
	for(const auto& i : as)
		iter = lst.insert(iter, i);
	for(const auto& i : lst)
		std::cout << i << " ";
	std::cout << std::endl;

	/*front&back*/
	auto val1 = *as.begin();
	auto val2 = as.back();
	std::cout << "*as.begin() = " << val1 << std::endl;
	std::cout << "as.back() = " << val2 << std::endl;

	/*forward_list示例*/
	std::array<int, 11> ai = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	forward_list<int> flst;
	for(auto& i : ai)
		flst.push_front(i);
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()){
		if(*curr % 2)
			curr = flst.erase_after(prev);
		else{
			prev = curr;
			++curr;
		}
	}
	for(const auto& i : flst)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;

}