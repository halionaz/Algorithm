// WARBOY
// 사칙연산

#include <iostream>

int A, B, C;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> A >> B >> C;

    std::cout << (B/A)*3*C << '\n'; 

    return 0;
}