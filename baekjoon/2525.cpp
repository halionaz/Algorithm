// 오븐 시계
// 사칙연산

#include <iostream>

int main(){
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	int A,B,C;
	
	std::cin >> A >> B;
	std::cin >> C;
	
	B += C;
	
	while(B >= 60){
		A += 1;
		B -= 60;
	}

	while(A >= 24){
		A -= 24;
	}
	
	std::cout << A << ' ' << B << '\n';
	
	return 0;
}