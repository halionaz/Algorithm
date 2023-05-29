// 공 바꾸기
// 구현 & 시뮬레이션

#include <iostream>

int N, M;
int buckets[101];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    // "각 바구니에 적혀있는 번호와 같은 번호가 적힌 공이 들어있다."
    for(int i = 1; i <= N; i++){
        buckets[i] = i;
    }

    while(M--){
        int i, j, tmp;
        std::cin >> i >> j;

        tmp = buckets[i];
        buckets[i] = buckets[j];
        buckets[j] = tmp;
    }

    for(int i = 1; i <= N; i++){
        std::cout << buckets[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}