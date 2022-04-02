// RGB거리 2
// 다이나믹 프로그래밍

// 원형 DP

#include <iostream>
#include <algorithm>
const int inf = 10000000;
int main(){
    int N;
    std::cin >> N;
    int cost[N][3];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            std::cin >> cost[i][j];
        }
    }
    int dp[N][3];
    int ans = inf;
    for(int k = 0; k < 3; k++){
        for(int i = 0; i < 3; i++){
            if(i==k){
                dp[0][i] = cost[0][i];
            } else {
                dp[0][i] = inf;
            }
        }
        for(int i = 1; i < N; i++){
            dp[i][0] = std::min(dp[i-1][1],dp[i-1][2])+cost[i][0];
            dp[i][1] = std::min(dp[i-1][0],dp[i-1][2])+cost[i][1];
            dp[i][2] = std::min(dp[i-1][0],dp[i-1][1])+cost[i][2];
        }
        for(int i = 0; i<3; i++){
            if(i!=k){
                ans = std::min(ans,dp[N-1][i]);
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}