// 이상한 기호
// 사칙연산

#include <iostream>

long long A, B;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> A >> B;
    
    std::cout << (A+B)*(A-B) << '\n';

    return 0;
}
