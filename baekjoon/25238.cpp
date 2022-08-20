// 가희와 방어율 무시
// 사칙연산

#include <iostream>

double a, b;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> a >> b;

    a = a * ((100 - b)/100);

    std::cout << (a < 100 ? 1 : 0) << '\n';

    return 0;
}