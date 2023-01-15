// 보안 업체
// 다이나믹 프로그래밍 & 누적 합
// top-down

// 명우가 지나가는 곳은 어차피 순찰이 되는 것이므로
// 이미 지나친 상점은 계산이 다 되어 있음 

// 따라서 i점포와 j점포의 순찰이 끝났다면 i ~ j까지의 순찰이 모두 완료된 것이고
// 현재 명우의 위치는 i 또는 j임

#include <iostream>
#include <string.h>
#include <algorithm>

typedef long long ll;

int T;
int N, a;
// dp[i][j][f] :: i ~ j 까지의 순찰이 끝났을 때, 민우가 f위치에 있는 경우의 답 
// f가 0이면 left, 1이면 right에 위치한 것
ll dp[101][101][2];
ll prefixSum[101]; // 각 상점의 거리 누적합

ll solve(int left, int right, int dong){
    if(left == 1 && right == N){
        // 순찰이 모두 끝남
        return 0;
    }

    ll &res = dp[left][right][dong];

    if(res != -1){
        // 그 전 계산 값이 있다면
        return res;
    } else {
        int now = dong ? right : left;

        res = 1e12;

        // 아직 순찰이 끝나지 않은 점포 개수
        ll curWaitingNum = N - right + left - 1;

        if(1 < left){ 
            // 왼쪽 순찰 가능
            res = std::min(res, solve(left - 1, right, 0) + curWaitingNum * (prefixSum[now] - prefixSum[left-1]));
        }
        if(right < N){
            // 오른쪽 순찰 가능
            res = std::min(res, solve(left, right + 1, 1) + curWaitingNum*(prefixSum[right + 1] - prefixSum[now]));
        }

        return res;
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        memset(dp, -1, sizeof(dp));
        memset(prefixSum, 0, sizeof(prefixSum));

        std::cin >> N >> a;

        for(int i = 2; i <= N; i++){
            std::cin >> prefixSum[i];
            prefixSum[i] += prefixSum[i-1];
        }

        std::cout << solve(a, a, 0) << '\n';
    }

    return 0;
}