// 그래프의 싱크
// 강한 연결 요소
// 코사라주 알고리즘

#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>

int N, M, ind;
bool visited[5001];
int scc[5001], outDegree[5001];
std::vector<int> line[5001];
std::vector<int> rev_line[5001];
std::vector<int> scc_vec[5001];
std::stack<int> stck;

void dfs(int cur){
    visited[cur] = true;
    for(int i = 0; i < line[cur].size(); i++){
        if(!visited[line[cur][i]]){
            dfs(line[cur][i]);
        }
    }
    stck.push(cur);
}

void rev_dfs(int cur){
    visited[cur] = true;
    scc[cur] = ind;
    scc_vec[ind].push_back(cur);
    for(int i = 0; i < rev_line[cur].size(); i++){
        if(!visited[rev_line[cur][i]]){
            rev_dfs(rev_line[cur][i]);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(1){

        ind = 0;

        for(int i = 0; i < 5001; i++){
            line[i].clear();
            rev_line[i].clear();
            scc_vec[i].clear();
        }

        std::cin >> N;
        if(!N){
            // 0 입력 시 종료
            break;
        }
        
        std::cin >> M;

        while(M--){
            int v, w;
            std::cin >> v >> w;
            line[v].push_back(w);
            rev_line[w].push_back(v);
        }

        memset(visited, false, sizeof(visited));

        for(int i = 1; i <= N; i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        memset(visited, false, sizeof(visited));
        while(!stck.empty()){
            if(!visited[stck.top()]){
                rev_dfs(stck.top());
                ind++;
            }
            stck.pop();
        }

        memset(outDegree, 0, sizeof(outDegree));

        for(int i = 1; i <= N; i++){
            for(int j = 0; j < line[i].size(); j++){
                if(scc[i] != scc[line[i][j]]){
                    // i -> j 간선이 있는데, i와 j의 집합이 다르다는 것은, j에서 i로 돌아오진 못한다는 것
                    // 띠라서 scc[i]는 싱크가 아님
                    outDegree[scc[i]]++;
                }
            }
        }

        std::vector<int> ans;

        for(int i = 0; i < ind; i++){
            if(outDegree[i] == 0){
                // i번째 scc가 싱크라면
                for(int j = 0; j < scc_vec[i].size(); j++){
                    // 그 scc 내에 있는 모든 노드 ans에 추가
                    ans.push_back(scc_vec[i][j]);
                }
            }
        }

        std::sort(ans.begin(),ans.end());

        for(int i = 0; i < ans.size(); i++){
            std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
        
    }

    return 0;
}