// 알고리즘 수업 - 점근적 표기 1
// 수학

#include <iostream>

int a1, a0, c, n0;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> a1 >> a0;
    std::cin >> c;
    std::cin >> n0;

    if(c < a1){
        // a1이 더 크다면 언젠간 무조건 따라잡히므로 문제 조건 성립 불가
        std::cout << "0\n";
        return 0;
    }

    double min = double(a0) / double(c - a1);

    std::cout << (min <= n0) << '\n';

    return 0;
}