// 호텔 관리
// 2-sat & 강한 연결 요소

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

const int max = 100001;
const int switchMax = 2*max;

int N,M;
int ind = 0;
int roomStatus[max];
int visited[switchMax];
int scc[switchMax];
std::vector<int> switchConnection[max];
std::vector<int> line[switchMax];
std::stack<int> stck;

void DFS(int cur){
    visited[cur] = true;
    for(int j = 0; j < line[cur].size(); j++){
        if(!visited[line[cur][j]]){
            DFS(line[cur][j]);
        }
    }
    stck.push(cur);
}

void reverseDFS(int cur){
    visited[cur] = true;
    scc[cur] = ind;
    for(int j = 0; j < line[cur].size(); j++){
        if(!visited[line[cur][j]]){
            reverseDFS(line[cur][j]);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 1; i <= N; i++){
        std::cin >> roomStatus[i];
    }

    for(int i = 1; i <= M; i++){
        int K,x;
        std::cin >> K;
        for(int j = 0; j < K; j++){
            std::cin >> x;
            switchConnection[x].push_back(i);
        }
    }

    for(int i = 1; i <= N; i++){

        int a = switchConnection[i][0];
        int b = switchConnection[i][1];

        int notA = a*2;
        int notB = b*2;
        a = a*2-1;
        b = b*2-1;

        if(roomStatus[i]){
            //열려 있는 상태
            line[a].push_back(b);
            line[b].push_back(a);
            line[notA].push_back(notB);
            line[notB].push_back(notA);

        } else {
            //닫혀 있는 상태
            line[a].push_back(notB);
            line[notB].push_back(a);
            line[b].push_back(notA);
            line[notA].push_back(b);
        }
    }

    memset(visited,false,sizeof(visited));

    for(int i = 1; i <= 2*M; i++){
        if(!visited[i]){
            DFS(i);
        }
    }

    memset(visited,false,sizeof(visited));

    while(!stck.empty()){
        if(!visited[stck.top()]){
            ind++;
            reverseDFS(stck.top());
        }
        stck.pop();
    }

    for(int i = 1; i<= M; i++){
        if(scc[i*2-1] == scc[i*2]){
            std::cout << 0 << '\n';
            return 0;
        }
    }

    std::cout << 1 << '\n';

    return 0;
}