// 팬들에게 둘러싸인 홍준
// 구현

#include <iostream>
#include <string>

std::string S;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> S;

    std::cout << ":fan:";
    std::cout << ":fan:";
    std::cout << ":fan:\n";
    std::cout << ":fan::";
    std::cout << S;
    std::cout << "::fan:\n";
    std::cout << ":fan:";
    std::cout << ":fan:";
    std::cout << ":fan:\n";
    
    return 0;
}