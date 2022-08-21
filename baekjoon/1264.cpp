// 모음의 개수
// 구현 & 문자열

#include <iostream>
#include <string>

std::string S;
char vowels[] = {'a','e','i','o','u','A','E','I','O','U'};

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(true){

        std::getline(std::cin, S);

        int ans = 0;

        if(S == "#"){
            break;
        }

        for(int i = 0; i < S.length(); i++){
            for(int j = 0; j < 10; j++){
                if(S[i] == vowels[j]){
                    ans += 1;
                    break;
                }
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}