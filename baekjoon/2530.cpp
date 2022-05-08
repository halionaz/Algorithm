// 인공지능 시계
// 사칙연산

#include <iostream>

int A, B, C, D;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> A >> B >> C >> D;

    C += D;

    if(C > 59){
        B += C / 60;
        C %= 60;
    }
    if(B > 59){
        A += B / 60;
        B %= 60;
    }
    if(A > 23){
        A %= 24;
    }

    std::cout << A << ' ' << B << ' ' << C << '\n';

    return 0;
}