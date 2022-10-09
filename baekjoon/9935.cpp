// 문자열 폭발
// 문자열 & 스택

#include <iostream>
#include <vector>
#include <string>

std::string S, E;
std::vector<char> stck;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> S >> E;

    int Slen = S.length();
    int Elen = E.length();

    for(int i = 0; i < Slen; i++){

        stck.push_back(S[i]);

        if(stck[stck.size()-1] == E[Elen-1]){
            // 마지막 글자가 같음
            bool match = true;
            for(int j = 0; j < Elen; j++){
                if(stck[stck.size() - Elen + j] != E[j]){
                    // 매칭 안됨
                    match = false;
                    break;
                }
            }

            if(match){
                for(int j = 0; j < Elen; j++){
                    stck.pop_back();
                }
            }
        }

    }

    if(stck.empty()){
        std::cout << "FRULA\n";
    } else {
        for(int i = 0; i < stck.size(); i++){
            std::cout << stck[i];
        }
        std::cout << '\n';
    }

    return 0;
}