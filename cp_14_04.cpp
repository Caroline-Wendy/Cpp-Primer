/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.11.6
 *      Author: C.L.Wang
 */

/*eclipse cdt*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct absInt {
	int operator () (int val) const {
		return val<0 ? -val : val;
	}
};

class PrintString {
public:
	PrintString (std::ostream &o = std::cout, char c = ' ') : os(o), sep(c) { }
	void operator() (const std::string &s) const { os << s << sep; }
private:
	std::ostream &os;
	char sep;
};

class LargerString {
public:
	bool operator() (const std::string& a, const std::string& b) {
		return a.size() > b.size();
	}
};

int main (void) {

	int i = -42;
	absInt absObj;
	int ui = absObj (i);
	std::cout << "ui = " << ui << std::endl;

	std::vector<std::string> sv = {"Ladyboy", "Girl", "Lady", "Women", "Pretty"};
	std::for_each(sv.begin(), sv.end(), PrintString(std::cout));
	std::cout << std::endl;
	std::stable_sort(sv.begin(), sv.end(),
			[](const std::string& a, const std::string& b){ return a.size()<b.size(); });
	std::for_each(sv.begin(), sv.end(), PrintString(std::cout));
	std::cout << std::endl;
	std::stable_sort(sv.begin(), sv.end(), LargerString());
	std::for_each(sv.begin(), sv.end(), PrintString(std::cout));
	std::cout << std::endl;
	std::stable_sort(sv.begin(), sv.end(), std::less<std::string>());
	std::for_each(sv.begin(), sv.end(), PrintString(std::cout));
	std::cout << std::endl;

	std::plus<int> intAdd;
	std::negate<int> intNegate;
	int sum = intAdd(10, 20);
	std::cout << "sum = " << sum << std::endl;
	sum = intNegate(intAdd(10, 20));
	std::cout << "sum = " << sum << std::endl;
	sum = intAdd(-10, intNegate(-10));
	std::cout << "sum = " << sum << std::endl;



    return 0;

}
