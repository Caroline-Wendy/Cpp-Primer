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

class Bulk_quote final : public Quote { //final限定词, 无法被继承
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string&book, double p, std::size_t qty, double disc) :
		Quote(book, p), min_qty(qty), discount(disc) {} //使用基类的构造器
	double net_price(std::size_t cnt) const override;
private:
	std::size_t min_qty = 0; //折扣的最小量
	double discount = 0.0; //折扣
};
double Bulk_quote::net_price(std::size_t cnt) const
{
	if (cnt >= min_qty)
		return cnt * (1-discount) * price;
	else
		return cnt * price;
}
int main (void) {

	Quote q("CppPrimer", 99);
	Bulk_quote bq("CppPrimer", 99, 10, 0.5);
	std::size_t n = 20;
	std::cout << "We want to buy " << n << " books. " << std::endl;
	std::cout << "Quote net_price : " << q.net_price(n) << std::endl;
	std::cout << "Bulk_quote net_price : " << bq.net_price(n) << std::endl;

	return 0;

}
