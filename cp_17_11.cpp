/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.28
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <iomanip> //setprecision
#include <cmath>

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

	//浮点数的精度
	std::cout << "Precision : " << std::cout.precision() << ", Value : " << std::sqrt(2.0) << std::endl; //默认6位
	std::cout.precision(12); //使用cout的precision方法设置精度
	std::cout << "Precision : " << std::cout.precision() << ", Value : " << std::sqrt(2.0) << std::endl;
	std::cout << std::setprecision(3); //使用<iomanip>的setprecision函数设置精度
	std::cout << "Precision : " << std::cout.precision() << ", Value : " << std::sqrt(2.0) << std::endl;

	//前面指定精度为3, 默认输出3位, fixed固定小数为3位
	std::cout << "default format : " << 100*std::sqrt(2.0) << '\n'
			<< "scientific : " << std::scientific << 100*std::sqrt(2.0) << '\n'
			<< "fixed decimal : " << std::fixed << 100*std::sqrt(2.0) << '\n';

	//显示小数
	std::cout << std::showpoint << 10.0 << std::endl << std::noshowpoint;

	//格式
	int i(-16);
	double d(3.14159);
	std::cout << "i: " << std::setw(12) << i << "next col" << '\n';
	std::cout << "d: " << std::setw(12) << d << "next col" << '\n';
	std::cout << std::left //左对齐
			<< "i: " << std::setw(12) << i << "next col" << '\n'
			<< "d: " << std::setw(12) << d << "next col" << '\n';
	std::cout << std::right //左对齐
			<< "i: " << std::setw(12) << i << "next col" << '\n'
			<< "d: " << std::setw(12) << d << "next col" << '\n';
	std::cout << std::internal //左对齐
			<< "i: " << std::setw(12) << i << "next col" << '\n'
			<< "d: " << std::setw(12) << d << "next col" << '\n';
	std::cout << std::setfill('#') //左对齐
			<< "i: " << std::setw(12) << i << "next col" << '\n'
			<< "d: " << std::setw(12) << d << "next col" << '\n'
			<< std::setfill(' ');

	char ch;
	/*while (std::cin >> ch)
		std::cout << ch; //忽略空格*/
	std::cin >> std::noskipws; //保留空格
	while (std::cin >> ch)
		std::cout << ch;
	std:;cin >> std::skipws;
	return 0;
}



















