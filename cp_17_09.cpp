#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <cmath>


using namespace std;

bool play (bool first) {
	std::default_random_engine e;
	std::bernoulli_distribution b(0.6); //获胜概率较大
	bool win = b(e);
	if(first) //我们获胜的概率大
		return win;
	else
		return !win;
}

int main()
{
	std::string resp;
	std::default_random_engine e;
	std::bernoulli_distribution b;
	do {
		bool first = b(e); //伯努利生产器
		std::cout << (first ? "We go first" : "You get to go first") << std::endl; //判断先后手
		std::cout << ((play(first)) ? "congrats, you won" : "sorry, you lost") << std::endl;
		std::cout << "play again? Enter 'yes' or 'no' " << std::endl;
	} while (std::cin >>resp && resp[0] == 'y');
	return 0;
}
