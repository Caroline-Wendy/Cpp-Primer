/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.11.2
 *      Author: C.L.Wang
 */

#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <string>
#include <set>
#include <map>

#include <cstddef>
#include <utility>
#include <stdexcept>

using namespace std;

std::map<std::string, std::string>
buildMap(std::ifstream& map_file){
	std::map<std::string, std::string> trans_map;
	std::string key;
	std::string value;
	while (map_file >> key && std::getline(map_file, value)){
		if(value.size() > 1)
			trans_map[key] = value.substr(1); //略过空格
		else
			throw runtime_error("no rule for " + key);
	}
	return trans_map;
}

const std::string&
transform(const std::string &s, const std::map<std::string, std::string> &m)
{
	auto map_it = m.find(s);
	if(map_it != m.end())
		return map_it->second;
	else
		return s;
}

void word_transform(std::ifstream& map_file, std::ifstream& input)
{
	auto trans_map = buildMap(map_file);
	std::string text;
	while (std::getline(input, text)){
		std::istringstream stream(text);
		std::string word;
		bool firstword = true;
		while (stream >> word){
			if(firstword) //不会打印第一个空格
				firstword = false;
			else
				std::cout << " ";
			std::cout << transform(word, trans_map);
		}
		std::cout << std::endl;
	}
}

int main(void) {

	std::ifstream map_file("map_file.txt");
	std::ifstream input("input.txt");
	word_transform(map_file, input);
	map_file.close();
	input.close();

	return 0;

}

