// 타일 채우기
// 다이나믹 프로그래밍

// Top-Down 방식

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
            ret = solve(cur-1, 0) + solve(cur-2,0) + solve(cur-1,3) + solve(cur-1, 12) + solve(cur-1,9);
            break;
        case 3:
            ret = solve(cur-1,0) + solve(cur-1, 12);
            break;
        case 6:
            ret = solve(cur-1,9);
            break;
        case 9:
            ret = solve(cur-1,6) + solve(cur-1, 0);
            break;
        case 12:
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

// 반복문

// #include <iostream>
// #include <cstring>

// int T, N;
// int dp[600][1<<4];

// int main(){

//     std::ios_base::sync_with_stdio(0);
//     std::cin.tie(0);

//     memset(dp, -1, sizeof(dp));

//     std::cin >> T;

//     dp[0][0] = 1;
//     dp[1][0] = 1;
//     dp[1][3] = 1;
//     dp[1][6] = 0;
//     dp[1][9] = 1;
//     dp[1][12] = 1;

//     for(int cur = 2; cur < 600; cur++){

//         for(int state = 0; state <= 12; state += 3){

//             int &ret = dp[cur][state];
            
//             switch(state){
//                 case 0:
//                     ret = dp[cur-1][0] + dp[cur-2][0] + dp[cur-1][3] + dp[cur-1][12] + dp[cur-1][9];
//                     break;
//                 case 3:
//                     ret = dp[cur-1][0] + dp[cur-1][12];
//                     break;
//                 case 6:
//                     ret = dp[cur-1][9];
//                     break;
//                 case 9:
//                     ret = dp[cur-1][6] + dp[cur-1][0];
//                     break;
//                 case 12:
//                     ret = dp[cur-1][0] + dp[cur-1][3];
//                     break;
//             }
            
//         }

//     }

//     while(T--){
//         std::cin >> N;

//         std::cout << dp[N][0] << '\n';

//     }

//     return 0;
// }