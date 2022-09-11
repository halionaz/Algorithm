// 그림 교환
// 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍
// top-down

#include <iostream>
#include <algorithm>

int N;
int cost[16][16];
int dp[16][1 << 17][10]; // dp[i][j][k], i번에게 그림이 있고, j만큼 돌았으며, k가 마지막 거래 금액일 때 거쳐간 인원 수 최댓값

int solve(int cur, int curBit, int lastCost){
    int &res = dp[cur][curBit][lastCost];
    if(curBit == (1 << N) - 1){
        // 모든 사람이 그림을 소유했던 적이 있으므로 더 이상의 탐색 불필요
        return res = 1;
    } else {
        if(res != 0){
            return res;
        } else {
            res = 1;
            for(int i = 0; i < N; i++){
                if((curBit & (1<<i)) == 0 && i != cur && cost[cur][i] >= lastCost){
                    res = std::max(res, 1 + solve(i, (curBit|(1<<i)), cost[cur][i]));
                }
            }
            return res;
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char inp;
            std::cin >> inp;
            cost[i][j] = (int)inp;
        }
    }

    std::cout << solve(0, 1, 0) << '\n';

    return 0;
}