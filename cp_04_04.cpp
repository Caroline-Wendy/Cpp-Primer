/*Programme from C++ Primer, By C.L.Wang*/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[]){

	/*指针数组转换*/
	int ia[5] = {1, 2, 3, 4, 5};
	int* ip = ia;
	std::cout << "*ip = " << *ip << std::endl;

	/*指针为空, 不能解引用*/
	/*ip = nullptr;
	std::cout << "*ip = " << *ip << std::endl;*/

	/*const指针和引用转换*/
	int i(0);
	const int &j = i;
	const int *p = &i;
	i = 2;
	std::cout << "j = " << j << std::endl;
	std::cout << "*p = " << *p << std::endl;
	/*int& r = j*/

	/*整数除法被截断, 并且没有警告*/
	int ii(3), ij(2);
	double slope = static_cast<double>(ii)/ij;
	std::cout << "slope = " << slope << std::endl;

	/*static_cast<type>*/
	double d(12.0);
	void* pp = &d;	//无法输出
	double* dp = static_cast<double*>(pp);
	std::cout << "*dp = " << *dp << std::endl;

	/*改变const属性(指针\引用), const_cast<type>*/
	const int ww(10);
	int* kk = const_cast<int*>(&ww);
	*kk += 20;
	std::cout << "ww  = " << ww  << std::endl;
	std::cout << "*kk  = " << *kk  << std::endl;

	/*reinterpret_cast<type>重新解释*/
	int a_tt(97);
	char* a_pp = reinterpret_cast<char*>(&a_tt);
	std::cout << "*a_pp  = " << *a_pp  << std::endl;
	std::string str(a_pp);
	std::cout << "str  = " << str  << std::endl;

	return 0;

}