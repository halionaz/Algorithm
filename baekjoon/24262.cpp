// 알고리즘 수업 - 알고리즘의 수행 시간 1
// 구현

// MenOfPassion(A[], n) {
//     i = ⌊n / 2⌋;
//     return A[i]; # 코드1
// }

// 이 함수는 n의 값과 상관없이 항상 상수시간이 소요되는 알고리즘이므로
// 1, 0 출력 

#include <iostream>

int n;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;

    std::cout << 1 << '\n' << 0 << '\n';

    return 0;
}