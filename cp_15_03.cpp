/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.13
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.7.1*/

#include <iostream>

class Base {
public:
	virtual int fcn () { //虚函数
		std::cout << "This base class [int fcn()]. " << std::endl;
		return 0;
	}
	void f2 () {
		std::cout << "This bass class [f2()]. " << std::endl;
	}
};
class D1 : public Base {
public:
	int fcn (int) { //与基类的参数不同, 不是重载虚函数
		std::cout << "This derived 1 class [int fcn(int)]. " << std::endl;
		return 0;
	}
	virtual void f2 () { //虚函数
		std::cout << "This derived 1 class [f2()]. " << std::endl;
	}
	using Base::f2;
};
class D2 : public D1 {
public:
	int fcn (int) { //隐藏基函数的同名函数
		std::cout << "This derived 2 class [int fcn(int)]. " << std::endl;
		return 0;
	}
	int fcn () { //重载基类的虚函数
		std::cout << "This derived 2 class [int fcn()]. " << std::endl;
		return 0;
	}
	void f2 () {
		std::cout << "This derived 2 class [f2()]. " << std::endl;
	}
};

int main (void) {

	Base bobj;
	D1 d1obj;
	D2 d2obj;

	Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
	bp1->fcn();
	bp2->fcn(); //未找到重载版本, 则使用基函数版本
	bp3->fcn(); //D2使用的是重载版本

	D1 *d1p = &d1obj;
	D2 *d2p = &d2obj;
	d1p->f2();
	d2p->f2();

	D1 *p1 = &d2obj;
	D2 *p2 = &d2obj;
	p1->fcn(10);
	p2->fcn(10);

	return 0;

}


