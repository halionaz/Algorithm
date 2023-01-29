// 순환 순열
// kmp
// 환형 kmp

// 두 문자열을 XOR 했을 때, 0이 나온다는 것은
// 두 문자열이 같다는 뜻이다

#include <iostream>
#include <string>
#include <vector>

std::vector<int> findPi(std::string P){
    int M = P.length();
    std::vector<int> pi(M,0);
    int begin = 1, matched = 0;
    while(begin+matched < M){
        if(P[begin+matched] == P[matched]){
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

std::string A, B;

int main(){
    
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> A >> B;

    std::vector<int> pi = findPi(B);

    int N = A.length() , M = B.length();

    std::string checkS = A + A.substr(0,N-1);

    int matched = 0;
    int ans = 0;

    for(int i = 0; i < 2*N-1; i++){
        while(matched > 0 && checkS[i] != B[matched]){
            matched = pi[matched-1];
        }
        if(checkS[i] == B[matched]){
            matched++;
            if(matched == M){
                ans++;
                matched = pi[matched-1];
            }
        }
    }

    std::cout << ans << '\n';

    return 0;

}