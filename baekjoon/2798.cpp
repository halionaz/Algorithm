// 블랙잭
// 브루트포스 알고리즘

#include <iostream>

int ans = 0;
int N, M;
int card[100];

int main(){
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	std::cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		std::cin >> card[i];
	}
	
	for(int i = 0; i < N - 2; i++){
		for(int j = i + 1; j < N - 1; j++){
			for(int l = j + 1; l < N; l++){
				int cur = card[i] + card[j] + card[l];
				if(cur <= M && M - cur < M - ans){
					ans = cur;
				}
			}
		}
	}
	
	std::cout << ans << '\n';
	
	return 0;
}