// 정사각형 만들기
// 다이나믹 프로그래밍 & 그리디 알고리즘

#include <iostream>
#include <algorithm>
#include <cstring>

int N, M;
int dp[101][10001]; // dp[i][j] :: i * j 크기 직사각형 종이를 갈라 만들 수 있는 최소 정사각형 수

int solve(int r, int l){
    if(r > l){
        return solve(l, r);
    }
    if(l % r == 0){
        return l / r;
    }

    int &ret = dp[r][l];

    if(ret != -1){
        return ret;
    }

    ret = r*l; // 최대로 많은 양, 넓이 1짜리 정사각형 개수

    if(l >= 3*r){
        ret = std::min(ret, solve(r, l-r) + 1);
    } else {
        // l 고정, 가로축으로 쪼개기
        for(int i = 1; i <= r / 2; i++){
            ret = std::min(ret, solve(r - i, l) + solve(i, l));
        }
        // r 고정, 세로축으로 쪼개기
        for(int i = 1; i <= l / 2; i++){
            ret = std::min(ret, solve(r, l - i) + solve(r, i));
        }
    }

    return ret;

}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(dp, -1, sizeof(dp));

    std::cin >> N >> M;

    std::cout << solve(N, M) << '\n';

    return 0;
}