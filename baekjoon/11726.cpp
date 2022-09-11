// 2xn 타일링
// 다이나믹 프로그래밍
// bottom-up

#include <iostream>
#define mod 10007
int dp[1001];
int n;
int main(){
    std::cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < n+1; i++){
        dp[i] = (dp[i-1]+dp[i-2])%mod;
    }
    std::cout << dp[n] << '\n';
    return 0;
}