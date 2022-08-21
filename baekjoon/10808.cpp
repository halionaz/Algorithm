// 알파벳 개수
// 구현 & 문자열

#include <iostream>
#include <string>

std::string S;
int arr[26];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> S;

    for(int i = 0; i < S.length(); i++){
        arr[S[i]-'a'] += 1;
    }

    for(int i = 0; i < 26; i++){
        std::cout << arr[i] << ' ';
    }

    std::cout << '\n';

    return 0;
}