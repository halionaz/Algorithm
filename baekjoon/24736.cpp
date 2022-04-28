// Football Scoring
// 사칙연산

#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int a1, a2, a3, a4, a5; // a팀 각 점수당 횟수
    int b1, b2, b3, b4, b5; // b팀 각 점수당 횟수

    std::cin >> a1 >> a2 >> a3 >> a4 >> a5;
    std::cin >> b1 >> b2 >> b3 >> b4 >> b5;

    std::cout << a1*6 + a2*3 + a3*2 + a4 + a5*2 << ' ';
    std::cout << b1*6 + b2*3 + b3*2 + b4 + b5*2 << '\n';

    return 0;
}