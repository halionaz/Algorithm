// 삼각형 외우기
// 기하학

#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int a, b, c;

    std::cin >> a >> b >> c;

    if(a + b + c == 180){
        if(a == b && b == c){
            std::cout << "Equilateral\n";
        } else {
            if(a != b && b != c && c != a){
                std::cout << "Scalene\n";
            } else {
                std::cout << "Isosceles\n";
            }
        }
    } else {
        std::cout << "Error\n";
    }

    return 0;
}