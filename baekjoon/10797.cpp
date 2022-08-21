// 10부제
// 구현

#include <iostream>

int main(){

    int N;

    int ans = 0;

    std::cin >> N;

    for(int i = 0; i < 5; i++){
        int inp;
        std::cin >> inp;
        if(inp == N){
            ans += 1;
        }
    }

    std::cout << ans << '\n';

    return 0;
}