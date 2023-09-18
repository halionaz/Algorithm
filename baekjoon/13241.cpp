// 최소공배수
// 정수론 & 유클리드 호제법

#include <iostream>
typedef long long ll;

ll A, B;

ll GCD(ll a, ll b){
    if(a < b){
        ll tmp = a;
        a = b;
        b = tmp;
    }

    while(b){
        ll tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
    
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> A >> B;

    ll gcd = GCD(A, B);

    std::cout << (A * B) / gcd << '\n';

    return 0;
}