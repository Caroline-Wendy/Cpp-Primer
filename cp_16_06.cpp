/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.28
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <typeinfo>

using namespace std;

/*需要显示定义返回类型*/
template <typename T1, typename T2, typename T3>
T1 sum (T2, T3)
{
	T2 i2; T3 i3;
	return static_cast<T1>(i2+i3);
}

/*注意拖尾返回类型(trailing return type)前面需要加auto*/
template <typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
	return *beg;
}

/*注意拖尾返回类型是值, 注意第二个typename, 表明为类型*/
template <typename It>
auto fcn2(It beg, It end) ->
	typename remove_reference<decltype(*beg)>::type
{
	return *beg;
}

int main (void) {

	std::cout << "The type of sum return : " <<
			typeid(sum<float>(2, 3)).name() << std::endl;

	std::vector<int> vi = {1, 2, 3, 4, 5};
	std::vector<std::string> vs = {"girl", "lady"};

	/*返回的是引用*/
	auto &i = fcn(vi.begin(), vi.end());
	auto &s = fcn(vs.begin(), vs.end());
	i = 12, s = "woman";

	std::cout << "*vi.begin() = " << *vi.begin() << std::endl;
	std::cout << "*vs.begin() = " << *vs.begin() << std::endl;

	/*返回的是值, 所以不能在使用&符号*/
	auto i2 = fcn2(vi.begin(), vi.end());
	auto s2 = fcn2(vs.begin(), vs.end());

	std::cout << "i2 = " << i2 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;

	return 0;

}
