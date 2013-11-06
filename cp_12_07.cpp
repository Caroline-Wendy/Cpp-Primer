/*
 * CppPrimer.cpp
 *
 *  Created on: 2013.11.6
 *      Author: Caroline
 */

/*eclipse cdt*/

#include <iostream>

#include <vector>
#include <string>

#include <memory>
#include <new>

#include <cstddef>

using namespace std;

int main (void) {

	int ia[5] = {1, 2, 3, 4, 5};
	std::cout << "begin : " << *begin(ia) << std::endl;
	const int n=5;
	int *pia = new int [n]{1, 2, 3, 4, 5};
	for(int* q = pia; q !=pia+n; ++q)
		std::cout << *q << " ";
	std::cout << std::endl;

	std::cout << "unique_ptr : ";
	std::unique_ptr<int[]> up(pia);
	for(std::size_t i=0; i != 5; i++){
		std::cout << up[i] << " ";
	}
	std::cout << std::endl;
	up.release();

	std::cout << "shared_ptr : ";
	std::shared_ptr<int> sp(pia, [](int* p) { delete[] p; });
	for(std::size_t i=0; i != 5; i++){
			std::cout << *(sp.get()+i) << " ";
	}
	std::cout << std::endl;
	sp.reset();

	delete[] pia;
	pia = nullptr;

	std::allocator<std::string> alloc;
	auto const p = alloc.allocate(n); //n=5
	alloc.construct(p, "girl");
	alloc.construct(p+1, "boy");
	alloc.construct(p+2, "hi");
	alloc.construct(p+3, "hi");
	alloc.construct(p+4, "hi");
	std::cout << *p << std::endl;
	std::cout << *(p+1) << std::endl;

	std::allocator<int> alloci;
	std::vector<int> vi = {0, 1, 2, 3, 4, 5, 6};
	auto pa = alloci.allocator(vi.size() * 2);
	auto qa = std::uninitialized_copy(vi.begin(), vi.end(), pa);
	std::uninitialized_fill_n(qa, vi.size(), 42);

	for(auto i=alloci.begin(); i != alloci.end(); i++)

	return 0;

}
