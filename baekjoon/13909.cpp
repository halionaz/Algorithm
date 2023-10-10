// 창문 닫기
// 수학 & 정수론

// i번째 창문이 열려 있으려면
// 창문을 개폐한 사람이 홀수명이어야 함
// 즉, 약수의 개수가 홀수여야 창문이 열려 있을 수 있음
// 제곱수만이 약수의 개수가 홀수이므로, 범위 내 제곱수 개수 구하기와 동치인 문제

#include <iostream>

typedef long long ll;

ll N;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    int ans = 0;

    for(ll i = 1; i * i <= N; i++){
        ans++;
    }

    std::cout << ans << '\n';

    return 0;
}