// 분수 합
// 수학 & 정수론 & 유클리드 호제법

#include <iostream>

typedef long long ll;

ll GCD(ll a, ll b){
    // 최대공약수 반환하는 함수

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

ll LCM(ll a, ll b){
    // 최소공배수 반환하는 함수

    ll gcd = GCD(a, b);

    return (a * b) / gcd;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    ll a, b, c, d;

    std::cin >> a >> b >> c >> d;

    ll lcm = LCM(b, d);

    ll haveToMultA = lcm / b;
    ll haveToMultB = lcm / d;

    ll sum = a * haveToMultA + c * haveToMultB;
    ll gcd = GCD(sum, lcm);

    std::cout << sum / gcd << ' ' << lcm / gcd << '\n';

    return 0;
}