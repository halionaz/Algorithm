// 팰린드롬 분할
// 다이나믹 프로그래밍

// 10942와 초반 아이디어가 비슷함

#include <iostream>
#include <string>

int N;
std::string S;
int dp[2501];
bool P[2501][2501]; // P[i][j] :: 문자열의 i~j번째가 팰린드롬인지 검사

int min(int a, int b){
    return a < b ? a : b;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> S;
    N = S.length();
    S = '-' + S;

    for(int i = 1; i <= N; i++){
        P[i][i] = true;
        // 문자열의 i번째부터 i번째까지는 무조건 팰린드롬
    }
    for(int i = 1; i < N; i++){
        if(S[i] == S[i+1]){
            P[i][i+1] = true;
            // 문자열의 i부터 i+1까지는 두 문자가 같으면 팰린드롬
        }
    }
    for(int len = 3; len <= N; len++){
        for(int i = 1; i + len - 1 <= N; i++){
            int e = i + len - 1;
            if(S[i] == S[e] && P[i+1][e-1]){
                // 양 끝 문자가 같고, 중간 문자열이 팰린드롬이면 이 문자열도 팰린드롬
                P[i][e] = true;
            }
        }
    }

    for(int i = 1; i <= N; i++){
        dp[i] = 3000;
        for(int j = 1; j <= i; j++){
            if(P[j][i]){
                dp[i] = min(dp[i],dp[j-1]+1);
            }
        }
    }   

    std::cout << dp[N] << '\n';


    return 0;
}