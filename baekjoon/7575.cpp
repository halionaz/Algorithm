// 바이러스
// kmp

#include <iostream>
#include <vector>
#include <cstring>

int N, K;
int M[101];
int program[101][1001];

std::vector<int> getPi(int start){
    std::vector<int> pi(K,0);
    int begin = 1, matched = 0;
    while(begin + matched < K){
        if(program[0][start+begin] == program[0][start+begin+matched]){
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

    memset(program,0,sizeof(program));

    std::cin >> N >> K;

    for(int i = 0; i < N; i++){
        std::cin >> M[i];
        for(int j = 0; j < M[i]; j++){
            std::cin >> program[i][j];
        }
    }

    for(int i = 0; i < M[0] - K + 1; i++){

        std::vector<int> pi = getPi(i);
        bool ans = true;

        for(int j = 1; j < N; j++){
            bool canCheck = false;
            int matched = 0;
            for(int k = 0; k < M[j]; k++){
                while(matched > 0 && program[j][k] != program[0][i+matched]){
                    matched = pi[matched-1];
                }
                if(program[j][k] == program[0][i+matched]){
                    matched++;
                    if(matched == K){
                        canCheck = true;
                        break;
                    }
                }
            }
            if(!canCheck){
                for(int k = M[j]-1; k >= 0; k--){
                    while(matched > 0 && program[j][k] != program[0][i+matched]){
                        matched = pi[matched-1];
                    }
                    if(program[j][k] == program[0][i+matched]){
                        matched++;
                        if(matched == K){
                            canCheck = true;
                            break;
                        }
                    }
                }
                if(!canCheck){
                    ans = false;
                    break;
                }
            }
        }
        if(ans){
            std::cout << "YES" << '\n';
            return 0;
        }
    }

    std::cout << "NO" << '\n';
    return 0;
}