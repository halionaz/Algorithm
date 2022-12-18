// 1, 2, 3 더하기
// 다이나믹 프로그래밍
// bottom-up

#include <iostream>

int T,n;
int dp[12] = {0,1,2,4};

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    for(int i = 4; i < 12; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
    while(T--){
        std::cin >> n;
        std::cout << dp[n] << '\n';
    }
}