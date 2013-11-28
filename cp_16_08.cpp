/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.28
 *      Author: Caroline
 */

#include <iostream>
#include <utility>

void f (int v1, int &v2)
{
	std::cout << v1 << " " << ++v2 << std::endl;
}

void g (int &&i, int &j) //i为右值
{
	std::cout << i << " " << j << std::endl;
}

template <typename F, typename T1, typename T2>
void flip1 (F f, T1 t1, T2 t2)
{
	f(t2, t1); //反序
}

template <typename F, typename T1, typename T2>
void flip2 (F f, T1&& t1, T2&& t2) //右值传递, 保证引用性
{
	f(t2, t1); //反序
}

template <typename F, typename T1, typename T2>
void flip3 (F f, T1&& t1, T2&& t2) //右值传递, 保证引用性
{
	f(std::forward<T2>(t2), std::forward<T1>(t1)); //反序
}


int main (void)
{
	int i(10), j(10);
	f (42, i); //i传递引用发生改变
	flip1 (f, j, 42); //j传递在flip1传递时是复制, 不发生改变

	std::cout << "flip 1 : i = " << i << std::endl;
	std::cout << "flip 1 : j = " << j << std::endl;

	flip2 (f, j, 42); //j传递在flip1传递时是复制, 不发生改变
	std::cout << "flip2 : j = " << j << std::endl;

	g (42, i); //可以传递
	//不能传递, 因为j在传递时变成左值引用, 无法赋值右值
	//cannot bind 'int' lvalue to 'int&&'
	//flip1 (g, j, 42);

	flip3 (g, j, 42); //forward函数保证传递所有信息

	return 0;
}


