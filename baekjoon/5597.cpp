// 과제 안 내신 분..?
// 구현

#include <iostream>

int n;
bool check[31];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    for(int i = 0; i < 28; i++){
        std::cin >> n;
        check[n] = true;
    }

    for(int i = 1; i <= 30; i++){
        if(!check[i]){
            std::cout << i << '\n';
        }
    }

    return 0;
}