/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.24
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <memory>

using namespace std;

void deleter (int* ptr) {
	delete ptr;
	ptr = nullptr;
	std::clog << "shared_ptr delete the pointer." << std::endl;
}

int main (void) {

	//定义函数类型
	typedef void (*tp) (int*);
	typedef decltype (deleter)* dp;
	using up = void (*) (int*);

	std::shared_ptr<int> spi(new int(10), deleter);
	std::shared_ptr<int> spi2(new int, deleter);
	spi2 = std::make_shared<int>(15);

	std::cout << "*spi = " << *spi << std::endl;
	std::cout << "*spi2 = " << *spi2 << std::endl;

	//unique_ptr是模板函数需要删除器(deleter)类型, 再传入具体的删除器
	std::unique_ptr<int, decltype(deleter)*> upi(new int(20), deleter);
	std::unique_ptr<int, tp> upi2(new int(25), deleter);
	std::unique_ptr<int, dp> upi3(new int(30), deleter);
	std::unique_ptr<int, up> upi4(new int(35), deleter);

	std::cout << "*upi = " << *upi << std::endl;
	std::cout << "*upi2 = " << *upi2 << std::endl;
	std::cout << "*upi3 = " << *upi3 << std::endl;
	std::cout << "*upi4 = " << *upi4 << std::endl;

	return 0;

}
