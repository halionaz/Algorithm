// 2-SAT - 3
// 강한 연결 요소 & 2-sat

#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

const int max = 10001;

int N,M;
int ind = -1;
int visited[max*2];
int scc[max*2];
std::vector<int> line[max*2];
std::vector<int> reverseLine[max*2];
std::stack<int> stck;

void DFS(int cur){
    visited[cur] = true;
    for(int i = 0; i < line[cur].size(); i++){
        if(!visited[line[cur][i]]){
            DFS(line[cur][i]);
        }
    }
    stck.push(cur);
}

void reverseDFS(int cur){
    visited[cur] = true;
    scc[cur] = ind;
    for(int i = 0; i < reverseLine[cur].size(); i++){
        if(!visited[reverseLine[cur][i]]){
            reverseDFS(reverseLine[cur][i]);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a,b;
        std::cin >> a >> b;
        a = a < 0 ? (-a)*2 : a*2-1;
        b = b < 0 ? (-b)*2 : b*2-1;
        line[a%2?a+1:a-1].push_back(b);
        reverseLine[b].push_back(a%2?a+1:a-1);
        line[b%2?b+1:b-1].push_back(a);
        reverseLine[a].push_back(b%2?b+1:b-1);
    }

    memset(visited,false,sizeof(visited));

    for(int i = 1; i <= N; i++){
        if(!visited[i*2-1]){
            DFS(i*2-1);
        }
        if(!visited[i*2]){
            DFS(i*2);
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

    for(int i = 1; i <= N; i++){
        if(scc[i*2-1] == scc[i*2]){
            std::cout << 0 << '\n';
            return 0;
        }
    }
    std::cout << 1 << '\n';
    return 0;
}