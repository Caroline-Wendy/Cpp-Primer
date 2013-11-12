/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.11.11
 *      Author: Caroline
 */

/*eclipse cdt*/

#include <iostream>
#include <stdexcept>
#include <cstddef>

using namespace std;

class SmallInt {
public:
	SmallInt(int i = 0) : val(i) { //int -> SmallInt
		if(i<0 || i>255)
			throw std::out_of_range("Bad SmallInt value");
		std::cout << "Hello, girl, this is int to SmallInt. " << std::endl;
	}
	explicit operator int() const { //SmallInt -> int, 显示
		std::cout << "Hello, girl, this is SmallInt to int. " << std::endl;
		return val;
	}
private:
	std::size_t val;
};

int main (void) {

	SmallInt si;
	si = 4;
	SmallInt si1 = 3.14;
	while(static_cast<int>(si1)) { //使用条件
		std::cout << "this is a condition" << std::endl;
		break;
	}

	return 0;

}
