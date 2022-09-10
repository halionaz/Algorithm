// 부분 문자열
// kmp

// strstr로도 풀린다고 한다

#include <iostream>
#include <string>
#include <vector>

std::vector<int> findPi(std::string p){
    int m = p.size();
    std::vector<int> pi(m,0);
    int begin = 1, matched = 0;
    while(begin + matched < m){
        if(p[begin+matched] == p[matched]){
            matched++;
            pi[begin+matched-1] = matched;
        }else{
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

    std::string S,P;

    getline(std::cin,S);
    getline(std::cin,P);
    
    std::vector<int> pi = findPi(P);
    int N = S.size(), M = P.size(), matched = 0;
    int isPartial = 0;
    for(int i = 0; i< N; i++){
        while(matched > 0 && S[i] != P[matched]){
            matched = pi[matched-1];
        }
        if(S[i] == P[matched]){
            matched++;
            if(matched == M){
                isPartial = 1;
                break;
            }
        }
    }
    
    std::cout << isPartial << '\n';
    return 0;
}