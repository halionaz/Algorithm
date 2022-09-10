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

    // abcabc 가 S 라면,
    // abcabcabc 는 S가 2번 반복된 것
    // 결국 pi[n-1](앞 뒤가 똑같은 길이)가 K-1번 만큼 빠질 수 있음
    std::cout << n*K - pi[n-1]*(K-1) << '\n';
    return 0;
}