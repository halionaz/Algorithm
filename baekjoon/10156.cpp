// 과자
// 사칙연산

#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int K, N, M;

    std::cin >> K >> N >> M;

    if(K*N <= M){
        std::cout << "0\n";
    } else {
        std::cout << K*N - M << '\n';
    }

    return 0;
}