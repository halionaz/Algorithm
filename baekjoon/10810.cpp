// 공 넣기
// 시뮬레이션 & 구현

#include <iostream>

int N, M;
int buckets[101];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    while(M--){
        int i, j, k;
        std::cin >> i >> j >> k;
        for(int l = i; l <= j; l++){
            buckets[l] = k;
        }
    }

    for(int i = 1; i <= N; i++){
        std::cout << buckets[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}