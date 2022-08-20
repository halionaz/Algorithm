// Oulipo
// kmp

#include <iostream>
#include <vector>
#include <string>

int T, ans;
std::string S, P;

std::vector<int> getPi(const std::string &N){
    int M = N.size();
    std::vector<int> pi(M, 0);
    int begin = 1, matched = 0;
    while (begin + matched < M){
        if (N[begin + matched] == N[matched]){
            matched++;
            pi[begin + matched - 1] = matched;
        }else{
            if (matched == 0)
                begin++;
            else{
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

int main(void){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        std::cin >> P;
        std::cin >> S;

        ans = 0;

        int n = S.size();
        int m = P.size();
        std::vector<int> pi = getPi(P);

        int matched = 0;

        for(int i = 0; i < n; i++){
            while(matched > 0 && S[i] != P[matched]){
                matched = pi[matched-1];
            }
            if(S[i] == P[matched]){
                matched++;
                if(matched == m){
                    matched = pi[matched-1];
                    ans += 1;
                }
            }
        }

        std::cout << ans << '\n';

    }

    return 0;
}
