// Four Squares
// 다이나믹 프로그래밍

#include <iostream>
#include <algorithm>

int N;
int dp[50001];

int main(){

    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::cin >> N;

    dp[1] = 1;

    for(int i = 2; i <= N; i++){
        int min = 5;
        for(int j = 1; j*j <= i; j++){
            min = std::min(min, dp[i - j*j]);
        }

        dp[i] = min + 1;
    }

    std::cout << dp[N] << '\n';

    return 0;
}