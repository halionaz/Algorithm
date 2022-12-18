// 카우버거 알바생
// 다이나믹 프로그래밍 & 배낭 문제
// bottom-up

#include <iostream>
#include <algorithm>

int N, M, K;
int dp[101][301][301];
// dp[i][j][k] :: i번째 주문까지 봤고, j개의 치즈버거, k개의 감자튀김이 있을 때 받을 수 있는 최대 주문량
int order[101][2];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M >> K;

    for(int i = 1; i <= N; i++){
        std::cin >> order[i][0] >> order[i][1];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            for(int k = 1; k <= K; k++){
                if(order[i][0] <= j && order[i][1] <= k){
                    // 이 주문 받을 여지 있음
                    // 이 주문을 안 받는 것 vs 주문을 받는 경우의 수 중 큰 것 저장
                    dp[i][j][k] = std::max(dp[i-1][j][k], dp[i-1][j - order[i][0]][k - order[i][1]] + 1);
                } else {
                    // 이 주문은 현재 조건에서 절대 못 받음
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
    }

    std::cout << dp[N][M][K] << '\n';

    return 0;
}