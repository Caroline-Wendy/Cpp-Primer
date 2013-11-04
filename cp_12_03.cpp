/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.11.4
 *      Author: C.L.Wang
 */

/*eclipse cdt*/

#include <iostream>

#include <vector>
#include <string>

#include <memory>
#include <new>

using namespace std;

int main (void) {
	/*new*/
	int* pi = new int();
	std::string* ps = new std::string(10, '9');
	std::vector<int>* pv = new std::vector<int>{0, 1, 2, 3, 4, 5};
	std::cout << "*pi (new) = " << *pi << std::endl;
	*ps = "Change!";
	std::cout << "*ps (new) = " << *ps << std::endl;
	std::cout << "*pv (new) = ";
	for(const auto& i : *pv){
		std::cout << i << " ";
	}
	std::cout << std::endl;
	const int* pci = new const int(1024);
	const std::string* pcs = new const std::string;
	std::cout << "*pci (new) = " << *pci << std::endl;
	delete pci;
	std::cout << "*pcs (new) = " << *pcs << std::endl;
	int *pni = new (nothrow) int(32);
	std::cout << "*pni (new) = " << *pni << std::endl;

	/*delete*/
	int i(10), *pdi = &i, *pi2 = nullptr;
	double* pd = new double(33.0), *pd2 = pd;
	delete pdi;
	delete pd;
	delete pd2; //潜在的错误, 不会报错
	delete pi2;

	/*error-prone*/
	int* p = new int(42);
	auto q = p;
	delete p;
	p = nullptr;
	//*p无法使用, 因为赋值nullptr; *q成为悬空指针
	//std::cout << "*p (new) = " << *p << std::endl;
	std::cout << "*q (new) = " << *q << std::endl;

 	return 0;
}
