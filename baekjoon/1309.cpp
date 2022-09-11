// 동물원
// 다이나믹 프로그래밍
// bottom-up

#include <iostream>

int N, mod = 9901;
int dp[100001][3]; 
// dp[i][0] :: i번째 칸에 사자가 없는 경우, i번째 칸까지 채우는 경우의 수
// dp[i][1] :: i번째 칸의 오른쪽에 사자가 있는 경우, i번째 칸까지 채우는 경우의 수
// dp[i][2] :: i번째 칸의 왼쪽에 사자가 있는 경우, i번째 칸까지 채우는 경우의 수

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    for(int i = 2; i <= N; i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1])%mod;
    }

    std::cout << (dp[N][0] + dp[N][1] + dp[N][2])%mod << '\n';

    return 0;
}