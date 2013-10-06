#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[]){

	/*条件操作的优先级较低*/
	int grade(40);
	std::cout << ((grade<60) ? "fail" : "pass") << std::endl;
	std::cout << (grade<60)  << std::endl;

	unsigned char val = 0227;
	std::cout << "val >> 3 = " << (val >> 3) << std::endl;
	std::cout << "val << 8 = " << (val << 8) << std::endl;
	std::cout << "val << 31 = " << (val << 31) << std::endl;
	std::cout << "~val = " << ~val << std::endl;

	/*测试位操作符*/
	unsigned char b1(0145);
	unsigned char b2(0257);
	std::cout << "b1&b2 = " << (b1&b2) << std::endl;
	std::cout << "b1&b2 = " << (b1|b2) << std::endl;
	std::cout << "b1&b2 = " << (b1^b2) << std::endl;

	/*位运算例子*/
	unsigned long quiz1(0);
	quiz1 |= 1UL<<27;
	bool status =quiz1 & (1UL<<27);
	if(status)
		std::cout << "Pass! " << std::endl;
	else
		std::cout << "Fail! " << std::endl;
	quiz1 &= ~(1UL<<27);
	status =  quiz1 & (1UL<<27);
	if(status)
		std::cout << "Pass! " << std::endl;
	else
		std::cout << "Fail! " << std::endl;

	int ia[] = {1, 2, 3, 4};
	std::cout << "sizeof(char) = " << sizeof(char)  << std::endl;
	std::cout << "sizeof(a_int) = " << sizeof(ia)  << std::endl;

	/*求数组的大小*/
	const size_t sz = sizeof(ia) / sizeof(*ia);
	int arr2[sz];
	for(int& t : arr2)
		t = 2;
	for(const int t : arr2)
		std::cout << t << std::endl;

	/*逗号操作符*/
	vector<int> ivec(4);
	int cnt = 4;
	for(vector<int>::size_type ix=0; ix!=ivec.size(); ++ix, --cnt)
		ivec[ix] = cnt;
	for(const int t : ivec)
		std::cout << t << std::endl;

	/*隐式类型转换*/
	int a = -1;
	unsigned short b = 10;
	decltype(a+b) c = a+b;
	std::cout << "a+b = "  << c << std::endl;
	std::cout << "3.14+'a' = " << 3.14+'a'  << std::endl;

	return 0;
}

