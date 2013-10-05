/*C++ Primer µÚÈıÕÂ Ëæ±Ê*/

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

int main(void){

	std::string s("Hello World! ");
	std::cout << "s = " << s << std::endl;

	const char* str = s.c_str();
	std::cout << "str = " << str << std::endl;

	std::string s_2= "Sorry!";
	s += s_2;
	std::cout << "s = " << s << std::endl;
	std::cout << "str = " << str << std::endl;

	int int_arr[] = {0, 1, 2, 3, 4, 5};
	std::vector<int> ivec(int_arr+1, int_arr+4);

	std::cout << "ivec = " << std::endl;
	for(unsigned int i=0; i<ivec.size(); i++){
		std::cout << std::setw(4) << ivec[i] << std::endl;
	}

	int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	for(auto p=ia; p!=ia+3; p++)
		for(auto q=*p; q!=*p+4; ++q)
			std::cout << *q << ' ';
	std::cout << std::endl;

	for(auto p=std::begin(ia); p!=std::end(ia); p++)
		for(auto q=std::begin(*p); q!=std::end(*p); ++q)
			std::cout << *q << ' ';
	std::cout << std::endl;

	return 0;

}