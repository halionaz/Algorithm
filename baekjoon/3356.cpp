// 라디오 전송
// kmp

// kmp의 실패 함수를 이용하여 푸는 문제

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
    int L;
    std::string S;
    std::cin >> L;
    std::cin >> S;
    std::vector<int> pi = getPi(S);
    std::cout << L-pi[L-1] << '\n';
    return 0;
}