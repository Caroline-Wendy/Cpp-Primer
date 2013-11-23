/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.21
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <vector>
#include <initializer_list>
#include <memory>
#include <cstddef>

template <typename T> class BlobPtr;
template <typename T> class Blob;

/*Blob: Binary Large OBject*/
template <typename T> class Blob {
	friend class BlobPtr<T>;
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	Blob ();
	Blob (std::initializer_list<T> il); //可以使用初始化列表, {}
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back (const T &t) { data->push_back(t); }
	void push_back (T &&t) { data->push_back(std::move(t)); } //右值操作
	void pop_back ();
	T& back ();
	T& operator[] (size_type i) ;
private:
	std::shared_ptr<std::vector<T> > data;
	void check (size_type i, const std::string &msg) const; //验证给定的索引
};

template <typename T>
Blob<T>::Blob () : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob (std::initializer_list<T> il) :
        data(std::make_shared< std::vector<T> >(il)) {}

/*验证给定的索引*/
template <typename T>
void Blob<T>::check (size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range (msg); //抛出异常
}

template <typename T>
T& Blob<T>::back ()
{
	check (0, "back on empty Blob");
	return data->back ();
}

template <typename T>
T& Blob<T>::operator[] (size_type i)
{
	check (i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back ()
{
	check (0, "pop_back on empty Blob");
	data->pob_back ();
}

template <typename T>
class BlobPtr {
public:
	BlobPtr () : curr (0) {}
	BlobPtr (Blob<T> &a, size_t sz=0) : wptr(a.data), curr (sz) {}
	T& operator* () const {
		auto p = check (curr, "dereference past end");
		return (*p) [curr];
	}
	BlobPtr& operator++ (); //前缀操作符
	BlobPtr& operator-- ();
	BlobPtr operator++ (int); //后缀操作符
	BlobPtr operator-- (int);
private:
	std::shared_ptr<std::vector<T>> check (std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

template <typename T>
std::shared_ptr<std::vector<T>>
BlobPtr<T>::check (std::size_t i, const std::string& msg) const
{
	auto ret = wptr.lock (); //判断wptr是否绑定了Blob
	if (!ret)
		throw std::runtime_error ("unbound BlobPtr");
	if (i >= ret->size ())
		throw std::out_of_range (msg);
	return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++ () {
	check (curr, "increment past end of BlobPtr"); //先判断后加
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator-- () {
	--curr; //先减之后, 如果为0, 再减就是大整数
	check (curr, "decrement past begin of BlobPtr"); //先减后判断
	return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator ++(int)
{
	BlobPtr ret = *this;
	++*this; //使用重载的前缀++
	return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator --(int)
{
	BlobPtr ret = *this;
	--*this; //使用重载的前缀--
	return ret;
}

int main (void) {
	std::cout << "Hello Mystra!" << std::endl;
	Blob<int> ia;
	Blob<int> ia2 = {0, 1, 2, 3, 4};
	std::cout << "ia2[2] = " << ia2[2] << std::endl;
	BlobPtr<int> pia = ia2;
	std::cout << "*(++pia) = " << *(++pia) << std::endl;
	return 0;
}
