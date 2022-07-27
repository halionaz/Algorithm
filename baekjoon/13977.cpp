// 이항 계수와 쿼리
// 페르마의 소정리 & 분할 정복을 이용한 거듭제곱 & 정수론 & 모듈로 곱셈 역원 & 조합론 & 수학

// 11401 이항 계수 3과 동일한 문제

// 페르마의 소정리 사용
// N!%mod*((K!(N-K)!)^(mod-2)) % mod

#include <iostream>

typedef long long ll;

const ll mod = 1000000007;

int M, N, K;
ll factorial[4000001];
ll inverse[4000001]; // inverse[i] = i!^(mod-2)

ll pow(ll a, ll b){
    if(b == 1){
        return a % mod;
    }

    if(b%2 == 0){
        return pow((a * a) % mod, b / 2);
    } else {
        return (pow(a, b - 1) * a) % mod;
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    // factorial을 구해주는 과정
    factorial[0] = 1;
    for(int i = 1; i < 4000001; i++){
        factorial[i] = (factorial[i-1]*i)%mod;
    }

    std::cin >> M;

    while(M--){

        std::cin >> N >> K;

        std::cout << (factorial[N] * pow((factorial[K]*factorial[N-K])%mod, mod-2))%mod << '\n';

    }

    return 0;
}