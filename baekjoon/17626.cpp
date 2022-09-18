// Four Squares
// 다이나믹 프로그래밍
// bottom-up

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
        // 무조건 4개 이하의 합으로 정리되므로, 5로 초기화 한 후 갱신
        int min = 5;
        for(int j = 1; j*j <= i; j++){
            min = std::min(min, dp[i - j*j]);
        }

        dp[i] = min + 1;
    }

    std::cout << dp[N] << '\n';

    return 0;
}