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

std::shared_ptr<int> clone(int p) {
	return shared_ptr<int>(new int(p));
}

void process (std::shared_ptr<int> ptr) {
	std::cout << "process : ";
	std::cout << "ptr use count : " << ptr.use_count() << std::endl;
	return;
}

int main (void) {

	//std::shared_ptr<int> p1 = new int(1024);
	std::shared_ptr<int> p2(new int(1024));
	//std::cout << "*p1 = " << *p1 << std::endl;
	std::cout << "*p2 = " << *p2 << std::endl;
	int p = 24;
	auto q = clone(p);
	std::cout << "*q = " << *q << std::endl;

	int* pi = new int(42);
	int* qi = pi;
	delete pi;
	pi = nullptr;
	std::cout << "*qi = " << *qi << std::endl; //悬空指针

	std::shared_ptr<int> psi = std::make_shared<int>(42);
	std::shared_ptr<int> qsi = psi;
	std::cout << "*qsi = " << *qsi << std::endl;
	std::cout << "*psi = " << *psi << std::endl;

	std::shared_ptr<int> pspi(new int(42));
	process(pspi);
	std::cout << "p use count : " << pspi.use_count() << std::endl;

	int* x(new int(1024));
	process(std::shared_ptr<int>(x));
	int j = *x;
	std::cout << "j = " << j << std::endl; //悬空指针

	std::shared_ptr<int> pg(new int(42));
	int* qg = pg.get();
	{
		//int* qg = pg.get();
		std::shared_ptr<int> qg1(qg);
	}
	int foo = *pg;
	std::cout << "foo = " << foo << std::endl;

	std::shared_ptr<int> pp1(new int(25));
	std::cout << "*pp1 = " << *pp1 << std::endl;
	//p1 = new int(1024);
	pp1.reset(new int(1024));
	auto pp2 = pp1;
	std::cout << "*pp1 = " << *pp1 << std::endl;
	std::cout << "*pp2 = " << *pp2 << std::endl;
	std::cout << "pp1 use count : " << pp1.use_count() << std::endl;
	if(!pp1.unique())
		pp1.reset(new int(*pp1));
	*pp1 = 20;
	std::cout << "*pp1 = " << *pp1 << std::endl;
	std::cout << "*pp2 = " << *pp2 << std::endl;
	std::cout << "pp1 use count : " << pp1.use_count() << std::endl;
 	return 0;
}
