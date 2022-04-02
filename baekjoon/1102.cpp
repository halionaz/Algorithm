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

    int onCnt = 0;
    int curBit = 0;

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
            std::cout << 0 << '\n';
        } else {
            std::cout << solve(onCnt, curBit) << '\n';
        }
    } else {
        if(P){
            std::cout << -1 <<'\n';
        } else {
            std::cout << 0 << '\n';
        }
    }


    return 0;
}