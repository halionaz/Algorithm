// 행렬 덧셈
// 구현 & 수학

#include <iostream>

int N, M;
int A[100][100];
int B[100][100];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cin >> A[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cin >> B[i][j];
            A[i][j] += B[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cout << A[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}