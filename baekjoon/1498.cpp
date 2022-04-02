// 주기문
// kmp

#include <iostream>
#include <string>
#include <vector>

std::vector<int> getPi(std::string S){
    int N = S.length();
    std::vector<int> pi(N,0);
    int begin = 1, matched = 0;
    while(begin + matched < N){
        if(S[begin+matched] == S[matched]){
            matched++;
            pi[begin+matched-1] = matched;
        } else {
            if(!matched){
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
    for(int i = 1; i < S.length(); i++){
        if((i+1)%(i+1-pi[i])==0 && pi[i] != 0){
            std::cout << i+1 << ' ' << (i+1)/(i+1-pi[i]) << '\n';
        }
    }
    return 0;
}