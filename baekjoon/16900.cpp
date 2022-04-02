// 이름 정하기
// kmp

#include <iostream>
#include <string>
#include <vector>

std::vector<long long> findPi(std::string S){
    long long m = S.length();
    std::vector<long long> pi(m,0);
    long long begin = 1, matched = 0;
    while(begin + matched < m){
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
long long K;
std::string S;
int main(){
    std::cin >> S >> K;
    std::vector<long long> pi = findPi(S);
    long long n = S.length();
    std::cout << n*K - pi[n-1]*(K-1) << '\n';
    return 0;
}