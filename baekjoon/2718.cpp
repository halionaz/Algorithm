// 타일 채우기
// 다이나믹 프로그래밍 & 비트마스킹
// top-down

#include <iostream>
#include <cstring>

int T, N;
int dp[600][1<<4];

int solve(int cur, int state){

    if(cur < 0){
        return 0;
    }
    if(cur == 0){
        return state == 0;
        // state가 비어있다면 1, 그렇지 않다면 0 반환
    }

    int &ret = dp[cur][state];

    if(ret != -1){
        return ret;
    }

    switch(state){
        case 0:
            // 0000
            ret = solve(cur-1, 0) + solve(cur-2,0) + solve(cur-1,3) + solve(cur-1, 12) + solve(cur-1,9);
            break;
        case 3:
            // 0011
            ret = solve(cur-1,0) + solve(cur-1, 12);
            break;
        case 6:
            // 0110
            ret = solve(cur-1,9);
            break;
        case 9:
            // 1001
            ret = solve(cur-1,6) + solve(cur-1, 0);
            break;
        case 12:
            // 1100
            ret = solve(cur-1, 0) + solve(cur-1, 3);
            break;
    }

    return ret;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(dp, -1, sizeof(dp));

    std::cin >> T;

    while(T--){
        std::cin >> N;

        std::cout << solve(N, 0) << '\n';

    }

    return 0;
}