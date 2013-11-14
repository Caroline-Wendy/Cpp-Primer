/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.11.6
 *      Author: C.L.Wang
 */

/*eclipse cdt*/

#include <iostream>

#include <vector>
#include <string>
#include <initializer_list>

#include <memory>

#include <cstddef>
#include <stdexcept>

using namespace std;

class StrBlobPtr;

class StrBlob {
        friend class StrBlobPtr;
        public:
                typedef std::vector<std::string>::size_type size_type;
                StrBlob();
                StrBlob(std::initializer_list<std::string> il);
                size_type size() const{ return data->size(); }
                bool empty() const { return data->empty(); }
                void push_back(const std::string& t) { data->push_back(t); }
                void pop_back();
                std::string& front() ;
                std::string& back() ;
                StrBlobPtr begin();
                StrBlobPtr end();
        private:
                std::shared_ptr<std::vector<std::string> > data;
                void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {
        public:
                StrBlobPtr() : curr(0) {}
                StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
                std::string& deref() const;
                StrBlobPtr& incr();
                StrBlobPtr& operator++ ();
                StrBlobPtr& operator-- ();
                StrBlobPtr operator++ (int);
                StrBlobPtr operator-- (int);
                std::string& operator* () const;
                std::string* operator->() const;
        private:
                std::shared_ptr<std::vector<std::string> >
                check(std::size_t, const std::string&) const;
                std::weak_ptr<std::vector<std::string> > wptr;
                std::size_t curr;
};

StrBlob::StrBlob():data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il):
                data(std::make_shared< std::vector<std::string> >(il)) {}
void StrBlob::check(size_type i, const std::string &msg) const {
        if(i >= data->size())
                throw out_of_range(msg);
}
std::string& StrBlob::front () {
        check(0, "front on empty StrBlob");
        return data->front();
}
std::string& StrBlob::back () {
        check(0, "back on empty StrBlob");
        return data->back();
}
void StrBlob::pop_back () {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
}
StrBlobPtr StrBlob::begin() {
        return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
}

std::shared_ptr<std::vector<std::string> >
StrBlobPtr::check(std::size_t i, const std::string& msg) const {
        auto ret = wptr.lock();
        if (!ret)
                throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size())
                throw std::out_of_range(msg);
        return ret;
}
std::string& StrBlobPtr::deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
}
StrBlobPtr& StrBlobPtr::operator++ () {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}
StrBlobPtr& StrBlobPtr::operator-- () {
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}
StrBlobPtr StrBlobPtr::operator++ (int) {
	StrBlobPtr ret = *this;
	++*this; //使用预先定义的前置操作符, 进行检查
	return ret;
}
StrBlobPtr StrBlobPtr::operator-- (int) {
	StrBlobPtr ret = *this;
	--*this;
	return ret;
}

std::string& StrBlobPtr::operator* () const {
	auto p = check (curr, "dereference past end");
	return (*p)[curr];
}
std::string* StrBlobPtr::operator-> () const {
	std::cout << "->" << std::endl;
	return &this->operator *();
}

int main (void) {

        StrBlob b1;
        //{}释放b2
        {
                StrBlob b2 = {"baby", "girl", "lady", "woman", "female"};
                b1 = b2;
                b2.push_back("pretty");
        }
        std::cout << "b1 size = " << b1.size() << std::endl;
        //b2已经被释放了
        std::cout << "b1.begin() = " << b1.begin().deref() << std::endl;
        std::cout << "b1.begin().incr().deref() = "
                        << b1.begin().incr().deref() << std::endl;
        std::cout << "++b1.begin() = " << (++b1.begin()).deref() << std::endl;
        std::cout << "--b1.end() = " << (--b1.end()).deref() << std::endl;

        StrBlobPtr p (b1);
        *p = "Cross-Dressing";
        std::cout << "the first element size : " << (p.operator->())->size()<< std::endl;
        std::cout << "the first element size : " << p->size() << std::endl;
        std::cout << "the first element size : "  <<(*p).size() << std::endl;


        return 0;

}