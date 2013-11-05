/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.11.4
 *      Author: C.L.Wang
 */

/*eclipse cdt GCC 4.8.1*/

#include <iostream>

#include <vector>
#include <string>

#include <memory>
#include <new>

using namespace std;

int main (void) {

	/*unique_ptr*/
	std::unique_ptr<int> p1(new int(42));
	std::cout << "*p1 = " << *p1 << std::endl;
	std::unique_ptr<std::string> p2(new std::string("Canonical"));
	std::cout << "*p2 = " << *p2 << std::endl;
	std::unique_ptr<std::string> p3(p2.release());
	std::cout << "*p3 = " << *p3 << std::endl;
	std::unique_ptr<std::string> p4(new std::string("Principal"));
	std::cout << "*p4 = " << *p4 << std::endl;
	p4.reset(p3.release());
	std::cout << "reset: *p4 = " << *p4 << std::endl;

	/*weak_ptr*/
	std::shared_ptr<int> p5 = std::make_shared<int>(42);
	std::weak_ptr<int> p6(p5);
	//std::cout << "*p6 = " << *p6 << std::endl;
	std::cout << "p5 use count = " << p5.use_count() << std::endl;
	std::cout << "p6 use count = " << p6.use_count() << std::endl;
	std::cout << "*p6.lock() = " << *p6.lock() << std::endl;
	std::shared_ptr<int> p7 = p6.lock();
	std::cout << "*p7 = " << *p7 << std::endl;
	std::cout << "p7 use count = " << p7.use_count() << std::endl;

 	return 0;

}
