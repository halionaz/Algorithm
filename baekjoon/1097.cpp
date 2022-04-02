// 마법의 단어
// KMP & 브루트포스 알고리즘

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

int N,K, cnt = 0;
bool visited[9];
std::vector<std::string> stringArr;

std::vector<int> getPi(std::string S){
    int M = S.length();
    std::vector<int> pi(M,0);
    int begin = 1, matched = 0;
    while(begin + matched < M){
        if(S[begin+matched] == S[matched]){
            matched++;
            pi[begin+matched-1] = matched;
        } else {
            if(!matched){
                begin++;
            } else {
                begin += matched-pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

void dfs(int depth, std::string str){

    if(depth == N){

        std::string toFind = str + str.substr(0,str.length()-1);
        std::vector<int> pi = getPi(str);
        int M = str.length();
        int matched = 0;
        int ans = 0;
        for(int i = 0; i < M+M-1; i++){
            while(matched > 0 && toFind[i] != str[matched]){
                matched = pi[matched-1];
            }
            if(toFind[i] == str[matched]){
                matched++;
                if(matched == M){
                    ans++;
                    matched = pi[matched-1];
                }
            }
        }
        if(ans == K){
            cnt++;
        }

    } else {
        for(int i = 0; i < N; i++){
            if(!visited[i]){
                visited[i] = true;
                dfs(depth+1,str+stringArr[i]);
                visited[i] = false;
            }
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(visited, false, sizeof(visited));

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::string inp;
        std::cin >> inp;
        stringArr.push_back(inp);
    }

    std::cin >> K;

    dfs(0,"");

    std::cout << cnt << '\n';
    return 0;

}