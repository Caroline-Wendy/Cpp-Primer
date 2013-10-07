/*Programme from C++ Primer, By C.L.Wang*/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[]){

	/*ָ������ת��*/
	int ia[5] = {1, 2, 3, 4, 5};
	int* ip = ia;
	std::cout << "*ip = " << *ip << std::endl;

	/*ָ��Ϊ��, ���ܽ�����*/
	/*ip = nullptr;
	std::cout << "*ip = " << *ip << std::endl;*/

	/*constָ�������ת��*/
	int i(0);
	const int &j = i;
	const int *p = &i;
	i = 2;
	std::cout << "j = " << j << std::endl;
	std::cout << "*p = " << *p << std::endl;
	/*int& r = j*/

	/*�����������ض�, ����û�о���*/
	int ii(3), ij(2);
	double slope = static_cast<double>(ii)/ij;
	std::cout << "slope = " << slope << std::endl;

	/*static_cast<type>*/
	double d(12.0);
	void* pp = &d;	//�޷����
	double* dp = static_cast<double*>(pp);
	std::cout << "*dp = " << *dp << std::endl;

	/*�ı�const����(ָ��\����), const_cast<type>*/
	const int ww(10);
	int* kk = const_cast<int*>(&ww);
	*kk += 20;
	std::cout << "ww  = " << ww  << std::endl;
	std::cout << "*kk  = " << *kk  << std::endl;

	/*reinterpret_cast<type>���½���*/
	int a_tt(97);
	char* a_pp = reinterpret_cast<char*>(&a_tt);
	std::cout << "*a_pp  = " << *a_pp  << std::endl;
	std::string str(a_pp);
	std::cout << "str  = " << str  << std::endl;

	return 0;

}