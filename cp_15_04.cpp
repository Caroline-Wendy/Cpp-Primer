/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.11.12
 *      Author: Caroline
 */

/*eclipse cdt*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstddef>

using namespace std;

class Quote {
public:
	//Quote() = default;
	Quote() {
		std::cout << "this is Quote constructor" << std::endl;
	}
	Quote (const std::string& book, double sales_price) :
		bookNo (book), price (sales_price) {}
	std::string isbn() const { return bookNo; }
	virtual double net_price (std::size_t n) const { return n* price; } //虚函数
	//virtual ~Quote() = default; //动态绑定析构器
	virtual ~Quote() {
		std::cout << "this is Quote destructor" << std::endl;
	}
private:
	std::string bookNo;
protected: //受保护类型
	double price = 0.0;
};

class Disc_quote : public Quote { //抽象基类
public:
	//Disc_quote() = default;
	Disc_quote() {
		std::cout << "this is Disc_quote constructor" << std::endl;
	}
	Disc_quote (const std::string& book, double price, std::size_t qty, double disc) :
		Quote(book, price), quantity (qty), discount (disc) {}
	double net_price (std::size_t) const = 0; //纯虚函数
	virtual ~Disc_quote() override{
		std::cout << "this is Disc_quote destructor" << std::endl;
	}
protected:
		std::size_t quantity = 0;
		double discount = 0.0;
};

class Bulk_quote final : public Disc_quote { //final限定词, 无法被继承
public:
	//Bulk_quote() = default;
	Bulk_quote() {
		std::cout << "this is Bulk_quote constructor" << std::endl;
	}
	Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :
		Disc_quote(book, p, qty, disc) {} //使用基类的构造器
	double net_price(std::size_t cnt) const override;
	virtual ~Bulk_quote() override{
		std::cout << "this is Bulk_quote destructor" << std::endl;
	}
};

double Bulk_quote::net_price(std::size_t cnt) const
{
	if (cnt >= quantity)
		return cnt * (1-discount) * price;
	else
		return cnt * price;
}

double print_total(std::ostream &os, const Quote& item, std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

int main (void) {

	Bulk_quote* bq = new Bulk_quote;
	delete bq;

	return 0;

}
