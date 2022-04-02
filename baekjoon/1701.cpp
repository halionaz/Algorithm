// Cubeditor
// kmp

#include <iostream>
#include <vector>
#include <string>

std::string S;
int ans = 0;
std::string ansS;

void getPi(std::string P){
    int M = P.size();
    std::vector<int> pi(M,0);
    int begin = 1, matched = 0;
    while(begin+matched < M){
        if(P[begin+matched] == P[matched]){
            matched++;
            if(matched > ans){
                ans = matched;
                ansS = P;
            }
            pi[begin+matched-1] = matched;
        } else {
            if(matched == 0){
                begin++;
            } else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
}

int main(){

    std::cin >> S;
    int M = S.length();
    for(int i = 0; i < M-1; i++){
        std::string P = S.substr(i,M-i);
        getPi(P);
    }
    std::cout << ans << '\n';
    return 0;
}