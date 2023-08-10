// 삼각형과 세 변
// 수학 & 기하학 & 구현

#include <iostream>
#include <algorithm>

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(1){

        int scale[3];
        std::cin >> scale[0] >> scale[1] >> scale[2];

        if(scale[0] == 0 && scale[1] == 0 && scale[2] == 0){
            break;
        }

        // 세 변을 길이 기준으로 정렬
        std::sort(scale, scale + 3);

        if(scale[2] >= scale[0] + scale[1]){
            std::cout << "Invalid\n";
        } else {
            if(scale[0] == scale[1] && scale[1] == scale[2]){
                std::cout << "Equilateral\n";
            } else if(scale[0] != scale[1] && scale[1] != scale[2] && scale[2] != scale[0]){
                std::cout << "Scalene\n";
            } else {
                std::cout << "Isosceles\n";
            }
        }
    }

    return 0;
}