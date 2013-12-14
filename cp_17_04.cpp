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
	boost::regex r(pattern, regex::icase); //忽略大小写
	std::string str("Ruby Carolinei biubiubiu Weindy SpikeI Winnceiy");
	//使用正则迭代器进行遍历
	for(boost::sregex_iterator it(str.begin(), str.end(), r), end_it;
			it!=end_it; ++it)
		std::cout << it->str() << std::endl;

	//输出正则表达式的前后字符串
	std::cout << std::endl;
	for(boost::sregex_iterator it(str.begin(), str.end(), r), end_it;
			it!=end_it; ++it){
		auto pos = it->prefix().length();
		pos = pos>40 ? pos-40 : 0;
		std::cout << it->prefix().str().substr(pos) /*输出前一个未匹配的字符串*/
				<< "\n\t\t>>>" << it->str() << "<<<\n"
				<< it->suffix().str().substr(0, 40) /*输出之后的字符串*/
				<<std::endl;
	}

	//匹配子表达式
	std::string filename("File.cqp MyGod.cpP");
	boost::regex rsub("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);
	smatch results;
	if(boost::regex_search(filename, results, rsub))
		std::cout << results.str(1) << std::endl;
}
