#include <iostream>
#include <string>

#include <boost/regex.hpp>

using namespace std;
using namespace boost;

bool valid(const boost::smatch& m)
{
	if(m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

int main()
{
	//问号(?)表示之前的可以选择
	std::string phone =
			"(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	boost::regex r(phone);
	boost::smatch m;
	std::string s("(432)312-3425 942-415-1424 15");
	for(boost::sregex_iterator it(s.begin(), s.end(), r), end_it;
			it != end_it; ++it)
	{
		if(valid(*it))
			std::cout << "valid : " << it->str() << std::endl;
		else
			std::cout << "not valid : " << it->str() << std::endl;
	}
}
