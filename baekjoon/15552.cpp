// 빠른 A+B
// 사칙연산

#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int T;
    int a,b;

    std::cin >> T;

    while(T--){
        std::cin >> a >> b;
        std::cout << a + b << '\n';
    }

    return 0;
    
}