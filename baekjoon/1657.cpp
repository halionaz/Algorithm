// 두부장수 장홍준
// 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍

#include <iostream>
#include <cstring>

const int intMax = 14;
const int min = -500000;

int N, M;
char rate[intMax*intMax];
int dp[intMax*intMax][1 << intMax];
int price[6][6] = {{10,8,7,5,0,1},{8,6,4,3,0,1},{7,4,3,2,0,1},{5,3,2,2,0,1},{0,0,0,0,0,0},{1,1,1,1,0,0}};


int max(int a, int b){
    return a > b ? a : b;
}

int solve(int tile, int bit){
    if(tile == N*M && !bit){
        return 0;
    }else {
        if(tile >= N*M){
            return min;
        } else {
            int &val = dp[tile][bit];
            if(val != -1){
                return val;
            } else {

                val = solve(tile+1,bit >> 1);


                if(!(bit & 1)){
                    // 세로로 놓을 때
                    if(tile+M < N*M){
                        val = max(val,solve(tile+1,(bit>>1)|(1<<(M-1))) + price[rate[tile]-'A'][rate[tile+M]-'A']);
                    }
                    if(tile % M != M-1 && !(bit & 2)){
                        val = max(val, solve(tile+2,bit >> 2) + price[rate[tile]-'A'][rate[tile+1]-'A']);
                    }
                }

                return val;

            }
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    memset(dp,-1,sizeof(dp));

    std::cin >> N >> M;

    for(int i = 0; i < N*M; i++){
        std::cin >> rate[i];
    }

    std::cout << solve(0,0) << '\n';

    return 0;
}