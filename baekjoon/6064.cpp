// 카잉 달력
// 중국인의 나머지 정리

// 정수론을 이용해 푸는 문제지만 어려운 수학은 아님
// 두 나누는 수가 주어지고, 각각의 나머지가 주어졌을때
// 원본 수를 구하는 문제

// 한 수 기준으로 후보군을 모두 뽑은 후
// 다른 수로 나눴을 때 나머지를 충족하는지 확인

#include <iostream>

int T, M, N, x ,y;

// 최대 공약수 구하기
int GCD(int a, int b){
    if(a%b == 0){
        return b;
    }

    return GCD(b, a%b);
}

// 최소 공배수 구하기
int LCM(int a, int b){
    return (a * b) / GCD(a,b);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        std::cin >> M >> N >> x >> y;

        int lastDay = LCM(M,N);

        while(true){
            if(x > lastDay || (x-1)%N + 1 == y){
                // 범위를 넘어섰거나, 조건 만족할 시
                break;
            }
            x += M;
        }

        if(x > lastDay){
            std::cout << -1 << '\n';
        } else {
            std::cout << x << '\n';
        }
    }

    return 0;
}