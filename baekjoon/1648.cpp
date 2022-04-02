// 격자판 채우기
// 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍

#include <iostream>
#include <cstring>

const int mod = 9901;

int N,M;
int dp[14*14][1 << 14];

int solve(int tile, int bit){

    if(tile == N*M && !bit){
        return 1;
    } else {
        if(tile >= N*M){
            return 0;
        } else {

            if(dp[tile][bit] != -1){

                return dp[tile][bit];
                
            } else {

                dp[tile][bit] = 0;

                if(bit & 1){
                    dp[tile][bit] += solve(tile+1, bit >> 1);
                    // 못 놓을 때
                } else {

                    dp[tile][bit] += solve(tile+1, (bit >> 1) | (1 << (M-1)));
                    // 세로로 놓을 때

                    if(tile % M != M-1 && !(bit & 2)){
                        dp[tile][bit] += solve(tile+2, bit>>2);
                        // 가로로 놓을 때
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