// 개수 세기
// 구현

#include <iostream>

int N, v, ans;
int arr[100];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    std::cin >> v;

    ans = 0;

    for(int i = 0; i < N; i++){
        if(arr[i] == v){
            ans += 1;
        }
    }

    std::cout << ans << '\n';

    return 0;
}