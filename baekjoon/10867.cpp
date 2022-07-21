// 중복 빼고 정렬하기
// 정렬

// 약간 야매로 풀음
// 정렬을 따로 안하고, set 자료구조를 순서대로(실제론 순서가 없음) 출력하여 정렬한 효과내기

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