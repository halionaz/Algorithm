// 카멜레온 부분 문자열
// kmp

#include <iostream>
#include <string>
#include <vector>
std::vector<int> getPi(std::string S){
    int M = S.length();
    std::vector<int> pi(M,0);
    int begin = 1, matched = 0;
    while(begin + matched < M){
        if(S[begin+matched] == S[matched]){
            matched++;
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
    return pi;
}
int main(){
    std::string S;
    std::cin >> S;
    std::vector<int> pi = getPi(S);
    int N = S.length();
    std::string checkS = S.substr(1,N-2);
    int L = pi[N-1];
    while(L){
        std::string p = S.substr(0,L);
        int matched = 0;
        for(int j = 0; j < N-2; j++){
            while(matched > 0 && checkS[j] != p[matched]){
                matched = pi[matched-1];
            }
            if(checkS[j] == p[matched]){
                matched++;
                if(matched == L){
                    std::cout << p << '\n';
                    return 0;
                }
            }
        }
        L = pi[L-1];
    }
    std::cout << -1 <<'\n';
    return 0;
}