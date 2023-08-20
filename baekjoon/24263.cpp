// 알고리즘 수업 - 알고리즘의 수행 시간 2
// 구현 & 시뮬레이션

#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);


    int N;

    std::cin >> N;

    // 코드1의 수행 횟수를 다항식으로 나타내었을 때, 최고차항의 차수는 항상 1
    // O(N)
    std::cout << N << '\n' << 1 << '\n';

    return 0;
}