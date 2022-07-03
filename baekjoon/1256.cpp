// 사전
// 다이나믹 프로그래밍 & 조합론

#include <iostream>
#include <string.h>

typedef long long ll;

const ll inf = 0x3f3f3f3f3f3f3f3f;

int N, M;
ll K;
ll dp[251][151]; // dp[n][r] : nCr

ll combDp(int n, int r){
    //nCr
    if(n == r || r == 0){
        return 1;
    }
    ll &ret = dp[n][r];
    if(ret != -1){
        return ret;
    }

    // 이항 정리에 따라
    // nCr = (n-1)C(r-1) + (n-1)Cr
    ll a = combDp(n-1, r-1);
    ll b = combDp(n-1, r);

    if(a + b > 1000000000){
        ret = inf;
    } else {
        ret = a + b;
    }

    return ret;
}

void simulate(int n, int m, ll rest){

    ll c = combDp(n+m-1, n-1);
    if(n > 0 && rest <= c){
        std::cout << 'a';
        simulate(n-1, m, rest);
    } else if(m > 0){
        std::cout << 'z';
        simulate(n, m-1, rest - c);
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    for(int i = 0; i < 251; i++){
        for(int j = 0; j < 151; j++){
            dp[i][j] = -1;
        }
    }

    std::cin >> N >> M >> K;

    if(combDp(N+M, N) < K){
        std::cout << -1 << '\n';
    } else {
        simulate(N, M, K);
        std::cout << '\n';
    }

    return 0;
}