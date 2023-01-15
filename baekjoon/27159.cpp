// 노 땡스!
// 구현

#include <iostream>

int N;
int arr[34];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    int ans = 0;
    int prev = -1;
    for(int i = 0; i < N; i++){
        std::cin >> arr[i];

        if(prev == -1 | arr[i] - 1 != prev){
            // 첫 수거나, 그 전 수와 연속하지 않다면
            ans += arr[i];
        }

        prev = arr[i];
    }

    std::cout << ans << '\n';

    return 0;
}