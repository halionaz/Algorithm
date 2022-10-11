// 가로등 끄기
// 다이나믹 프로그래밍 & 누적 합
// top-down

// 어차피 마징가가 불을 끄는 시간은 0초이므로
// 지나치는 모든 가로등을 끄는 것으로 상정

// 따라서 i와 j 가로등이 꺼져있다면 i~j의 가로등은 모두 꺼져있을 것이며,
// 현재 마징가의 위치는 i 또는 j임


#include <iostream>
#include <vector>
#include <cstring>

typedef long long ll;

int N, M;
// dp[i][j][f] :: i~j 까지의 가로등이 꺼졌을 때, 마징가가 f위치에 있는 경우의 답 
// f가 0이면 left, 1이면 right에 위치한 것
ll dp[1002][1002][2]; 
std::vector<ll> pos; // 각 가로등 인덱스의 위치 저장
std::vector<ll> cost; // 각 가로등 전력 소비량 저장
std::vector<ll> sum; // 0 ~ i 전력 소비량 누적합 저장

int solve(int left, int right, int fb){
    if(left == 1 && right == N){
        // 모두 다 끈 상태이면
        return 0;
    }
    ll &res = dp[left][right][fb];
    if(res != -1){
        return res;
    } else {
        ll minimum;
        int cur = fb ? right : left;
        ll curCost = sum[N] - sum[right] + sum[left - 1]; // 현재 켜져있는 가로등의 초당 전력소비량
        if(left - 1 >= 1){
            minimum = solve(left - 1, right, 0) + (pos[cur] - pos[left-1]) * curCost;
            if(res == -1 || minimum < res){
                res = minimum;
            }
        }
        if(right + 1 <= N){
            minimum = solve(left, right + 1, 1) + (pos[right + 1] - pos[cur]) * curCost;
            if(res == -1 || minimum < res){
                res = minimum;
            }
        }
        return res;
    }
}

int main(){
    
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    memset(dp,-1,sizeof(dp));
    pos.resize(N + 1);
    cost.resize(N + 1);
    sum.resize(N + 1);

    for(int i = 1; i <= N; i++){
        std::cin >> pos[i] >> cost[i];
        sum[i] = sum[i-1] + cost[i]; // 비용 누적합
    }

    std::cout << solve(M, M, 0) << '\n';

    return 0;
}