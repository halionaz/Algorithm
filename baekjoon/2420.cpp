// 사파리월드
// 사칙연산

#include <iostream>

long long N,M;

int main(){

    std::cin >> N >> M;

    std::cout << ((N-M < 0) ? -(N-M) : (N-M)) << '\n';
}