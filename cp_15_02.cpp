/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.11.12
 *      Author: Caroline
 */

/*eclipse cdt*/

#include <iostream>
#include <string>
#include <cstddef>

using namespace std;

class Quote {
public:
	Quote() = default;
	Quote (const std::string& book, double sales_price) :
		bookNo (book), price (sales_price) {}
	std::string isbn() const { return bookNo; }
	virtual double net_price (std::size_t n) const { return n* price; } //虚函数
	virtual ~Quote() = default; //动态绑定析构器
private:
	std::string bookNo;
protected: //受保护类型
	double price = 0.0;
};

class Disc_quote : public Quote { //抽象基类
public:
	Disc_quote() = default;
	Disc_quote (const std::string& book, double price, std::size_t qty, double disc) :
		Quote(book, price), quantity (qty), discount (disc) {}
	double net_price (std::size_t) const = 0; //纯虚函数
protected:
		std::size_t quantity = 0;
		double discount = 0.0;
};

class Bulk_quote final : public Disc_quote { //final限定词, 无法被继承
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string&book, double p, std::size_t qty, double disc) :
		Disc_quote(book, p, qty, disc) {} //使用基类的构造器
	double net_price(std::size_t cnt) const override;
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

	Quote q("CppPrimer", 99);
	Bulk_quote bq("CppPrimer", 99, 10, 0.5);
	Quote& rq = bq;
	std::size_t n = 20;
	std::cout << "We want to buy " << n << " books. " << std::endl;
	std::cout << "Quote net_price : " << q.net_price(n) << std::endl;
	std::cout << "Bulk_quote net_price : " << bq.net_price(n) << std::endl;
	std::cout << "R Quote net_price : " << rq.net_price(n) << std::endl;

	//动态绑定
	Quote base("EffectiveCpp", 50);
	print_total(cout, base, 10);
	Bulk_quote derived("EffectiveCpp", 50, 5, .19);
	print_total(cout, derived, 10);

	//复制-赋值操作, 派生类->基类转换
	base = derived;
	std::cout << "net_price : " << base.net_price(20) << std::endl;

	double undiscounted = derived.Quote::net_price(20); //派生类使用基类的虚函数
	std::cout << "undiscounted : " << undiscounted << std::endl;
	return 0;

}
