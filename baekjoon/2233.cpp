// 사과나무
// 트리 & 최소 공통 조상

// 썩은 사과 두개가 주어졌을때,
// 그 두개의 공통 조상을 자르는 것이 답

#include <iostream>
#include <cstring>
#include <string>

const int maxNum = 2001;
const int log = 11;
int N,X,Y;
int node = 1;
int d = 0;
int parents[log+1][maxNum];
int depth[maxNum];
int binary[maxNum+maxNum];
std::string S;

int main(){

    memset(parents,-1,sizeof(parents));
    memset(depth,-1,sizeof(depth));

    std::cin >> N;
    std::cin >> S;

    int cur = 0;

    // 벌레 이진수를 바탕으로 트리 만들기
    for(int i = 0; i <= N+N; i++){
        if(S[i] == '1'){
            d--;
            binary[i] = cur;
            cur = parents[0][cur];
        } else {
            parents[0][node] = cur;
            depth[node] = d;
            cur = node;
            binary[i] = node;
            node++;
            d++;
        }
    }

    // sparse table 제작
    for(int i = 0; i < log; i++){
        for(int j = 1; j <= N; j++){
            if(parents[i][j] != -1){
                parents[i+1][j] = parents[i][parents[i][j]];
            }
        }
    }

    // X와 Y의 최소 공통 조상 찾기
    std::cin >> X >> Y;
    X = binary[X-1];
    Y = binary[Y-1];
    if(depth[X] < depth[Y]){
        int tmp = X;
        X = Y;
        Y = tmp;
    }
    int dist = depth[X] - depth[Y];
    int ind = 0;
    while(dist){
        if(dist%2){
            X = parents[ind][X];
        }
        ind++;
        dist /= 2;
    }
    if(X!=Y){
        for(int i = log; i >= 0; i--){
            if(parents[i][X] != parents[i][Y]){
                X = parents[i][X];
                Y = parents[i][Y];
            }
        }
        X = parents[0][X];
    }
    // X가 공통 조상이므로, 이진수에서 몇번째인지를 찾음
    for(int i = 0; i < N+N; i++){
        if(binary[i] == X){
            std::cout << i+1 << ' ';
        }
    }
    std::cout << '\n';
}