// 크냐?
// 구현

#include <iostream>

int A,B;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(true){

        std::cin >> A >> B;

        if(A == 0 && B == 0){
            break;
        }

        std::cout << (A > B ? "Yes" : "No") << '\n';
    }

    return 0;
}