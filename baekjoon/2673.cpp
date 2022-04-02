// 교차하지 않는 원의 현들의 최대 집합
// 다이나믹 프로그래밍

#include <iostream>
#include <algorithm>

int N;
int dp[101][101];
// dp[i][j] :: i ~ j까지 중 교차하지 않는 현의 최댓값
bool arr[101][101];
// arr[i][j] :: i와 j를 잇는 현이 존재하는가

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        int x, y;
        std::cin >> x >> y;
        arr[x][y] = arr[y][x] = true;
    }

    for(int i = 1; i <= 100; i++){
        for(int j = i; j >= 1; j--){
            for(int k = j; k < i; k++){
                dp[j][i] = std::max(dp[j][i], dp[j][k] + dp[k][i] + arr[j][i]);
            }
        }
    }

    std::cout << dp[1][100] << '\n';

    return 0;
}