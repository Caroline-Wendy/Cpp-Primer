/*Programme from C++ Primer, By C.L.Wang*/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

int main(void) {

	/*String数字类型转换*/
	std::string str_dec = "2001, A Space Odyssey";
	std::string str_hex = "40c3";
	std::string str_bin = "-10010110001";
	std::string str_auto = "0x7f";
	std::string::size_type sz;   // alias of size_t
	int i_dec = std::stoi (str_dec,&sz);
	int i_hex = std::stoi (str_hex,nullptr,16);
	int i_bin = std::stoi (str_bin,nullptr,2);
	int i_auto = std::stoi (str_auto,nullptr,0);
	std::cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
	std::cout << str_hex << ": " << i_hex << '\n';
	std::cout << str_bin << ": " << i_bin << '\n';
	std::cout << str_auto << ": " << i_auto << '\n';

	/*stack和priority_queue的用法*/
	std::stack<int> intStack;
	for(size_t ix=0; ix != 10; ix++)
		intStack.push(ix);
	while(!intStack.empty()){
		int value = intStack.top();
		std::cout << " value = " << value << std::endl;
		intStack.pop();
	}
	std::priority_queue<int, vector<int>, std::greater<int>>  intPQueue;
	intPQueue.push( 3 );
	intPQueue.push( 5 );
	intPQueue.push( 2 );
	intPQueue.push( 4 );
	while( !intPQueue.empty() ){
		int pvalue = intPQueue.top();
		std::cout << " pvalue = " << pvalue << std::endl;
		intPQueue.pop(); 
	}

	return 0;

}