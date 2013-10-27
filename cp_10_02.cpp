/*Programme from C++ Primer, By C.L.Wang*/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <array>

using namespace std;

void biggies(std::vector<std::string> & words,
			 std::vector<std::string>::size_type sz,
			 std::ostream &os = std::cout, char c = ' ')
{
	std::for_each(words.begin(), words.end(), 
		[&os, c](const std::string& s){ os << s << c; });
}

/*mutable Lambda*/
void fcn3()
{
	size_t v1 = 42;
	auto f = [v1] () mutable { return ++v1; };
	v1 = 0;
	auto j = f();
	std::cout << " j = " << j << std::endl;
}

int main(void) {

	/*lambda*/
	size_t v1 = 42;
	auto f = [v1]{return v1;};
	v1 = 0;
	auto j = f();
	std::cout << " v1 = " << v1 << std::endl;
	std::cout << " j = " << j << std::endl;

	/*lambda capture by reference*/
	std::array<std::string, 6> as = {"boy", "girl", "baby", "woman", "man", "ladyboy"};
	std::vector<std::string> vs;
	for(const auto& i : as)
		vs.push_back(i);
	biggies(vs, 3);
	std::cout << std::endl;

	fcn3();

	/*trailing return type*/
	std::array<int, 6> ai = {1, -2, 3, -4, -5, -6};
	std::transform(ai.begin(), ai.end(), ai.begin(), 
		[] (int i) -> int {
			if (i<0)
				return -i;
			else
				return i;
			});
	for(const auto i : ai)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;

}