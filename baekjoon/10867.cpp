// 중복 빼고 정렬하기
// 정렬

#include <iostream>
#include <set>

int N;
std::set<int> S;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        int inp;
        std::cin >> inp;
        S.insert(inp);
    }

    std::set<int>::iterator iter;
    for(iter = S.begin(); iter != S.end(); iter++){
        std::cout << *iter << " ";
    }
    std::cout << '\n';

    return 0;
}