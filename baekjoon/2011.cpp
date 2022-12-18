// 암호코드
// 다이나믹 프로그래밍
// bottom-up

// 암호가 잘못된 경우에는 0을 출력해야 하지만,
// 알고리즘 상, 암호가 잘못된 경우(0으로 시작하는 암호문),
// 경우의 수가 0이 나옴.

#include <iostream>
#include <string>

#define mod 1000000;

int code[5001], dp[5001];
int N;
std::string inp;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> inp;

    N = inp.length();

    for(int i = 1; i <= N; i++){
        code[i] = inp[i-1] - '0'; // 숫자로 변환
    }

    dp[0] = 1;

    for(int i = 1; i <= N; i++){

        if(code[i] >= 1 && code[i] <= 9){
            // 그냥 A,B,C,D,E,F,G,H,I,J를 뒤에 붙이는 경우
            dp[i] = (dp[i] + dp[i-1]) % mod;
        }

        if(i > 1){
            // 앞에 숫자가 있다면, 이어질 수도 있음
            int connectedInt = code[i-1]*10 + code[i];

            if(connectedInt >= 10 && connectedInt <= 26){
                dp[i] = (dp[i] + dp[i-2]) % mod;
            }
        }

    }

    std::cout << dp[N] << '\n';

    return 0;

}