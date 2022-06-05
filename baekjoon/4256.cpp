// 트리
// 분할 정복 & 트리 & 재귀

#include <iostream>

int T, N;
int preord[1001];
int inord[1001];

void func(int root, int s, int e){
    for(int i = s; i < e; i++){
        if(preord[root] == inord[i]){
            // 분기점 찾음, inord 기준 i번째 인덱스가 루트

            // 왼쪽 서브 트리, 루트는 preord 기준으로 (기존 root) + 1 임
            func(root+1, s, i);

            // 오른쪽 서브 트리
            func(root + (i - s) + 1, i + 1, e);

            std::cout << preord[root] << ' ';
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        std::cin >> N;

        for(int i = 0; i < N; i++){
            std::cin >> preord[i];
        }

        for(int i = 0; i < N; i++){
            std::cin >> inord[i];
        }

        func(0, 0, N);

        std::cout << '\n';

    }

    return 0;
}