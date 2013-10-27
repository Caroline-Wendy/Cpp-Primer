/*Programme from C++ Primer, By C.L.Wang*/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <array>

using namespace std;

bool isShorter(const std::string& s1, const std::string& s2) {
	return s1.size() < s2.size();
}

/*返回单词的复数形式*/
std::string make_plural(size_t ctr, const std::string& word,
						const std::string& ending){
							
	return (ctr>1) ? word+ending : word;
}

int main(void) {

	std::array<std::string, 11> as = 
	{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle", "fox"};
	std::vector<std::string> words;
	for(const auto& i : as)
		words.push_back(i);
	std::sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	std::stable_sort(words.begin(), words.end(), isShorter);
	for(const auto& i : words)
		std::cout << i << " ";
	std::cout << std::endl;
	std::vector<std::string>::size_type sz = 4;
	auto wc = std::find_if(words.begin(), words.end(), 
		[sz](const std::string &a)
			{ return a.size() >= sz;}
	);
	auto count = words.end() - wc;
	std::cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer " << std::endl;

	return 0;

}