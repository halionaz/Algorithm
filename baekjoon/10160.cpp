// 암호
// 다이나믹 프로그래밍
// bottom-up

// 생각하기 조금 빡셌던 DP 문제
// dp[i] = dp[i-1]*K - dp[i-5]*2 + dp[i-7]
// K개의 문자를 쓸 수 있으므로, dp[i-1]에 K를 곱하면 됨
// 단 ABCBC와 ABABC로 끝나는 경우를 제외해야 하므로 dp[i-5]에서 2를 곱한걸 뺌

// 여기서 ~AB ABCBC인 경우가 빠지게 됨
// 하지만 dp[i-1]에는 ~AB ABCB가 있을 수 없음
// 중간에 ABABC가 포함 되기 때문
// 따라서 dp[i-7]*1 (마지막이 ABABC인 경우)를 더해서
// 쓸데 없이 뺀걸 다시 더해줌

#include <iostream>

typedef long long ll;

const ll mod = 1000000009;

ll N,K;
ll dp[1000001];
// dp[i], 길이가 i인 안전한 문자열의 개수

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> K;

    dp[0] = 1;
    for(int i = 1; i < 5; i++){
        dp[i] = dp[i-1]*K;
    }
    dp[5] = dp[4]*K - (ll)2; // ABCBC, ABABC 제외
    dp[6] = (dp[5]*K - dp[1]*(ll)2) % mod;
    // + mod를 해주는 이유는, 만약 계산한 값이 음수가 나오는 경우를 대비
    for(int i = 7; i <= N; i++){
        dp[i] = (dp[i-1]*K - dp[i-5]*(ll)2 + dp[i-7]) % mod;
        if(dp[i] < 0) dp[i] += mod;
    }
    std::cout << dp[N]%mod << '\n';
    return 0;
}