// 방학 숙제
// 사칙연산

#include <iostream>
#include <algorithm>

int L, A, B, C, D;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> L >> A >> B >> C >> D;

    int workDay = std::max((A%C ? A/C+1 : A/C),(B%D ? B/D+1 : B/D));

    std::cout << L - workDay << '\n';

    return 0;
}