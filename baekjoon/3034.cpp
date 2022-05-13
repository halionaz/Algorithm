// 앵그리 창영
// 피타고라스 정리

#include <iostream>
#include <math.h>

int N, W, H;
int len;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> W >> H;

    int maxLength = pow(W,2) + pow(H,2);

    for(int i = 0; i < N; i++){
        std::cin >> len;
        if(maxLength >= pow(len, 2)){
            std::cout << "DA\n";
        } else {
            std::cout << "NE\n";
        }
    }

    return 0;
}