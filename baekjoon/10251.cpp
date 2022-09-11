// 운전 면허 시험
// 다이나믹 프로그래밍
// bottom-up

#include <iostream>
#include <cstring>
#include <algorithm>

int T, M, N, L, G;
int dp[101][101][250][2];
// dp[i][j][k][l], i행 j열에서 k번 방향을 전환했고 l을 바라보고 있을 때 최소 연료
int costR[101][101];
int costD[101][101];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        memset(dp,1000001,sizeof(dp));
        dp[0][0][0][0] = dp[0][0][0][1] = 0;

        std::cin >> N >> M >> L >> G;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M-1; j++){
                std::cin >> costR[i][j];
            }
        }
        for(int i = 0; i < N - 1; i++){
            for(int j = 0; j < M; j++){
                std::cin >> costD[i][j];
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                for(int k = 0; k < 250; k++){
                    if(i + 1 < N){
                        // (i+1,j)이고, 전 좌표부터 방향 전환 없음
                        dp[i+1][j][k][0] = std::min(dp[i+1][j][k][0], dp[i][j][k][0] + costD[i][j]);
                        // (i+1,j)이고, 전 좌표에서 방향 전환함
                        dp[i+1][j][k+1][0] = std::min(dp[i+1][j][k+1][0], dp[i][j][k][1] + costD[i][j]);
                    }
                    if(j + 1 < M){
                        dp[i][j+1][k][1] = std::min(dp[i][j+1][k][1], dp[i][j][k][1] + costR[i][j]);
                        dp[i][j+1][k+1][1] = std::min(dp[i][j+1][k+1][1], dp[i][j][k][0] + costR[i][j]);
                    }
                }
            }
        }

        int ans = 999999999;

        for(int k = 0; k < 250; k++){
            int t = L*(N+M-2) + k;
            if(dp[N-1][M-1][k][0] <= G){
                ans = std::min(ans, t);
            }
            if(dp[N-1][M-1][k][1] <= G){
                ans = std::min(ans, t);
            }
        }
        if(ans == 999999999){
            std::cout << -1 << '\n';
        } else {
            std::cout << ans << '\n';
        }
    }

    return 0;
}