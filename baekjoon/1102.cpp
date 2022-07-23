// 발전소
// 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍

#include <iostream>
#include <algorithm>
#include <cstring>

int N, P;
int cost[16][16];
int dp[1 << 16];

int solve(int onCnt, int curBit){
    if(onCnt == P){
        return 0;
    } else {
        if(dp[curBit] != -1){
            return dp[curBit];
        } else {
            dp[curBit] = 999999999;
            for(int i = 0; i < N; i++){
                if(curBit & (1 << i)){
                    // 켜져 있다면
                    for(int j = 0; j < N; j++){
                        if(i!=j && !(curBit & (1<<j))){
                            // 안 켜져 있는 j 발전소를 i 발전소로 키는 경우 계산
                            dp[curBit] = std::min(dp[curBit], cost[i][j] + solve(onCnt+1, curBit | (1<<j)));
                        }
                    }
                }
            }
            return dp[curBit];
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(dp, -1, sizeof(dp));

    std::cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> cost[i][j];
        }
    }

    int onCnt = 0; // 켜져있는 발전소 개수
    int curBit = 0; // 발전소 on/off 여부 표시 bit

    for(int i = 0; i < N; i++){
        char inp;
        std::cin >> inp;
        if(inp == 'Y'){
            onCnt++;
            curBit = curBit | (1 << i);
        }
    }

    std::cin >> P;

    if(onCnt){
        if(onCnt >= P){
            // 이미 필요 이상의 발전소가 켜져있음
            std::cout << 0 << '\n';
        } else {
            std::cout << solve(onCnt, curBit) << '\n';
        }
    } else {
        if(P){
            // 처음에 켜져있는 발전소는 없는데 켜져야할 발전소는 1이상임
            // 불가능
            std::cout << -1 <<'\n';
        } else {
            // 발전소 못키긴 하는데 키지 않아도 됨
            std::cout << 0 << '\n';
        }
    }


    return 0;
}