// 뮤탈리스크
// 다이나믹 프로그래밍

#include <iostream>
#include <algorithm>
#include <string.h>

int N;
int hp[3];
int dp[61][61][61]; // dp[i][j][k], scv 체력이 i, j, k 남았을 때 공격 횟수

int attack(int a, int b, int c){
    if(a < 0){
        // a가 죽었으면
        return attack(0, b, c);
    }
    if(b < 0){
        return attack(a, 0, c);
    }
    if(c < 0){
        return attack(a, b, 0);
    }

    if(a == 0 && b == 0 && c == 0){
        // 전멸
        return 0;
    }

    int &cur = dp[a][b][c];

    if(cur == -1){
        cur = std::min({
            attack(a-9,b-3,c-1) + 1,
            attack(a-9,b-1,c-3) + 1,
            attack(a-3,b-9,c-1) + 1,
            attack(a-3,b-1,c-9) + 1,
            attack(a-1,b-9,c-3) + 1,
            attack(a-1,b-3,c-9) + 1
        });

    }

    return cur;


}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(dp, -1, sizeof(dp));

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> hp[i];
    }

    std::cout << attack(hp[0], hp[1], hp[2]) << '\n';

    return 0;
}