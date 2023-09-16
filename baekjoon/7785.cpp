// 회사에 있는 사람
// 자료 구조
// 집합과 맵

#include <iostream>
#include <map>
#include <string>

int N;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    // 사전 순의 역순으로 정렬해야 함
    std::map <std::string, bool, std::greater<std::string> > m;
    std::string name, state;

    std::cin >> N;

    while(N--){
        std::cin >> name >> state;

        if(state == "enter"){
            // state가 enter
            m.insert(std::make_pair(name, true));
        } else {
            // state가 leave
            m.erase(name);
        }
    }

    for(auto iter = m.begin(); iter != m.end(); iter++){
        std::cout << iter->first << '\n';
    }

    return 0;
}