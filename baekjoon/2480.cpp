// 주사위 세개
// 사칙연산

#include <iostream>

int cnt[6] = {0}; // 각 눈금 별 나온 횟수 저장

int main(){
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	int inp;
	
	for(int i = 0; i < 3; i++){
		std::cin >> inp;
		
		cnt[inp-1] += 1;
	}
	
	for(int i = 0; i < 6; i++){
		if(cnt[i] == 3){
			std::cout << 10000+(i+1)*1000 << '\n';
			return 0;
		} else if (cnt[i] == 2){
			std::cout << 1000 + (i+1)*100 << '\n';
			return 0;
		}
	}
	
	for(int i = 5; i >= 0; i--){
		if(cnt[i]){
			std::cout << (i+1)*100 << '\n';
			return 0;
		}
	}
	
}