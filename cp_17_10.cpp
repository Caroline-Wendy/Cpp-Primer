/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.28
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>

using namespace std;

int main()
{
	//控制格式化, 输出
	std::cout << "default bool values : " << true << " " << false
			<< "\nalpha bool values : " << std::boolalpha << true << " " << false
			<< std::endl;
	std::cout << "no reset bool : " << true << " " << false << std::endl; //没有重置
	std::cout << std::noboolalpha << "reset bool : " << true << " " << false << std::endl; //重置

	//整数的基, 显示, 大写
	std::cout << std::showbase;
	std::cout << "default : " << 20 << " " << 1024 << std::endl; //默认
	std::cout << "octal : " << oct << 20 << " " << 1024 << std::endl; //8进制
	std::cout << std::uppercase << "hex : " << hex << 20 << " " << 1024
			<< std::nouppercase <<std::endl; //16进制
	std::cout << "decimal : "  << dec<< 20 << " " << 1024 << std::endl; //10进制
	std::cout << std::noshowbase;
	return 0;
}
