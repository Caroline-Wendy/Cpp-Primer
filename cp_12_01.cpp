/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.11.2
 *      Author: C.L.Wang
 */

/*eclipse cdt*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <list>

using namespace std;

std::shared_ptr<std::string>
factory(const std::string str){
	return std::make_shared<std::string>(str);
}

std::shared_ptr<std::string>
use_factory(const std::string str){
	std::shared_ptr<std::string> p = factory(str);
	return p;
}

int main (void) {

	/*shared_ptr初始化*/
	std::shared_ptr<std::string> p1;
	std::shared_ptr<std::list<int>> p2;
	p1 = std::make_shared<std::string>("hi");
	*p1 = "good";
	std::shared_ptr<int> p3 = std::make_shared<int>(42);
	std::shared_ptr<std::string> p4 = std::make_shared<std::string>(10, '9');
	std::shared_ptr<int> p5 = std::make_shared<int>();
	std::cout << "p1 = " << *p1 << std::endl;
	std::cout << "p3 = " << *p3 << std::endl;
	std::cout << "p4 = " << *p4 << std::endl;
	std::cout << "p5 = " << *p5 << std::endl;

	/*shared_ptr复制*/
	auto q(p3);
	std::cout << "p3.use_count() = " << p3.use_count() << std::endl;
	std::cout << "q.use_count() = " << q.use_count() << std::endl;

	std::shared_ptr<std::string> p = use_factory("hello");
	std::cout << "p.use_count() = " << p.use_count() << std::endl;
	std::cout << *p << std::endl;

	std::vector<int> iv = {1, 2, 3};
	for(auto it = iv.cbegin(); it != iv.cend(); ++it)
		std::cout << *it << std::endl;

}
