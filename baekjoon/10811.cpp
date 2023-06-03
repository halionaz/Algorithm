// 바구니 뒤집기
// 구현 & 시뮬레이션

#include <iostream>
#include <algorithm>

int N, M;
int arr[101];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 1; i <= N; i++){
        arr[i] = i;
    }

    while(M--){
        int i, j;
        std::cin >> i >> j;
        std::reverse(arr + i, arr + j + 1);
    }

    for(int i = 1; i <= N; i++){
        std::cout << arr[i] << ' ';
    }

    std::cout << '\n';

    return 0;
}