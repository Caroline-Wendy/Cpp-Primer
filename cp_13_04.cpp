/*
 * HelloWorld.cpp
 *
 *  Created on: 2013.11.7
 *      Author: Caroline
 */

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <cstddef>

class StrVec {
public:
	StrVec () : elements (nullptr), first_free (nullptr), cap (nullptr) {}
	StrVec (const StrVec&);
	StrVec &operator= (const StrVec&);
	~StrVec();
	void push_back (const std::string &);
	size_t size () const { return first_free-elements; }
	size_t capacity () const { return cap-elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }
private:
	static std::allocator<std::string> alloc;
	void free();
	void reallocate();
	void chk_n_alloc () {
		if(size() == capacity())
			reallocate();
	}
	std::pair<std::string*, std::string*> alloc_n_copy
	(const std::string*, const std::string*);
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};
void StrVec::reallocate () {
	auto newcapacity = size() ? 2*size() : 1; //正常2倍, 为空分配一个
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (std::size_t i=0; i!=size(); ++i)
		alloc.construct(dest++, std::move(*elem++)); //每个元素均移动
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

std::allocator<std::string> StrVec::alloc; //需要初始化

void StrVec::push_back(const std::string& s)
{
	chk_n_alloc ();
	alloc.construct(first_free++, s); //注意后++
}
std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e-b); //分配足够的空间
	return {data, std::uninitialized_copy(b, e, data)}; //把数据存入空间, 返回首尾指针
}
void StrVec::free ()
{
	if (elements) {
		for (auto p=first_free; p!=elements;)
			alloc.destroy(--p); //先--, 指向确定元素
		alloc.deallocate(elements, cap-elements); //释放内存, 首元素和内存大小
	}
}
StrVec::StrVec (const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end()); //pair类型
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec::~StrVec() { free(); }
StrVec &StrVec::operator= (const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free ();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
int main (void) {
	StrVec sv;
	sv.push_back("Girls");
	sv.push_back("Ladies");
	sv.push_back("Women");
	for(auto it = sv.begin(); it != sv.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	return 0;
}



