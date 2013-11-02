/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.11.2
 *      Author: C.L.Wang
 */

#include <iostream>
#include <vector>
#include <string>
#include <tr1/unordered_map>

using namespace std;

int main(void) {

	/*unordered - hash*/
	std::tr1::unordered_map<std::string, size_t> word_count;
	std::string word;
	std::vector<std::string> sv = {"Lady", "Girl", "Baby", "Woman", "Girl", "Ladyboy"};
	for(const auto& str : sv)
		++word_count[str];
	for(const auto& w : word_count)
		std::cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times. " : " time. ") << std::endl;

	std::cout << "bucket_count = " << word_count.bucket_count() << std::endl;
	std::cout << "max_bucket_count = " << word_count.max_bucket_count() << std::endl;

	for(const auto& w : word_count)
		std::cout << w.first << " bucket : "
		<< word_count.bucket(w.first) << std::endl;

	std::cout << "load_factor = " << word_count.load_factor() << std::endl;
	std::cout << "max_load_factor = " << word_count.max_load_factor() << std::endl;

	word_count.rehash(5);
	for(const auto& w : word_count)
			std::cout << w.first << " bucket : "
			<< word_count.bucket(w.first) << std::endl;

	return 0;

}

