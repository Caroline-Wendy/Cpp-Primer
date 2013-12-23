/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.28
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.8.1*/

/* setlocale example */
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class out_of_stock : public std::runtime_error
{
public:
	//初始化基类的runtime_error
	explicit out_of_stock(const std::string &s) : std::runtime_error(s) {}
};

class id_mismatch : public std::logic_error
{
public:
	explicit id_mismatch(const std::string &s) : std::logic_error(s) {}
	id_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs) :
		std::logic_error(s), left(lhs), right(rhs) {}
	const std::string left, right;
};

struct My_food
{
	My_food(const std::string fi, const int fn) : food_id(fi), food_num(fn) {}
	My_food& operator+=(const My_food& rhs);
	std::string food_id;
	int food_num;
};

My_food& My_food::operator+=(const My_food& rhs)
{
	if(this->food_id != rhs.food_id)
		throw id_mismatch("wrong id", this->food_id, rhs.food_id);
	this->food_num += rhs.food_num;
	return *this;
}

int main (void)
{
	My_food M1("Apple", 3), M2("Pear", 2), M3("Apple", 2);
	try{
		M1 += M3;
		std::cout << M1.food_id << ":" << M1.food_num << std::endl;
		M1 += M2;
	}catch(const id_mismatch &e){
		std::cerr << e.what() << ": left id("
				<< e.left <<") right id(" << e.right << ")" << std::endl;
	}
}















