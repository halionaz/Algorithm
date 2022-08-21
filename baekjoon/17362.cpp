// 수학은 체육과목 입니다 2
// 사칙연산

#include <iostream>

int n = 0;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;

    int ans;

    switch (n%8) {
        case 1 :
            ans = 1;
            break;
        case 0 :
        case 2 :
            ans = 2;
            break;
        case 3 :
        case 7 :
            ans = 3;
            break;
        case 4 :
        case 6 :
            ans = 4;
            break;
        case 5 :
            ans = 5;
            break;
    }

    std::cout << ans << '\n';

    return 0;
}