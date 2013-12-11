/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.12.9
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

template<typename T>
struct myclass{
	void print() { std::cout << "myclass!" << std::endl; }
};

int main(void)
{
	myclass<double> mcd;
	mcd.print();

	myclass <int> mci;
	mci.print();

	return 0;
}
