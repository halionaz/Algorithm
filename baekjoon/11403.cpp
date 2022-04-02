// 경로 찾기
// 플로이드-와샬

#include <iostream>

int N;
bool line[101][101];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> line[i][j];
        }
    }

    for(int k = 0; k < N; k++){
        // k를 거쳐가는 경우
        for(int i = 0; i < N; i++){
            for(int j = 0; j< N; j++){
                if(line[i][k] && line[k][j]){
                    line[i][j] = 1;
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            std::cout << line[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}