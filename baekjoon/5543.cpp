// 상근날드
// 사칙연산

#include <iostream>
#include <algorithm>

int main(){

    int upper, mid, lower, coke, sprite;

    std::cin >> upper >> mid >> lower >> coke >> sprite;

    int ans = 2000;
    ans = std::min(ans, upper);
    ans = std::min(ans, mid);
    ans = std::min(ans, lower);
    ans += std::min(coke, sprite);

    std::cout << ans - 50 << '\n';
}