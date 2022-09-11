// 퇴사 2
// 다이나믹 프로그래밍
// bottom-up

#include <iostream>
#include <algorithm>

int N;
int dp[1500002]; // dp[i] :: i일까지 상담원으로 있을 때, 낼 수 있는 최대 이익
int T[1500002];
int P[1500002];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 1; i <= N; i++){
        std::cin >> T[i] >> P[i];
    }

    for(int i = N; i > 0; i--){
        if(i + T[i] > N + 1){
            dp[i] = dp[i+1];
        } else {
            dp[i] = std::max(dp[i+1], dp[i+T[i]] + P[i]);
        }
    }

    std::cout << dp[1] << '\n';

    return 0;
}