// 색상환
// 다이나믹 프로그래밍
// bottom-up

#include <iostream>

const int mod = 1000000003;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int N, K;
    std::cin >> N >> K;

    if(K > N-2){
        // K개의 조합 중 무조건 근접하는 색이 나오므로 
        // 고를 수 있는 경우의 수가 없음
        std::cout << 0 << '\n';
        return 0;
    } else {
        int dp[1001][1001];
        // dp[i][j] i개 색상환일때, j가지 색을 뽑는 경우의 수

        // 일단 선형으로 생각하자
        for(int i = 0; i <= N; i++){
            dp[i][0] = 1;
            dp[i][1] = i;
        }
        for(int i = 2; i<=N; i++){
            for(int j = 2; j<=K; j++){
                // i개 색이 있을 때, 이중 j를 인접하지 않게 뽑는 경우의 수는
                // i-2개 색이 있을 때, 이중 j-1개를 인접하지 않게 뽑고, i번째 색을 뽑는 경우
                // +
                // i-1개 색이 있을 때, 이중 j개를 인접하지 않게 뽑고, i번째 색을 뽑지 않는 경우
                dp[i][j] = (dp[i-2][j-1] + dp[i-1][j])%mod;
            }
        }

        // 다만 색상환은 "환형" 이므로
        // N번째 색을 뽑지 않는 경우는 N-1개 색이 있을 때, K개를 인접하지 않게 뽑는 경우이고
        // N번째 색을 뽑는 경우는 1번째 칸도, N-1번째 칸도 뽑으면 안되므로, N-3개 색에서 K-1개를 인접하지 않게 뽑는 경우임
        std::cout << (dp[N-3][K-1] + dp[N-1][K])%mod << '\n';
    }

    return 0;
}