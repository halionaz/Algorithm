// 주기
// kmp & 유클리드 호제법

// KMP와 GCD를 혼합한 문제 풀이

#include <iostream>
#include <vector>
#include <string>

int N;
std::vector<int> p;

std::vector<int> getPi(std::string S){
    int M = S.length();
    std::vector<int> pi(M,0);
    int begin = 1, matched = 0;
    while(begin+matched < M){
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

int GCD(int a, int b){
    if(a<b){
        int tmp = a;
        a = b;
        b = tmp;
    }

    while(b){
        int tmp = a%b;
        a = b;
        b = tmp;
    }

    return a;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int ind = 0;

    while(1){

        ind++;

        std::cin >> N;

        if(!N){
            break;
        }

        std::cout << "Test case #" << ind << '\n';
        std::string S;
        std::cin >> S;
        p = getPi(S); // 실패함수 이용한 접두어-접미어 관계 구하기

        for(int i = 1; i < N; i++){
            if(p[i] != 0){ // 주기가 있는 접두사 등장
                int len = i+1; // 접두사 길이
                int gcd = GCD(len, p[i]); // 주기문의 길이
                if(p[i] + gcd == len){
                    // 겹치지 않는다면
                    std::cout << len << ' ' << len/gcd << '\n';
                }
            }
        }

        std::cout << '\n';
    }

    return 0;
}