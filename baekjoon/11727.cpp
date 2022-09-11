// 2xn 타일링 2
// 다이나믹 프로그래밍
// bottom-up

#include <iostream>

int N;
int dp[1001];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= N; i++){
        dp[i] = (dp[i-1] + dp[i-2]*2)%10007;
    }

    std::cout << dp[N] << '\n';

    return 0;
}