// Shares
// 사칙연산
// inf_input

#include <iostream>
#include <cstdio>

int N, S;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while (~scanf("%d %d", &N, &S)) {
        std::cout << S / (N+1) << '\n';
    }

    return 0;
}