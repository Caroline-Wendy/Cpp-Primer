/*From C++ Primer By C.L.Wang*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>

using namespace std;

std::pair<std::string, int>
process (std::vector<std::string>& v)
{
	if (!v.empty())
		return {v.back(), v.back().size()};
	else
		return std::pair<std::string, int>();
}

int main(void) {
	/*pair*/
	std::pair<std::string, std::string> author { "James", "Joyce" };
	std::cout << author.first << " and " << author.second << std::endl;
	std::vector<std::string> sv = {"girl", "lady", "baby"};
	std::pair<std::string, int> sip = process(sv);
	std::cout << sip.first << " and " << sip.second << std::endl;

	/*Associative Container Iterators*/
	std::map<std::string, int> word_count = {{"Hello", 1}, {"World", 2}, {"Girl", 4}};
	std::cout << word_count.size() << std::endl;
	auto map_it = word_count.begin();
	++(map_it->second);
	//输出"Girl", 因为map进行了排序
	std::cout << map_it->first << " " << map_it->second << std::endl;
	std::set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::set<int>::iterator set_it = iset.begin();
	if (set_it != iset.end()){
		std::cout << "*set_it = " << *set_it << std::endl;
	}

	/*Iterator Traverse, GCC4.6.3不支持cbegin*/
	auto map_it2 = word_count.begin();
	while (map_it2 != word_count.end()){
		std::cout << map_it2->first << " occurs " << map_it2->second
				<< " times" << std::endl;
		++map_it2;
	}
}








