/*Programme from C++ Primer, By C.L.Wang*/

#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <array>
#include <list>

using namespace std;

bool comp(const int i, const int j){
	return i>j;
}

int main(void) {
	std::array<int, 4> ai1 = {1, 3, 4, 5};
	std::list<int> lsti1;
	for(const auto& i : ai1)
		lsti1.push_front(i);
	std::array<int, 4> ai2 = {2, 6, 7, 8};
	std::list<int> lsti2;
	for(const auto& i : ai2)
		lsti2.push_front(i);

	lsti1.merge(lsti2, comp);

	for(const auto& i : lsti1)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;

}