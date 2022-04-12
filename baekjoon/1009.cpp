// 분산처리
// 구현

#include <iostream>

int T, a, b;

int main(){
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	std::cin >> T;
	
	for(int i = 0; i < T; i++){
		
		int cur = 1;
		
		std::cin >> a >> b;
		
		for(int j = 0; j < b; j++){
			cur *= a;
			cur %= 10;
		}
		
		if(cur == 0){
			cur = 10;
		}
		
		std::cout << cur << '\n';
	}
	
	return 0;
}