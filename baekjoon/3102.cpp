// 겹치지 않는 원
// 다이나믹 프로그래밍

#include <iostream>

int N;
bool arr[301][301];
int dp[301][301];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        int c, r;
        std::cin >> c >> r;
        arr[c-r+100][c+r+100] = true;
    }

    for(int i = 1; i <= 300; i++){
        for(int j = i; j >= 1; j--){
            for(int k = j; k < i; k++){
                if(dp[j][k] + dp[k][i] + arr[j][i] > dp[j][i]){
                    dp[j][i] = dp[j][k] + dp[k][i] + arr[j][i];
                }
            }
        }
    }

    std::cout << N - dp[1][300] << '\n';

    return 0;
}