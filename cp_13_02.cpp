/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.7
 *      Author: Caroline
 */

#include <iostream>
#include <string>
#include <memory>
#include <utility> //swap
#include <cstddef>

/*class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(std::make_shared<std::string>(s)), i(0) {} //构造器
private:
	std::shared_ptr<std::string> ps;
	int i;
};*/

struct NoCopy {
	NoCopy () = default;
	NoCopy (const NoCopy&) = delete;
	NoCopy &operator= (const NoCopy&) = delete;
	~NoCopy () = default;
};

class HasPtr
{
friend void swap (HasPtr&, HasPtr&);
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0), use(new std::size_t(1)) {} //构造器
	HasPtr(const HasPtr &p) : ps (p.ps), i(p.i), use(p.use) { ++(*use); } //复制构造器
	HasPtr& operator= (HasPtr); //复制分配构造器
	~HasPtr(); //析构器
private:
	std::string *ps;
	int i;
	std::size_t *use; //counter
};

inline void swap (HasPtr& lhs, HasPtr& rhs) {
	using std::swap;
	std::swap (lhs.ps, rhs.ps);
	std::swap (lhs.i, rhs.i);
}

HasPtr::~HasPtr() {
	if (--(*use) == 0) {
		delete ps;
		delete use;
	}
}

//std::string *ps; ps(new std::string(s));
/*HasPtr& HasPtr::operator= (const HasPtr &rhs)
{
	auto newp = new std::string( *(rhs.ps) );
	delete ps;
	ps = newp;
	i = rhs.i;
	return *this;
}*/

//std::string *ps; ps(new std::string(s));
//std::size_t *use; use(new std::size_t(1));
/*HasPtr& HasPtr::operator= (const HasPtr &rhs)
{
	++(*(rhs.use)); //括号可以不用添加, 添加是为了清晰
	if (--(*use) == 0) {
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}*/

HasPtr& HasPtr::operator= (HasPtr rhs) {
	using std::swap;
	swap(*this, rhs);
	return *this;
}

int main (void) {

	return 0;
}
