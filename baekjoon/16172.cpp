// 나는 친구가 적다 (Large)
// kmp

#include <iostream>
#include <string>
#include <vector>

std::vector<int> getPi(std::string S){
    int M = S.length();
    std::vector<int> pi(M,0);
    int begin = 1, matched = 0;
    while(begin+matched < M){
        if(S[begin+matched] == S[matched]){
            matched++;
            pi[matched+begin-1] = matched;
        } else {
            if(matched == 0){
                begin++;
            } else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

std::string inp;
std::string S;
std::string K;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> inp;
    for(int i = 0; i < inp.length(); i++){
        if(inp[i] >= 'A' && inp[i] <= 'z'){
            S += inp[i];
        }
    }
    
    std::cin >> K;
    std::vector<int> pi = getPi(K);
    int matched = 0;
    int M = K.length();
    for(int i = 0; i < S.length(); i++){
        while(matched > 0 && S[i] != K[matched]){
            matched = pi[matched-1];
        }
        if(S[i] == K[matched]){
            matched++;
            if(matched == M){
                std::cout << 1 << '\n';
                return 0;
            }
        }
    }

    std::cout << 0 << '\n';

    return 0;
}