/*Programme from C++ Primer, By C.L.Wang*/
/*Some examples from http://en.cppreference.com/w/cpp/container/array */
#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

int main(void) {

	/*array���÷�*/
	std::array<int, 3> ai = {1, 2, 3};
	std::array<std::string, 2> as = {std::string("a"), "b"};
	std::reverse_copy(ai.begin(), ai.end(), std::ostream_iterator<int>(std::cout, " ")); /*����*/
	for(auto& s : as)
		std::cout << s << " ";
	std::cout << std::endl;

	/*emplace���÷�*/
	std::array<int, 3> myarray = {10, 20, 30};
	std::vector<int> myvector;
	for(auto& i : myarray)
		myvector.push_back(i);
	auto it = myvector.emplace ( myvector.begin()+1, 100 );
	myvector.emplace ( it, 200 );
	myvector.emplace ( myvector.end(), 300 ); //ע��end��λ��[begin,end)
	std::cout << "myvector contains:";
	for (auto& x: myvector)
		std::cout << ' ' << x;
	std::cout << std::endl;

	/*��������*/
	std::vector<int> myvector2(myvector.cbegin(), myvector.cend());
	for (auto& x: myvector2)
		std::cout << ' ' << x;
	std::cout << std::endl;

	/*array��ʼ��*/
	std::array<int, 10> myarray3 = {10, 20, 30};
	for (auto& x: myarray3)
		std::cout << ' ' << x;
	std::cout << std::endl;

	return 0;

}