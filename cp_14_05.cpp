/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.11.11
 *      Author: Caroline
 */

/*eclipse cdt*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class PrintString {
public:
	PrintString (std::ostream &o = std::cout, char c = ' ') : os(o), sep(c) { }
	void operator() (const std::string &s) const { os << s << sep; }
private:
	std::ostream &os;
	char sep;
};

/*Function Predicate*/
bool isLarger (const std::string &s1, const std::string &s2) {
	return s1.size() > s2.size();
}

/*Function Object*/
class LargerString {
public:
	bool operator() (const std::string& a, const std::string& b) {
		return a.size() > b.size();
	}
};

int main (void) {

	std::vector<std::string> sv = {"Beauty", "Girl", "Lady", "Women", "Pretty"};

	std::stable_sort(sv.begin(), sv.end(), isLarger);
	std::cout << "Function Predicate : ";
	std::for_each(sv.begin(), sv.end(), PrintString(std::cout));
	std::cout << std::endl;

	std::stable_sort(sv.begin(), sv.end(),
			[](const std::string& s1, const std::string& s2){ return s1.size()>s2.size(); });
	std::cout << "Lambda Expression Predicate : ";
	std::for_each(sv.begin(), sv.end(), PrintString(std::cout));
	std::cout << std::endl;

	bool (*pf) (const std::string &s1, const std::string &s2);
	pf = &isLarger;
	std::stable_sort(sv.begin(), sv.end(), *pf);
	std::cout << "Function Pointer Predicate : ";
	std::for_each(sv.begin(), sv.end(), PrintString(std::cout));
	std::cout << std::endl;

	std::stable_sort(sv.begin(), sv.end(), LargerString());
	std::cout << "Function Object Predicate : ";
	std::for_each(sv.begin(), sv.end(), PrintString(std::cout));
	std::cout << std::endl;


	std::stable_sort(sv.begin(), sv.end(), std::greater<std::string>());
	std::cout << "Library-Defined Function Object Predicate : ";
	std::for_each(sv.begin(), sv.end(), PrintString(std::cout));
	std::cout << std::endl;

    return 0;

}


