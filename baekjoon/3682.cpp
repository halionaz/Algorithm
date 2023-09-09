// 동치 증명
// 강한 연결 요소
// 코사라주 알고리즘

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

int T, N, M, ind;
int scc[20001];
bool visited[20001];
std::vector<int> line[20001];
std::vector<int> rev_line[20001];
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
    for(int i = 0; i < rev_line[cur].size(); i++){
        if(!visited[rev_line[cur][i]]){
            rev_dfs(rev_line[cur][i]);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        // 변수 초기화
        ind = 0;
        for(int i = 0; i < 20001; i++){
            line[i].clear();
            rev_line[i].clear();
        }

        std::cin >> N >> M;

        while(M--){

            int s1, s2;

            std::cin >> s1 >> s2;
            line[s1].push_back(s2);
            rev_line[s2].push_back(s1);
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

        if(ind == 1){
            // 모든 명제들이 이미 동치로 묶여 있음
            std::cout << "0\n";
            continue;
        }

        std::vector<int> inN(ind, 0), outN(ind, 0);

        for(int i = 1; i <= N; i++){
            for(int j = 0; j < line[i].size(); j++){
                if(scc[i] != scc[line[i][j]]){
                    outN[scc[i]]++;
                    inN[scc[line[i][j]]]++;
                }
            }
        }
        int in0 = 0, out0 = 0;
        for(int i = 0; i < ind; i++){
            if(!inN[i]){
                in0++;
            }
            if(!outN[i]){
                out0++;
            }
        }
        std::cout << std::max(in0, out0) << '\n';
    }

    return 0;
}