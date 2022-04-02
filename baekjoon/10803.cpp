// 정사각형 만들기
// 다이나믹 프로그래밍

#include <iostream>
#include <algorithm>
#include <cstring>

int N, M;
int dp[101][10001];

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

    ret = r*l;

    if(l >= 3*r){
        ret = std::min(ret, solve(r, l-r) + 1);
    } else {
        for(int i = 1; i <= r / 2; i++){
            ret = std::min(ret, solve(r - i, l) + solve(i, l));
        }
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