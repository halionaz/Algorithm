// 문자열 집합
// 트리를 사용한 집합과 맵
// 집합과 맵

#include <iostream>
#include <set>
#include <string>

int N,M;
std::set<std::string> S;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < N; i++){
        std::string inp;
        std::cin >> inp;
        S.insert(inp);
    }

    int ans = 0;

    for(int i = 0; i< M; i++){
        std::string inp;
        std::cin >> inp;
        int c = S.count(inp);
        ans += c ? 1 : 0;
    }

    std::cout << ans << '\n';

    return 0;
}