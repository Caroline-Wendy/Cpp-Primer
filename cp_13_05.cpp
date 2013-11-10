/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.7
 *      Author: Caroline
 */

#include <iostream>
#include <utility>

int main (void) {
	int i = 42;
	int &lr = i;
	int &&rr = i*42;
	const int &lr1 = i*42;
	int &&rr1 = 42;
	int &&rr2 = std::move(lr);
	std::cout << "i = " << i << std::endl;
	std::cout << "lr = " << lr << std::endl;
	std::cout << "rr = " << rr << std::endl;
	std::cout << "lr1 = " << lr1  <<std::endl;
	std::cout << "rr1  = " << rr1  << std::endl;
	std::cout << "rr2  = " << rr2  << std::endl;
}
