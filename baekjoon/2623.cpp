// 음악프로그램
// 위상 정렬

#include <iostream>
#include <queue>
#include <vector>
int N, M, singerNum;
int inputCnt[1001] = {0}, tmpInput[1001];
std::vector<int> line[1001];

int main(){
    std::cin >> N >> M;
    for(int i = 0; i<M; i++){
        std::cin >> singerNum;
        for(int j = 0; j < singerNum; j++){
            std::cin >> tmpInput[j];
        }
        for(int j = 0; j < singerNum-1; j++){
            for(int l = j+1; l < singerNum; l++){
                line[tmpInput[j]].push_back(tmpInput[l]);
                inputCnt[tmpInput[l]]++;
            }
        }
    }
    std::queue<int> q;
    for(int i = 1; i <= N; i++){
        if(inputCnt[i]==0){
            q.push(i);
        }
    }
    std::vector<int> ans;
    for(int i = 1; i <= N; i++){
        if(q.empty()){
            std::cout << 0 <<'\n';
            return 0;
        } else {
            int tmp = q.front();
            q.pop();
            ans.push_back(tmp);
            for(int j = 0; j < line[tmp].size(); j++){
                if(--inputCnt[line[tmp][j]] == 0){
                    q.push(line[tmp][j]);
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        std::cout << ans[i] << '\n';
    }
    return 0;
}