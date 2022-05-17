// 두~~부 두부 두부
// 사칙연산 & 구현

#include <iostream>

int N, M, K;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M >> K;

    K -= 3;

    if(K >= 0){
        K %= N;
    } else {
        K = N - ((-K) % N);
    }

    M += K;

    if(M > N){
        M -= N;
    }

    std::cout << M << '\n';

    return 0;
}