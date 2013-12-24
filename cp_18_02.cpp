/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.28
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <string>

namespace A{
	class C {
		friend void f2(){
			std::cout << "This f2..." << std::endl;
		}
		friend void f(const C&){
			std::cout << "This f..." << std::endl;
		}
	};
}

int main (void)
{
	A::C cobj;
	f(cobj); //可以通过实参依赖(Argument-Dependent)找到
	//f2(); //无法找到, 或使用A::
}















