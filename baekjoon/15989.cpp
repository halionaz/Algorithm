// 1, 2, 3 더하기 4
// 다이나믹 프로그래밍

// 합을 이루는 숫자가 순서만 다르면 같은 것으로 치므로
// 숫자가 오름차순으로 더해진 경우의 수를 구해야 함
// 따라서 기존 dp를 3개로 나누어, 1로 끝나는 경우, 2로 끝나는 경우, 3으로 끝나는 경우를 각각 카운트

#include <iostream>

int dp[10001][4];
int T, n;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    dp[1][1] = 1; // 1
    dp[2][1] = 1; // 1+1
    dp[2][2] = 1; // 2
    dp[3][1] = 1; // 1+1+1
    dp[3][2] = 1; // 1+2
    dp[3][3] = 1; // 3

    for(int i = 4; i <= 10000; i++){
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }

    std::cin >> T;

    while(T--){
        std::cin >> n;
        std::cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
    }

    return 0;
}