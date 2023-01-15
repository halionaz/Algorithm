// 할리갈리
// 구현 & 자료 구조
// 집합과 맵

#include <iostream>
#include <string>
#include <map>

std::map<std::string, int> fruit;

int num[4];
int N, X;
std::string S;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    fruit["STRAWBERRY"] = 0;
    fruit["BANANA"] = 1;
    fruit["LIME"] = 2;
    fruit["PLUM"] = 3;

    std::cin >> N;
    
    for(int i = 0; i < N; i++){
        std::cin >> S >> X;
        num[fruit[S]] += X;
    }

    for(int i = 0; i < 4; i++){
        if(num[i] == 5){
            std::cout << "YES\n";
            return 0;
        }
    }

    std::cout << "NO\n";

    return 0;
}