/*C++ Primer ������ ���*/

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

int main(void){

	int ia[] = {0, 2, 4, 6, 8};
	int last = *(ia+4);
	int last_2 = *ia +4;

	std::cout << "last = " << last << std::endl;
	std::cout << "last_2 = " << last_2 << std::endl;

	/*��������Ϊ1*/
	int i(0);
	std::cout << i << " " << ++i << std::endl;

	/*bool���޷���*/
	bool b(true);
	bool b2 = -b;
	std::cout << "b2 = " << b2 << std::endl;

	/*����wrapped around*/
	short short_value(32767);
	short_value++;
	std::cout << "short_value: " << short_value << std::endl;

	return 0;

}