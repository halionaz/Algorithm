// Vera and Outfits
// 사칙연산 & 조합론

#include <iostream>

int N;

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    
    std::cin >> N;
    
    std::cout << N*(N-1) << '\n';

    return 0;
}
