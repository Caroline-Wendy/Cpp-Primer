/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.11.2
 *      Author: C.L.Wang
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <cstddef>

using namespace std;

int main(void) {
	/*add a element to set*/
	std::vector<int> ivec = {2, 4, 6, 8, 2, 4, 6, 8};
	std::set<int> set2;
	set2.insert(ivec.begin(), ivec.end());
	for(const auto& i : set2)
		std::cout << i << " ";
	std::cout << std::endl;
	std::vector<int> ivec2 = {1, 3, 5, 7, 1, 3, 5, 7};
	set2.insert(ivec2.begin(), ivec2.end());
	for(const auto& i : set2)
		std::cout << i << " ";
	std::cout << std::endl;

	/*add a element to map*/
	std::map<std::string, size_t> word_count;
	word_count.insert({"Hello", 1});
	word_count.insert(make_pair("World", 2));
	word_count.insert(std::pair<std::string, int>("Girl", 3));
	word_count.insert(std::map<std::string, size_t>::value_type("Lady", 4));
	for(auto map_it = word_count.begin(); map_it != word_count.end(); map_it++)
		std::cout << map_it->first << " " << map_it->second << std::endl;

	/*return insert*/
	std::vector<std::string> sv = {"Hello", "Ladyboy", "Lady"};
	auto sv_it = sv.begin();
	while (sv_it != sv.end()){
		auto ret = word_count.insert({*sv_it, 1});
		std::cout << std::boolalpha << ret.second << std::endl;
		if(!ret.second) //没有插入成功, 就把原值加1
			++ret.first->second;
		sv_it++;
	}
	std::cout << "return: " << std::endl;
	for(const auto& i : word_count)
		std::cout << i.first << " " << i.second << std::endl;
	std::cout << std::endl;

	/*multimap*/
	multimap<std::string, std::string> authors;
	authors.insert({"Caroline", "To be a girl"});
	authors.insert({"Caroline", "To be a woman"});
	authors.insert({"Caroline", "To be a baby"});
	std::cout << "multimap: " << std::endl;
	for(const auto& i : authors){
		std::cout << i.first << " " << i.second << std::endl;
	}

	/*erase*/
	std::cout << "Elements: " << word_count.begin()->first << std::endl;
	std::map<std::string, size_t>::iterator wc_it = word_count.erase(word_count.begin());
	std::cout << "Return: " << wc_it->first << std::endl;
	std::string removal_word("Hello");
	std::cout << "The count: " << word_count.erase(removal_word) << std::endl;
	std::cout << "ok: " << removal_word << " removed\n";
	if(word_count.erase(removal_word))
		std::cout << "ok: " << removal_word << " removed\n";
	else
		std::cout << "oops: " << removal_word << " not found!\n";
	auto cnt = authors.erase("Caroline");
	std::cout << "multiple: " << cnt << std::endl;

	/*subscripting a map*/
	word_count["Anna"] = 10;
	std::cout << "Anna : " << word_count["Anna"] << std::endl;
	std::cout << word_count.at("Anna") << std::endl;

	/*access elements*/
	std::multiset<int> iset_a = {0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5};
	std::cout << "iset_a.find(1) = " << *iset_a.find(1) << std::endl;
	std::cout << "iset_a.find(10) = " << *iset_a.find(10) << std::endl;
	std::cout << "iset_a.count(1) = " << iset_a.count(1) << std::endl;
	std::cout << "iset_a.count(11) = " << iset_a.count(11) << std::endl;

	if(word_count.find("foobar") == word_count.end()){
		std::cout << "foobar is not in the map. " << std::endl;
	}

	authors.insert({"Wendy", "To be a girl"});
	authors.insert({"Wendy", "To be a woman"});
	authors.insert({"Wendy", "To be a baby"});
	std::string search_item("Wendy");
	auto entries = authors.count(search_item);
	auto iter = authors.find(search_item);
	while(entries){
		std::cout << iter->second << std::endl;
		++iter;
		--entries;
	}
	for(auto beg = authors.lower_bound(search_item),
			end = authors.upper_bound(search_item);
			beg != end; ++beg){
		std::cout << beg->second << std::endl;
	}
	std::cout << "equal_range: " << std::endl;
	for(auto pos = authors.equal_range(search_item);
			pos.first != pos.second; ++pos.first){
		std::cout << pos.first->second << std::endl;
	}
}



