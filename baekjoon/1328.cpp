// 고층 빌딩
// 다이나믹 프로그래밍

#include <iostream>

typedef long long ll;

const ll mod = 1000000007;
int N,L,R;
ll dp[101][101][101] = {0,};
// dp[i][j][k] :: i개의 건물, 왼쪽에서 j개, 오른쪽에서 k개 보일때의 경우의 수

int main(){

    std::cin >> N >> L >> R;

    dp[1][1][1] = 1;

    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= L; j++){
            for(int k = 1; k <= R; k++){
                dp[i][j][k] = (dp[i-1][j-1][k] + dp[i-1][j][k-1] + dp[i-1][j][k]*(i-2))%mod;
            }
        }
    }

    std::cout << dp[N][L][R] << '\n';

    return 0;
}