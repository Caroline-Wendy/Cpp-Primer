/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.7
 *      Author: Caroline
 */

#include <iostream>

struct NoCopy {
	NoCopy () = default;
	NoCopy (const NoCopy&) = delete;
	NoCopy &operator= (const NoCopy&) = delete;
	~NoCopy () = default;
};

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {} //构造器
	HasPtr(const HasPtr &p) : ps (new std::string (*p.ps)), i(p.i) {} //复制构造器
	HasPtr& operator= (const HasPtr &); //复制分配构造器
	~HasPtr() { delete ps; } //析构器
private:
	std::string *ps;
	int i;
};

HasPtr& HasPtr::operator= (const HasPtr &rhs) {
	auto newp = new std::string (*rhs.ps);
	delete ps;
	ps = newp;
	i = rhs.i;
	return *this;
}

int main (void) {

	return 0;
}
