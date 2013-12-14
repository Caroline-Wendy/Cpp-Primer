#include <iostream>
#include <string>

#include <boost/regex.hpp>

using namespace std;
using namespace boost;

int main()
{
	//问号(?)表示之前的可以选择
	std::string phone =
			"(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	boost::regex r(phone);
	//代替
	std::string fmt("$2.$5.$7");
	std::string number("(908)555-1800");
	std::cout << regex_replace(number, r, fmt) << std::endl;

	std::string file("Caroline (201)555-2368 862-55-0123");
	std::cout << boost::regex_replace(file, r, fmt) << std::endl;
	std::cout << boost::regex_replace(file, r, fmt,
			boost::regex_constants::format_no_copy) << std::endl;
}
