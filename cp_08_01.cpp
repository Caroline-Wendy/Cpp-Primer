/*Programme from C++ Primer, By C.L.Wang*/
/*Some examples from http://www.cplusplus.com/reference/ios */
#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(void){

	/*IO库状态基本用法*/
	char buffer[80] = "Girls Generation";
	ofstream ofs;
	ifstream ifs;
	ofs.open ("test.txt", fstream::out); 
	ofs << "Hello World";
	if ( (ofs.rdstate() & ifstream::failbit) != 0) //检查错误位
		std::cerr << "Error opening 'test.txt'. " << std::endl;
	ofs.close();
	ifs.open("test.txt", fstream::in);
	ifs.getline(buffer, 80);
	std::cout << buffer << " : Read from file successfully. " << std::endl;
	ifs.close();

	/*tie的用法*/
	std::ostream *prevstr;
	ofs.open ("test.txt");
	std::cout << "tie example:\n";
	*std::cin.tie(&cout) << "This is inserted into cout";
	prevstr = std::cin.tie (&ofs);
	*std::cin.tie(prevstr) << "This is inserted into the file";
	ofs.close();

	return 0;
}