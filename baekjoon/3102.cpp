// 겹치지 않는 원
// 다이나믹 프로그래밍
// bottom-up

#include <iostream>

int N;
// arr[i][j] :: i-j를 지름으로 하는 원의 유무 판단
bool arr[301][301];
// dp[i][j] :: i~j 범위에서 겹치지 않는 원의 개수
int dp[301][301];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        int c, r;
        std::cin >> c >> r;
        arr[c-r+100][c+r+100] = true; // 양수로 만들기 위해 100을 더함
    }

    for(int i = 1; i <= 300; i++){
        for(int j = i; j >= 1; j--){
            // j~i 원 내부 탐색
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