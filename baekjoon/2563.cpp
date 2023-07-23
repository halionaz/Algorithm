// 색종이
// 구현

#include <iostream>

bool white[101][101];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            white[i][j] = false;
        }
    }

    int N;

    std::cin >> N;

    for(int i = 0; i < N; i++){
        int pL, pD;
        std::cin >> pL >> pD;

        for(int j = 0; j < 10; j++){
            for(int p = 0; p < 10; p++){
                white[1 + pL + j][1 + pD + p] = true;
            }
        }
    }

    int S = 0;

    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            if(white[i][j]){
                S++;
            }
        }
    }

    std::cout << S << '\n';

    return 0;
}