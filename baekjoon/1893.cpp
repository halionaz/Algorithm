// 시저 암호
// kmp & 브루트포스 알고리즘

#include <iostream>
#include <string>
#include <vector>
#include <map>

int T, N, M;
std::string alphabetOrder, pat, S;

std::vector<int> getPi(std::string P){
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

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        std::map<char,int> dict;

        std::cin >> alphabetOrder >> pat >> S;

        int cnt = alphabetOrder.length();
        N = S.length();
        M = pat.length();
        int ansCnt = 0;
        std::vector<int> ans;

        for(int i = 0; i < cnt; i++){
            dict.insert(std::make_pair(alphabetOrder[i],i));
        }

        for(int l = 0; l < cnt; l++){

            // 경우의 수는 알파벳 개수만큼 존재함

            std::vector<int> pi = getPi(pat);

            int wordCnt = 0, matched = 0;
            bool canAns = true;

            for(int i = 0; i < N; i++){
                while(matched > 0 && S[i] != pat[matched]){
                    matched = pi[matched-1];
                }

                if(pat[matched] == S[i]){
                    matched += 1;
                    if(matched == M){
                        matched = pi[matched-1];
                        if(wordCnt){
                            canAns = false;
                            break;
                        } else {
                            wordCnt++;
                        }
                    }
                }
            }

            if(canAns && wordCnt){
                ansCnt++;
                ans.push_back(l);
            }

            // 패턴 갱신
            for(int i = 0; i < M; i++){
                int ind = dict[pat[i]] + 1;
                if(ind == cnt){
                    ind = 0;
                }
                pat[i] = alphabetOrder[ind];
            }
        }


        if(ansCnt){

            if(ansCnt == 1){
                std::cout << "unique: " << ans[0] << '\n';
            } else {
                std::cout << "ambiguous: ";
                for(int i = 0; i < ansCnt; i++){
                    std::cout << ans[i] << ' ';
                }
                std::cout << '\n';
            }

        } else {
            std::cout << "no solution\n";
        }

    }
    
    return 0;
}