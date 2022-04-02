// 산책
// 다이나믹 프로그래밍

#include <iostream>

int H,W,N;
bool arr[1003][1003];
int dp[1003][1003];

void dfs(int i, int j){

    if(i > H || j > W){
        std::cout << i << ' ' << j << '\n';
    } else {
        if(arr[i][j]){
            // 오른쪽
            dfs(i,j+1);
        } else {
            dfs(i+1,j);
        }
    }

}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> H >> W >> N;

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            std::cin >> arr[i][j];
        }
    }

    dp[1][1] = N - 1; // N-1의 시행까지 (1,1)을 들른 횟수는 N-1

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            dp[i+1][j] += dp[i][j]/2;
            dp[i][j+1] += dp[i][j]/2;
            if(dp[i][j]%2){
                if(arr[i][j]){
                    // 오른쪽
                    dp[i][j+1] += 1;
                } else {
                    // 아래쪽
                    dp[i+1][j] += 1;
                }

                // N-1번까지 이 교차로를 들른 횟수가 홀수
                arr[i][j] = !arr[i][j];
            } 
        }
    }

    dfs(1,1);

    return 0;
}