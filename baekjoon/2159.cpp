// 케익 배달
// 다이나믹 프로그래밍

#include <cstdlib>
#include <iostream>
#include <utility>
#include <string.h>
#include <algorithm>

typedef long long ll;
typedef std::pair<int, int> pii;

const int intinf = 1e9;
const ll llinf = 1e18;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

int N;
ll dp[100001][5]; //dp[i][j] :: i번째 인덱스 배달, 인덱스 배달할 때 j위치를 거칠 때, 배달하는 최단 거리
pii pos[100001][5]; // i번째 인덱스의 j위치 좌표

int dist(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

ll dfsDP(int cur, int dir){

    if(cur == N){
        return 0;
    }

    ll &ret = dp[cur][dir];

    if(ret != -1){
        return ret;
    }

    ret = llinf;

    for(int i = 0; i < 5; i++){
        if(pos[cur+1][i].first != intinf){
            // 다음 주문 순번의 i번째 좌표가 유효함
            ret = std::min(ret, dfsDP(cur+1, i) + dist(pos[cur][dir].first, pos[cur][dir].second, pos[cur+1][i].first, pos[cur+1][i].second));
        }
    }

    return ret;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(dp, -1, sizeof(dp));

    std::cin >> N;

    std::cin >> pos[0][0].first >> pos[0][0].second;

    for(int i = 1; i <= N; i++){

        std::cin >> pos[i][0].first >> pos[i][0].second;

        // 5개 위치 모두 저장
        for(int j = 0; j < 4; j++){

            int newX = pos[i][0].first + dx[j];
            int newY = pos[i][0].second + dy[j];

            if(1 <= newX && newX <= 100000 && 1 <= newY && newY <= 100000){
                // 좌표 유효
                pos[i][j+1].first = newX;
                pos[i][j+1].second = newY;
            } else {
                // 좌표 무효
                pos[i][j+1].first = intinf;
                pos[i][j+1].second = intinf;
            }
        }

    }

    std::cout << dfsDP(0,0) << '\n';

    return 0;
}