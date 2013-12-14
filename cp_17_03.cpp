#include <iostream>
#include <string>
#include <algorithm>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

int main()
{
	std::string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	boost::regex r(pattern);
	boost::smatch results;
	std::string test_str = "receipt freind theif receive";
	//只保存第一个, freind和theif都满足要求
	if(boost::regex_search(test_str, results, r))
		std::cout << results.str() << std::endl;

	boost::regex r2("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
	boost::smatch results2;
	std::string filename = "a.cpP";
	if(boost::regex_search(filename, results2, r2))
		std::cout << results2.str() << std::endl;
}
