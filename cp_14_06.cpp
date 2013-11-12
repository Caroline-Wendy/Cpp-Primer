/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.11.11
 *      Author: Caroline
 */

/*eclipse cdt*/

#include <iostream>
#include <functional>
#include <map>
#include <string>

using namespace std;

int add (int i, int j) { return i+j; }
auto mod = [](int i, int j) { return i%j; };
struct divide {
	int operator() (int denominator, int divisor) {
		return denominator / divisor;
	}
};

int main (void) {

	std::map<std::string, std::function<int (int, int)> > binops = {
			{"+", add},
			{"-", std::minus<int>()},
			{"/", divide()},
			{"*", [](int i, int j) { return i*j; }},
			{"%", mod}
	};

	std::cout << "10 + 5 = " <<  binops["+"] (10, 5) << std::endl;
	std::cout << "10 - 5 = " <<  binops["-"] (10, 5) << std::endl;
	std::cout << "10 / 5 = " <<  binops["/"] (10, 5) << std::endl;
	std::cout << "10 * 5 = " <<  binops["*"] (10, 5) << std::endl;
	std::cout << "10 % 5 = " <<  binops["%"] (10, 5) << std::endl;

	return 0;

}
