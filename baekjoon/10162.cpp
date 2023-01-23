// 전자레인지
// 그리디 알고리즘 & 수학

#include <iostream>

const int t[3] = {300, 60, 10};

int T;
int ans[3] = {0, 0, 0};

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    for(int i = 0; i < 3; i++){
        ans[i] = T / t[i];
        T -= t[i] * ans[i];
    }

    if(T == 0){
        for(int i = 0; i < 3; i++){
            std::cout << ans[i] << ' ';
        }
    } else {
        std::cout << -1;
    }
    std::cout << '\n';

    return 0;
}