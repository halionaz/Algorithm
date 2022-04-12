// 나는 행복합니다~
// 사칙연산

#include <iostream>

int N, M, K;

int main()
{
    
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    
    std::cin >> N >> M >> K;
    
    std::cout << K / M << ' ' << K%M << '\n'; 

    return 0;
}
