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
#include <set>

#include <utility>
#include <memory>
#include <cstddef>

using namespace std;

class Quote;

class Quote {
public:
	Quote() = default;
	Quote (const std::string& book, double sales_price) :
		bookNo (book), price (sales_price) {}
	void add_item (const Quote& sale);
	std::string isbn() const { return bookNo; }
	virtual double net_price (std::size_t n) const { return n* price; } //虚函数
	virtual Quote* clone() const & {return new Quote(*this);}
	virtual Quote* clone() && {return new Quote(std::move(*this));}
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
	Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :
		Disc_quote(book, p, qty, disc) {} //使用基类的构造器
	double net_price(std::size_t cnt) const override;
	virtual Bulk_quote* clone() const & {return new Bulk_quote(*this);}
	virtual Bulk_quote* clone() && {return new Bulk_quote(std::move(*this));}
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

class Basket {
public:
	void add_item (const std::shared_ptr<Quote> &sale) { items.insert(sale); }
	void add_item (const Quote& sale)
	{
		//items.insert(std::shared_ptr<Quote>(new Quote(sale))); //不会动态绑定
		items.insert(std::shared_ptr<Quote>(sale.clone()));
	}
	void add_item (Quote&& sale)
	{
		//items.insert(std::shared_ptr<Quote>(new Quote(std::move(sale)))); //不会动态绑定
		items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
	}
	double total_reciept (std::ostream&) const;
private:
	static bool compare (const std::shared_ptr<Quote> &lhs,
			const std::shared_ptr<Quote> &rhs)
	{ return lhs->isbn() < rhs->isbn(); };
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double Basket::total_reciept(std::ostream &os) const
{
	double sum = 0.0;
	for(auto iter = items.cbegin(); iter != items.cend();
			iter = items.upper_bound(*iter)) { //跳过同名书, 直接计算count
		sum += print_total(os, **iter, items.count(*iter)); //*it是shared_ptr; **it是object
	}
	os << "Total Sale: " << sum << std::endl;
	return sum;
}

int main (void) {

	Basket bsk;
	/*bsk.add_item(std::make_shared<Quote>("CppPrimer", 45));
	bsk.add_item(std::make_shared<Bulk_quote>("EffectiveCpp", 50, 2, 0.15));
	bsk.add_item(std::make_shared<Bulk_quote>("EffectiveCpp", 50, 2, 0.15));
	bsk.add_item(std::make_shared<Bulk_quote>("EffectiveCpp", 50, 2, 0.15));*/

	bsk.add_item(Quote("CppPrimer", 45));
	bsk.add_item(Bulk_quote("EffectiveCpp", 50, 2, 0.15));
	bsk.add_item(Bulk_quote("EffectiveCpp", 50, 2, 0.15));
	bsk.add_item(Bulk_quote("EffectiveCpp", 50, 2, 0.15));

	bsk.total_reciept(std::cout);

	return 0;

}
