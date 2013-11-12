/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.11.11
 *      Author: Caroline
 */

/*eclipse cdt*/

#include <iostream>
#include <stdexcept>
#include <cstddef>

using namespace std;

class B;
struct A {
	A() = default;
	A(const B&) {
		std::cout << "Hello, girl, this A's constructor. " << std::endl;
	}
};
struct B {
	operator A() const{
		std::cout << "Hello, girl, this B's convertion. " << std::endl;
	}
	int b;
};
A f(const A&) {}
struct C {
	C(int = 0) {
		std::cout << "Hello, girl, this C's int constructor. " << std::endl;
	}
	C(double) {
		std::cout << "Hello, girl, this C's double constructor. " << std::endl;
	}
	operator int () const {
		std::cout << "Hello, girl, this C's int convertion. " << std::endl;
	}
	operator double () const {
		std::cout << "Hello, girl, this C's double convertion. " << std::endl;
	}
};
void f2(long double) {}
struct D {
	//D() = default;
	D(int) {
		std::cout << "Hello, girl, this D's int constructor. " << std::endl;
	}
};
struct E {
	//E() = default;
	E(int) {
		std::cout << "Hello, girl, this E's int constructor. " << std::endl;
	}
};
void manip (const D&) {}
void manip (const E&) {}
int main (void) {
	B b;
	A a = f(b);
	A a1 = f(b.operator A());
	A a2 = f(A(b));

	C c;
	//f2(c);
	long lg;
	//C c2(lg);
	short s = 42;
	C c1(s);
	float fl = 0.1;
	C c2(fl);

	manip(D(10));
	manip(E(10));

	return 0;

}
