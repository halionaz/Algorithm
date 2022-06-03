// 알고리즘 수업 - 피보나치 수 1
// 수학

#include <iostream>

typedef long long ll;

int n;
ll dp[41]; // 재귀식 풀이 방법의 코드 실행 횟수 저장

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;

    dp[1] = 1; dp[2] = 1;

    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    std::cout << dp[n] << ' ' << n-2 << '\n';

    return 0;
}