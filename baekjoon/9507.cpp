// Generations of Tribbles
// 다이나믹 프로그래밍

#include <iostream>
typedef long long ll;

int T, n;
ll dp[68];

ll fib(int N){
    if(N < 2){
        return dp[N] = 1;
    } else if (N == 2){
        return dp[2] = 2;
    } else if (N == 3){
        return dp[3] = 4;
    } else {

        ll &ret = dp[N];

        if(ret != 0){
            return ret;
        } 
        
        return dp[N] = fib(N-1) + fib(N-2) + fib(N-3) + fib(N-4);
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    fib(67);

    while(T--){

        std::cin >> n;

        std::cout << dp[n] << '\n';
    }

    return 0;
}