/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.28
 *      Author: Caroline
 */

#include <iostream>
#include <typeinfo>

template <typename T>
void rvfnc (T&& val)
{
	T t = val;
	++t;
	if (val == t)
		std::cout << "rvfnc: this is lvalue." << std::endl;
	else
		std::cout << "rvfnc: this is rvalue." << std::endl;
}

template <typename T>
void rvfnc (const T& val)
{
	std::cout << "rvfnc(overload): this is lvalue." << std::endl;
}

int main (void)
{
	int i(10);
	rvfnc(i); //左值
	rvfnc(10); //右值
	rvfnc<int&>(i); //如果包含重载则使用重载; 如果不包含, 则使用右值;

	return 0;
}


