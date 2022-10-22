// 비밀번호 찾기
// 해시를 사용한 집합과 맵
// 집합과 맵

#include <iostream>
#include <string>
#include <map>

int N, M;
std::map<std::string, std::string> m;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < N; i++){
        std::string site, password;
        std::cin >> site >> password;
        m.insert(std::pair<std::string,std::string>(site,password));
    }

    while(M--){
        std::string site;
        std::cin >> site;
        std::cout << m[site] << '\n';
    }

    return 0;
}