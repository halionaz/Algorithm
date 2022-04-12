// 조별과제를 하려는데 조장이 사라졌다
// 사칙연산

#include <iostream>

int L;

int main(){
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	std::cin >> L;
	
	if(L % 5 == 0){
		std::cout << L / 5 << '\n';
	} else {
		std::cout << L / 5 + 1 << '\n';
	}
	
	return 0;
}