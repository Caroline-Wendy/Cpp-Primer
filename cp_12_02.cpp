/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.11.2
 *      Author: C.L.Wang
 */

/*eclipse cdt*/

#include <iostream>

#include <vector>
#include <string>
#include <initializer_list>

#include <memory>

#include <stdexcept>

using namespace std;

class StrBlob {
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
		std::shared_ptr<std::vector<std::string> > data; //test
	private:
		//std::shared_ptr<std::vector<std::string> > data;
		void check(size_type i, const std::string &msg) const;
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
int main (void) {
	StrBlob b1;
	//{}释放b2
	//{
		StrBlob b2 = {"a", "an", "the"};
		b1 = b2;
		b2.push_back("about");
	//}
	std::cout << "b1 size = " << b1.size() << std::endl;
	std::cout << "b1 data use count = " << b1.data.use_count() << std::endl;
	//b2已经被释放了
	//std::cout << "b2 size = " << b2.size() << std::endl;
	return 0;
}
