// 하우스 M.D.
// 강한 연결 요소 & 2-sat

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

const int max_symptom = 20001;

int N, M, ind;
int scc[max_symptom*2];
bool visited[max_symptom*2];
std::vector<int> line[max_symptom*2];
std::vector<int> reversed_line[max_symptom*2];
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
    for(int i = 0; i < reversed_line[cur].size(); i++){
        if(!visited[reversed_line[cur][i]]){
            rev_dfs(reversed_line[cur][i]);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(true){

        ind = -1;

        for(int i = 0; i < max_symptom*2; i++){
            line[i].clear();
            reversed_line[i].clear();
        }

        std::cin >> N >> M;

        if(!N && !M){
            break;
        }

        for(int i = 0; i < N; i++){
            int a, b;
            std::cin >> a >> b;
            a = a < 0 ? (-a)*2 : a*2-1;
            b = b < 0 ? (-b)*2 : b*2-1;
            line[a].push_back(b%2?b+1:b-1);
            reversed_line[b%2?b+1:b-1].push_back(a);
            line[b].push_back(a%2?a+1:a-1);
            reversed_line[a%2?a+1:a-1].push_back(b);
        }

        memset(visited,false,sizeof(visited));

        for(int i = 1; i <= M; i++){
            if(!visited[i*2-1]){
                dfs(i*2-1);
            }
            if(!visited[i*2]){
                dfs(i*2);
            }
        }

        memset(visited, false, sizeof(visited));

        while(!stck.empty()){
            if(!visited[stck.top()]){
                ind++;
                rev_dfs(stck.top());
            }
            stck.pop();
        }

        int ans = 1;

        for(int i = 1; i <= M; i++){
            if(scc[i*2-1] == scc[i*2]){
                ans = 0;
                break;
            }
        }

        std::cout << ans << '\n';

    }

    return 0;
}