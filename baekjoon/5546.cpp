// 파스타
// 다이나믹 프로그래밍
// bottom-up

#include <iostream>

const int mod = 10000;

int N, K, A, B;
int plan[101];
int dp[101][6];
// dp[i][0] :: i번째 날에 1번 파스타 1일차
// dp[i][1] :: i번째 날에 2번 파스타 1일차
// dp[i][2] :: i번째 날에 3번 파스타 1일차
// dp[i][3] :: i번째 날에 1번 파스타 2일차
// dp[i][4] :: i번째 날에 2번 파스타 2일차
// dp[i][5] :: i번째 날에 3번 파스타 2일차

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> K;

    for(int i = 0; i < K; i++){
        std::cin >> A >> B;
        plan[A] = B;
    }

    // 1일차 업데이트
    if(plan[1]){
        // 첫째 날에 계획이 있음
        if(plan[1] == 1){
            dp[1][0] = 1;
        } else if(plan[1] == 2){
            dp[1][1] = 1;
        } else if(plan[1] == 3){
            dp[1][2] = 1;
        }
    } else {
        // 첫째날에 계획이 없으므로 3개 파스타 다 가능
        dp[1][0] = dp[1][1] = dp[1][2] = 1;
    }

    for(int i = 2; i <= N; i++){
        if(plan[i] == 0){
            // 이 날짜에 계획이 없음
            dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4] + dp[i-1][5]) % mod;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2] + dp[i-1][3] + dp[i-1][5]) % mod;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4]) % mod;
            dp[i][3] = dp[i-1][0];
            dp[i][4] = dp[i-1][1];
            dp[i][5] = dp[i-1][2];
        } else {
            if(plan[i] == 1){
                dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4] + dp[i-1][5]) % mod;
                dp[i][3] = dp[i-1][0];
            } else if(plan[i] == 2){
                dp[i][1] = (dp[i-1][0] + dp[i-1][2] + dp[i-1][3] + dp[i-1][5]) % mod;
                dp[i][4] = dp[i-1][1];
            } else {
                dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4]) % mod;
                dp[i][5] = dp[i-1][2];
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 6; i++){
        ans += dp[N][i];
        ans %= mod;
    }

    std::cout << ans << '\n';

    return 0;
}