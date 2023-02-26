// 박성원
// 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍
// top-down

#include <iostream>
#include <string.h>
#include <string>
#include <numeric>

typedef long long ll;

int N, K;
std::string sArr[16]; // 수와 자릿수를 함께 저장하기 위해 문자열로 첫 입력 받음
int arr[16]; 
int len[16]; // 수의 자릿수 저장
// dp[i][j] :: 숫자 사용 여부가 i이고, K로 나눈 나머지가 j인 경우의 수
ll dp[1<<15][101];
int cash[52];

ll gcd(ll x, ll y){
    ll temp;
    if(x<y){
        temp = x;
        x= y;
        y = temp;
    }
    ll rest;
    while(y!=0){
        rest = x%y;
        x = y;
        y = rest;
    }
    return x;
}

ll solve(int visit, int mod){

    if(visit == (1 << N) - 1){
        // 순열 완성
        if(mod == 0){
            // 경우의 수 있음
            return 1;
        } else {
            // 경우의 수 없음
            return 0;
        }
    }

    ll &res = dp[visit][mod];

    if(res != -1){
        return res;
    } else {
        res = 0;
        for(int i = 0; i < N; i++){
            if((visit & (1 << i)) == 0){
                res += solve(visit | (1 << i), (mod * cash[len[i]] + arr[i]) % K);
            }
        }
        return res;
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(dp, -1, sizeof(dp));

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> sArr[i];
    }

    std::cin >> K;

    for(int i = 0; i < N; i++){
        len[i] = sArr[i].length();
        arr[i] = 0;
        for(int j = 0; j < len[i]; j++){
            arr[i] *= 10;
            arr[i] %= K;
            arr[i] += (sArr[i][j] - '0');
            arr[i] %= K;
        }
    }

    // 빠른 처리를 위해 10의 승수에 해당하는 나머지 미리 구해놓기
    cash[0] = 1 % K; // 1을 K로 나눈 나머지
    for(int i = 1; i < 52; i++){
        cash[i] = (cash[i-1] * 10) % K;
    }

    ll son = solve(0, 0);
    ll mom = 1;
    for(int i = 1; i <= N; i++){    
        mom *= i;    
    }    

    if(son == 0){
        std::cout << "0/1\n";
    } else {
        ll t = gcd(mom, son);
        std::cout << son / t << '/' << mom / t << '\n';
    }

    return 0;
}