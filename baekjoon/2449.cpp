// 전구
// 분할 정복 & 다이나믹 프로그래밍

#include <iostream>
#include <cstring>

const int maxInt = 200;

int N, K;
int arr[maxInt];
int dp[maxInt][maxInt];

int makeDP(int s, int e){
    if(s == e){
        return dp[s][e] = 0;
    } else {
        if(dp[s][e] != -1){

            return dp[s][e];

        } else {

            int ans = 500000;

            for(int i = s; i < e; i++){
                ans = std::min(ans, makeDP(s,i) +makeDP(i + 1,e) + (arr[s] == arr[i+1] ? 0 : 1));
            }

            return dp[s][e] = ans;
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(dp,-1,sizeof(dp));

    std::cin >> N >> K;

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }
    std::cout << makeDP(0,N-1) << '\n';

    return 0;
}