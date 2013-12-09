/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.12.9
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

template <typename T>
bool compare (const T& t1, const T& t2)
{
	std::cout << "first version" << std::endl;
	return (t1<t2) ? true : false;
}

//函数模板定制
template<>
bool compare (const char* const &p1, const char* const &p2)
{
	std::cout << "third version" << std::endl;
	return strcmp(p1, p2);
}

//有非模板优先使用非模板
/*bool compare (const char* const &p1, const char* const &p2)
{
	std::cout << "forth version" << std::endl;
	return strcmp(p1, p2);
}*/

//处理字面类型的比较
template<unsigned N, unsigned M>
bool compare (const char (&p1)[N], const char (&p2)[M])
{
	std::cout << "second version" << std::endl;
	return strcmp(p1, p2);
}

int main(void)
{
	const char* w("Wendy");
	const char* c("Caroline");
	//没有函数模板定制, 调用第一个版本, 因为指针不能转换为数组的引用
	if(compare(c, w)) {
		std::cout << "Caroline is long." << std::endl;
	} else {
		std::cout << "Wendy is long." << std::endl;
	}

	if(compare("Caroline", "Wendy")) {
		std::cout << "Caroline is long." << std::endl;
	} else {
		std::cout << "Wendy is long." << std::endl;
	}

	return 0;
}
