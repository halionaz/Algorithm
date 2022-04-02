// 속타는 저녁 메뉴 
// kmp

// 환형 KMP

#include <iostream>
#include <vector>
#include <string>
std::vector<int> findPi(std::string P){
    int M = P.length();
    std::vector<int> pi(M,0);
    int begin = 1, matched = 0;
    while(begin+matched < M){
        if(P[matched] == P[matched+begin]){
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
int kmp(std::string S, std::string P){
    int n = S.length(), m = P.length();
    std::vector<int> pi = findPi(P);
    int result = 0;
    int matched = 0;
    for(int i = 0; i < n; i++){
        while(matched > 0 && S[i] != P[matched]){
            matched = pi[matched-1];
        }
        if(S[i] == P[matched]){
            if(matched == m-1){
                result++; // 어차피 값은 중요하지 않음
                matched = pi[matched];
            } else {
                matched++;
            }
        }
    }
    return result;
}
int gcd(int a, int b){
    // 항상 a>b여야 한다
    int temp;
    while(b!=0){
        temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}
int main(){
    int N;
    std::cin >> N;
    std::string S,P;
    for(int i = 0; i < N; i++){
        char temp;
        std::cin >> temp;
        S += temp;
    }
    for(int i = 0; i < N; i++){
        char temp;
        std::cin >> temp;
        P += temp;
    }
    std::string findS = S + S.substr(0,N-1);
    int caseNum = kmp(findS,P);
    int g = gcd(N,caseNum);
    std::cout << caseNum/g << '/' << N/g << '\n';
    return 0;
}