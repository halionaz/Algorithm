// RGB거리 2
// 다이나믹 프로그래밍
// bottom-up

// 원형 DP

#include <iostream>
#include <algorithm>

const int inf = 10000000;
int cost[1001][3];
int dp[1001][3];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int N;
    std::cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            std::cin >> cost[i][j];
        }
    }

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