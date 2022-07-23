// A+B - 5
// 사칙연산

#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(true){
        int A, B;
        std::cin >> A >> B;
        if(A == 0 && B == 0){
            break;
        }
        std::cout << A + B << '\n';
    }

    return 0;
    
}