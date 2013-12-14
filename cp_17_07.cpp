#include <iostream>
#include <vector>
#include <string>
#include <random>


using namespace std;

std::vector<unsigned> good_randVec()
{
	static std::default_random_engine e; //静态
	static std::uniform_int_distribution<unsigned> u(0,9); //静态
	std::vector<unsigned> ret;
	for(size_t i=0; i<10; ++i)
		ret.push_back(u(e));
	return ret;
}

int main()
{
	std::default_random_engine e;
	std::cout << "engine : ";
	for(size_t i=0; i<10; ++i)
		std::cout << e() << " ";
	std::cout << std::endl;

	std::cout << "uniform : ";
	std::uniform_int_distribution<unsigned> u(0, 9); //即[0, 9]
	for(size_t i=0; i<10; ++i)
		std::cout << u(e) << " ";
	std::cout << std::endl;

	std::cout << "min : " << e.min() << " max : " << e.max() << std::endl;

	std::vector<unsigned> v1(good_randVec());
	std::vector<unsigned> v2(good_randVec());
	for(size_t i=0; i<v1.size(); ++i)
		std::cout << v1[i] << " ";
	std::cout << std::endl;
	for(size_t i=0; i<v2.size(); ++i)
		std::cout << v2[i] << " ";
	std::cout << std::endl;

	std::uniform_real_distribution<double> ud(0, 1);
	std::cout << "float : ";
	for(size_t i=0; i<10; ++i)
		std::cout << ud(e) << " ";
	std::cout << std::endl;

	return 0;
}
