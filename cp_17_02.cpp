/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.12.9
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

int main()
{
	std::bitset<13> b1(0xbeef); //1011(b) 1110(e) 1110(e) 1111(f)
	std::cout << b1 << std::endl;

	std::bitset<20> b2(0xbeef);
	std::cout << b2 << std::endl;

	std::bitset<8> b3("1110"); //string类型初始化
	std::cout << b3 << std::endl;

	return 0;
}
