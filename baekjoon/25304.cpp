// 영수증
// 구현 & 사칙연산

#include <iostream>

int X, N, a, b;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> X >> N;

    for(int i = 0; i < N; i++){
        std::cin >> a >> b;
        X -= a * b;
    }

    if(X == 0){
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    return 0;
}