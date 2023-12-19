// 라면 공식
// 사칙연산 & 구현

#include <iostream>

int N, A, B, X;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    while(N--){

        std::cin >> A >> B >> X;

        std::cout << A * (X - 1) + B << '\n';
        
    }

    return 0;
}