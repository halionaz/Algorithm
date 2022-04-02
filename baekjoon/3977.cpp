// 축구 전술 
// 강한 연결 요소

#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

const int maxArea = 100001;

int T,N,M;
int ind;
int scc[maxArea];
int sccInpNum[maxArea];
std::vector<int> line[maxArea];
std::vector<int> reverseLine[maxArea];
bool visited[maxArea];
std::stack<int> S;

void dfs(int cur){
    
    visited[cur] = true;
    for(int i = 0; i < line[cur].size(); i++){
        if(!visited[line[cur][i]]){
            dfs(line[cur][i]);
        }
    }
    S.push(cur);

}

void reverseDfs(int cur){
    visited[cur] = true;
    scc[cur] = ind;
    for(int i = 0; i < reverseLine[cur].size(); i++){
        if(!visited[reverseLine[cur][i]]){
            reverseDfs(reverseLine[cur][i]);
        }
    }

}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        memset(visited,false,sizeof(visited));
        memset(scc,0,sizeof(scc));
        memset(sccInpNum,0,sizeof(sccInpNum));
        for(int i = 0; i < maxArea; i++){
            line[i].clear();
            reverseLine[i].clear();
        }
        while(!S.empty()) S.pop();
        ind = -1;

        std::cin >> N >> M;

        for(int i = 0; i < M; i++){

            int a, b;
            std::cin >> a >> b;

            line[a].push_back(b);
            reverseLine[b].push_back(a);

        }

        for(int i = 0; i < N; i++){
            if(!visited[i]){
                dfs(i);
            }
        }

        memset(visited,false,sizeof(visited));

        while(!S.empty()){
            if(!visited[S.top()]){
                ind++;
                reverseDfs(S.top());
            }
            S.pop();
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < line[i].size(); j++){
                if(scc[i] != scc[line[i][j]]){
                    sccInpNum[scc[line[i][j]]]++;
                }
            }
        }


        int ansInd;
        int confused = 0;

        for(int i = 0; i <= ind; i++){
            if(sccInpNum[i] == 0){
                confused++;
                ansInd = i;
            }
        }

        if(confused > 1){
            std::cout << "Confused\n";
        } else {
            for(int i = 0; i < N; i++){
                if(scc[i] == ansInd) {
                    std::cout << i << '\n';
                }
            }
        }

        std::cout << '\n';

    }

    return 0;
}