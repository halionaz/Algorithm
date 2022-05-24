// 카드 구매하기 2
// 다이나믹 프로그래밍

#include <iostream>
#include <algorithm>

int N;
int P[1001], dp[1001];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 1; i <= N; i++){
        std::cin >> P[i];
    }

    for(int i = 1; i <= N; i++){
        dp[i] = P[i];
        for(int j = 1; j <= i; j++){
            dp[i] = std::min(dp[i], dp[i- j] + P[j]);
        }
    }

    std::cout << dp[N] << '\n';

    return 0;
}