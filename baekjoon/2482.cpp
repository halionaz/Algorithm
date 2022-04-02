// 색상환
// 다이나믹 프로그래밍

#include <iostream>

int main(){
    int N,K;
    std::cin >> N >> K;
    if(K>N-2){
        std::cout << 0 << '\n';
        return 0;
    } else {
        int dp[1001][1001];
        // dp[i][j] i개 색상환일때, j가지 색을 뽑는 경우의 수
        for(int i = 0; i<=N; i++){
            dp[i][0] = 1;
            dp[i][1] = i;
        }
        for(int i = 2; i<=N; i++){
            for(int j = 2; j<=K; j++){
                dp[i][j] = (dp[i-2][j-1] + dp[i-1][j])%1000000003;
            }
        }
        std::cout << (dp[N-3][K-1] + dp[N-1][K])%1000000003 << '\n';
    }
}