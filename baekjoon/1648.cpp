// 격자판 채우기
// 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍

#include <iostream>
#include <cstring>

const int mod = 9901;

int N,M;
// dp[i][j] :: 타일의 i번째 칸을 보고 있을 때, i-1번째 칸까지는 다 채웠고,
// i ~ i + M -1 까지의 칸이 j 상태인 경우의 수
int dp[14*14][1 << 14]; 

int solve(int tile, int bit){

    if(tile == N*M && !bit){
        // 현재 마지막 칸을 보고 있으며, 앞으로의 칸이 비어있다면(0) 답을 return
        return 1;
    } else {
        if(tile >= N*M){
            // 마지막 칸이 넘었음에도, 앞으로의 칸이 남아있는 경우이므로 답이 없음
            return 0;
        } else {

            if(dp[tile][bit] != -1){

                return dp[tile][bit];
                
            } else {

                dp[tile][bit] = 0;

                if(bit & 1){
                    // 현재 칸이 차 있음, 따라서 놓지 못함
                    dp[tile][bit] += solve(tile+1, bit >> 1);
                } else {
                    // 현재 칸이 비어있으므로, 두가지 방법으로 놓을 수 있음

                    // 세로로 놓을 때
                    dp[tile][bit] += solve(tile+1, (bit >> 1) | (1 << (M-1)));

                    if(tile % M != M-1 && !(bit & 2)){
                        // 현재 타일이 마지막 칸이 아니고, 그 다음칸이 비어있을 때
                        // 가로로 놓을 수 있음
                        dp[tile][bit] += solve(tile+2, bit>>2);
                    }
                }
                return dp[tile][bit] %= mod;
            }
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    memset(dp,-1,sizeof(dp));

    std::cin >> N >> M;

    std::cout << solve(0,0) << '\n';

    return 0;
}