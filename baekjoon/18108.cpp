// 1998년생인 내가 태국에서는 2541년생?!
// 사칙연산

#include <iostream>

int y;

int main(){
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	std::cin >> y;
	
	std::cout << y - 543 << '\n';
	
	return 0;
}