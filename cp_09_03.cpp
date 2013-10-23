/*Programme from C++ Primer, By C.L.Wang*/

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	/*vector的内存分配*/
	std::vector<int> ivec;
	std::cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << std::endl;
	for(std::vector<int>::size_type ix=0; ix!=24; ix++)
		ivec.push_back(ix);
	ivec.reserve(50);
	std::cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << std::endl;
	while(ivec.size() != ivec.capacity())
		ivec.push_back(0);
	std::cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << std::endl;
	ivec.push_back(42);
	std::cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << std::endl;
	ivec.shrink_to_fit();
	std::cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << std::endl;
	return 0;

}
