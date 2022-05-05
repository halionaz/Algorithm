// 세수정렬
// 정렬

#include <iostream>
#include <algorithm>

int num[3];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    for(int i = 0; i < 3; i++){
        std::cin >> num[i];
    }

    // 세 수만 정렬하면 된다는 조건 상, 조건문으로 구현 가능

    if(num[0] < num[1]){
        if(num[0] < num[2]){
            if(num[1] < num[2]){
                std::cout << num[0] << ' ' << num[1] << ' ' << num[2] << '\n';
            } else {
                std::cout << num[0] << ' ' << num[2] << ' ' << num[1] << '\n';
            }
        } else {
            std::cout << num[2] << ' ' << num[0] << ' ' << num[1] << '\n';
        }
    } else {
        if(num[1] < num[2]){
            if(num[0] < num[2]){
                std::cout << num[1] << ' ' << num[0] << ' ' << num[2] << '\n';
            } else {
                std::cout << num[1] << ' ' << num[2] << ' ' << num[0] << '\n';
            }
        } else {
            std::cout << num[2] << ' ' << num[1] << ' ' << num[0] << '\n';
        }
    }

    
    // C++ 기본 정렬 라이브러리 사용

    // std::sort(num, num+3);

    // for(int i = 0; i < 3; i++){
    //     std::cout << num[i] << ' ';
    // }
    // std::cout << '\n';

    return 0;
}