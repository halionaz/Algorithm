// 두부장수 장홍준
// 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍
// top-down

// 1648, 격자판 채우기와 비슷한 아이디어

#include <iostream>
#include <cstring>

const int intMax = 14;
const int min = -500000;

int N, M;
char rate[intMax*intMax]; // 각 칸의 등급 저장

int dp[intMax*intMax][1 << intMax];
// dp[i][j] :: 타일의 i번째 칸을 보고 있을 때, i-1번째 칸까지는 다 채웠고,
// i ~ i + M -1 까지의 칸이 j 상태인 경우의 수

// 등급 별 가격 저장
int price[6][6] = {{10,8,7,5,0,1},{8,6,4,3,0,1},{7,4,3,2,0,1},{5,3,2,2,0,1},{0,0,0,0,0,0},{1,1,1,1,0,0}};


int max(int a, int b){
    return a > b ? a : b;
}

int solve(int tile, int bit){
    if(tile == N*M && !bit){
        // 마지막 칸을 보고 있고, 앞으로의 칸이 비어있다면(0) 점수 계산 시작
        return 0;
    }else {
        if(tile >= N*M){
            // 마지막 칸을 넘었음에도, 앞으로의 칸이 남아있는 경우이므로 답이 없음
            return min;
        } else {

            int &val = dp[tile][bit];

            if(val != -1){

                return val;

            } else {
                
                // 일단 현재 칸을 신경쓰지 않고, 다음 칸을 놓는 경우 탐색
                val = solve(tile+1,bit >> 1);

                if(!(bit & 1)){
                    // 현재 칸이 비어있을 때

                    // 세로로 놓을 때
                    if(tile + M < N*M){
                        val = max(val,solve(tile+1,(bit>>1)|(1<<(M-1))) + price[rate[tile]-'A'][rate[tile+M]-'A']);
                    }
                    // 가로로 놓을 때
                    if(tile % M != M-1 && !(bit & 2)){
                        // 현재 타일이 줄의 마지막 칸이 아니고, 그 다음 칸이 비어있을 때
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