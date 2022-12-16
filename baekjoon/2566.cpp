// 최댓값
// 구현

#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int ansVal = -1, ansX, ansY, inp;
    
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            std::cin >> inp;

            if(inp > ansVal){
                ansVal = inp;
                ansX = i;
                ansY = j;
            }
        }
    }

    std::cout << ansVal << '\n';
    std::cout << ansX << ' ' << ansY << '\n';

    return 0;
}