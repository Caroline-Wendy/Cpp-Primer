/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.21
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <vector>
#include <functional> //less<>
#include <cstring> //strcmp

template <typename T>
int compare (const T &v1, const T &v2)
{
	if (std::less<T>() (v1, v2)) return -1; //使用库函数代替"<", 会避免指针地址比较
	if (std::less<T>() (v2, v1)) return 1;
	return 0;
}

template<unsigned N, unsigned M>
int compare (const char (&p1) [N], const char (&p2) [M])
{
	std::cout << "N = " << N << " M = " << M << std::endl; //添加一个空终止符(null terminator)
	return std::strcmp (p1, p2); //只比较不同的第一个字符
}

int main (void) {

	std::cout << compare(1, 0) << std::endl;
	std::vector<int> v1{1, 2, 3}, v2{4, 5, 6};
	std::cout << compare(v1, v2) << std::endl;
	std::cout << compare("girl", "lad") << std::endl;
	int a[] = {1, 2, 3, 4}, b[] = {1, 3, 4, 5};
	std::cout << compare(a, b) << std::endl;

	return 0;

}
