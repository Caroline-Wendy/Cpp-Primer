/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.12.9
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

std::tuple<std::string, int>
giveName(void)
{
	std::string cw("Caroline");
	int a(2013);
	std::tuple<std::string, int> t = std::make_tuple(cw, a);
	return t;
}

int main()
{
	std::tuple<int, double, std::string> t(64, 128.0, "Caroline");
	std::tuple<std::string, std::string, int> t2 =
			std::make_tuple("Caroline", "Wendy", 1992);

	//返回元素个数
	size_t num = std::tuple_size<decltype(t)>::value;
	std::cout << "num = " << num << std::endl;

	//获取第1个值的元素类型
	std::tuple_element<1, decltype(t)>::type cnt = std::get<1>(t);
	std::cout << "cnt = " << cnt << std::endl;

	//比较
	std::tuple<int, int> ti(24, 48);
	std::tuple<double, double> td(28.0, 56.0);
	bool b = (ti < td);
	std::cout << "b = " << b << std::endl;

	//tuple作为返回值
	auto a = giveName();
	std::cout << "name: " << get<0>(a)
			<< " years: " << get<1>(a) << std::endl;

	return 0;
}
