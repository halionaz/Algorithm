// A+B - 3
// 사칙연산

#include <iostream>

int main(void){
    int T;
    std::cin >> T;
    for(int i = 0; i < T; i++){
        int A,B;
        std::cin >> A;
        std::cin >> B;
        std::cout << A+B << std::endl;
    }
    return 0;
}