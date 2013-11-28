/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.28
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <sstream>
#include <string>
#include <utility>

using namespace std;

template <typename T>
std::string debug_rep (const T &t)
{
	std::ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename T>
std::string debug_rep (T *p)
{
	std::ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep (*p);
	else
		ret << " null pointer";
	return ret.str();
}

/*非模板函数*/
std::string debug_rep (const string &s)
{
	return '"' + s + '"';
}

/*char 重载版本*/
std::string debug_rep (char *p)
{
	std::cout << "plain ";
	return debug_rep (std::string(p));
}

/*const char 重载版本*/
std::string debug_rep (const char *p)
{
	std::cout << "const ";
	return debug_rep (std::string(p)); //调用第一个模板, 注意顺序, 或者前置声明
}

int main (void)
{
	std::string s("hi");
	std::cout << debug_rep (s) << std::endl; //调用第一个 / 优先调用非模板
	//&s, 即 string* s = &s, string* t = const T &t, 即 T->string*
	// string* t = T* t, 即 T->string; 所以选择第二个
	std::cout << debug_rep (&s) << std::endl; //调用第二个
	const std::string *sp = &s;
	std::cout << debug_rep (sp) << std::endl; //调用第二个
	//调用第二个, 只传递首字母; 包含char版本, 右值调用const
	std::cout << debug_rep("hello world") << std::endl;

	return 0;
}


