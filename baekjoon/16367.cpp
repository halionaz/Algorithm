// TV Show Game
// 강한 연결 요소 & 2-sat
// 코사라주 알고리즘

#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

const int max = 10002;

int k,n;
int ind = 0;
int scc[max];
bool visited[max];
int sccVisited[max];
std::vector<int> line[max];
std::vector<int> reverseLine[max];
std::vector<int> sccList[max];
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
    sccList[ind].push_back(cur);
    for(int j = 0; j < reverseLine[cur].size(); j++){
        if(!visited[reverseLine[cur][j]]){
            reverseDFS(reverseLine[cur][j]);
        }
    }
}

int reverse(int x){
    return ( x % 2 ) ? x + 1 : x - 1;
}

int main(){
    
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> k >> n;

    for(int i = 0; i < n; i++){
        int inp[3];
        for(int j = 0; j < 3; j++){
            char b;
            std::cin >> inp[j] >> b;
            inp[j] = (b=='B') ? inp[j] * 2 - 1 : inp[j] * 2;
        }
        for(int j = 0; j < 3; j++){
            for(int l = 0; l < 3; l++){
                if(j != l){
                    line[reverse(inp[j])].push_back(inp[l]);
                    reverseLine[inp[l]].push_back(reverse(inp[j]));
                }
            }
        }
    }

    memset(visited,false,sizeof(visited));

    for(int i = 1; i <= 2*k; i++){
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

    for(int i = 1; i <= k; i++){
        if(scc[i*2-1] == scc[i*2]){
            // 모순 발생
            std::cout << -1 << '\n';
            return 0;
        }
    }

    memset(sccVisited,-1,sizeof(sccVisited));

    for(int i = 1; i <= ind; i++){
        if(sccVisited[i] == -1){
            sccVisited[i] = 0;
            for(int j = 0; j < sccList[i].size(); j++){
                int rev = reverse(sccList[i][j]);
                sccVisited[scc[rev]] = 1;
            }
        }
    }

    for(int i = 1; i <= k; i++){
        std::cout << (sccVisited[scc[i*2-1]]?'B':'R');
    }
    std::cout<< '\n';

    return 0;
}