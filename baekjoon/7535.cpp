// A Bug’s Life
// 강한 연결 요소 & 2-sat
// 코사라주 알고리즘

#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

int T;
int N, I;
int ind = -1;
std::vector<int> line[2001*2];
std::vector<int> reverseLine[2001*2];
int visited[2001*2];
int scc[2001*2];
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

    std::cin >> T;

    for(int t = 1; t <= T; t++){

        // 초기화
        for(int i = 0; i < 2001*2; i++){
            line[i].clear();
            reverseLine[i].clear();
        }

        // 벌레의 수, 관계의 수
        std::cin >> N >> I;

        for(int i = 0; i < I; i++){
            int a, b;
            std::cin >> a >> b;
            // a가 수컷이면 b는 암컷
            // b가 수컷이면 a는 암컷
            line[a*2-1].push_back(b*2);
            line[b*2-1].push_back(a*2);
            line[a*2].push_back(b*2-1);
            line[b*2].push_back(a*2-1);
            reverseLine[b*2].push_back(a*2-1);
            reverseLine[a*2].push_back(b*2-1);
            reverseLine[b*2-1].push_back(a*2);
            reverseLine[a*2-1].push_back(b*2);
        }

        memset(visited,false,sizeof(visited));

        // 순방향 탐색
        for(int i = 1; i <= N; i++){
            if(!visited[i*2-1]){
                DFS(i*2-1);
            }
            if(!visited[i*2]){
                DFS(i*2);
            }
        }

        memset(visited,false,sizeof(visited));

        // 역방향 탐색
        while(!stck.empty()){
            if(!visited[stck.top()]){
                ind++;
                reverseDFS(stck.top());
            }
            stck.pop();
        }

        bool done = false;

        std::cout << "Scenario #" << t << ":\n";

        for(int i = 1; i <= N; i++){
            if(scc[i*2-1] == scc[i*2]){
                // a와 !a가 같은 scc 안에 포함되어 있으므로 이 명제는 성립할 수 없음
                done = true;
                break;
            }
        }

        if(!done){
            std::cout << "No suspicious bugs found!\n";
        } else {
            std::cout << "Suspicious bugs found!\n";
        }

        std::cout << '\n';

    }

    return 0;
}