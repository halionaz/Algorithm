// 시계 사진들
// kmp
// 환형 kmp

#include <iostream>
#include <vector>
#include <string>
int n;
std::string s(360000,'0');
std::string p(360000,'0');
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
                break;
            } else {
                matched++;
            }
        }
    }
    return result;
}
int main(){
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        std::cin >> tmp;
        s[tmp] = '1';
    }
    for(int i = 0; i<n; i++){
        int tmp;
        std::cin >> tmp;
        p[tmp] = '1';
    }
    std::string checkS = s+s;
    if(kmp(checkS,p)){
        std::cout << "possible" << '\n';
    } else {
        std::cout << "impossible" << '\n';
    }
    return 0;
}