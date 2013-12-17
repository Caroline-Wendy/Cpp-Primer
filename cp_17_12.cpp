/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.28
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	std::fstream inOut("copyOut", std::fstream::ate/*末尾*/ | std::fstream::in | std::fstream::out);
	if(!inOut) {
		std::cerr << "Unable to open file! " << std::endl;
		return EXIT_FAILURE;
	}
	std::fstream::pos_type end_mark = inOut.tellg();
	inOut.seekg(0, std::fstream::beg); //重定位在起点
	std::size_t cnt(0);
	std::string line;
	while (inOut && inOut.tellg() != end_mark &&
			getline(inOut, line))
	{
		cnt += line.size() + 1;
		std::fstream::pos_type mark = inOut.tellg(); //记住当前位置
		inOut.seekp(0, std::fstream::end); //跳至末尾
		inOut << cnt;
		if (mark != end_mark) inOut << " "; //除了最后一行, 均写入空格
		inOut.seekg(mark); //回到记录的地点
	}
	inOut.seekp(0, std::fstream::end);
	inOut << "\n";
	return 0;
}



















