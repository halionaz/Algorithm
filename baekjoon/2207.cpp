// 가위바위보
// 강한 연결 요소 & 2-sat
// 코사라주 알고리즘

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

const int max = 10001;

int N, M, ind = -1;
int scc[max*2];
bool visited[max*2];
std::vector<int> line[max*2];
std::vector<int> reversed_line[max*2];
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

void reverse_dfs(int cur){
    visited[cur] = true;
    scc[cur] = ind;
    for(int i = 0; i < reversed_line[cur].size(); i++){
        if(!visited[reversed_line[cur][i]]){
            reverse_dfs(reversed_line[cur][i]);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < N; i++){
        int x,y;
        std::cin >> x >> y; // x번째에 낼 것과 y번째에 낼 것
        x = x < 0 ? (-x)*2 : x*2-1; 
        y = y < 0 ? (-y)*2 : y*2-1;
        line[x%2?x+1:x-1].push_back(y); // !x -> y
        reversed_line[y].push_back(x%2?x+1:x-1); // 역방향 그래프 추가
        line[y%2?y+1:y-1].push_back(x); // !y -> x
        reversed_line[x].push_back(y%2?y+1:y-1); // 역방향 그래프 추가
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

    memset(visited,false,sizeof(visited));

    while(!stck.empty()){
        if(!visited[stck.top()]){
            ind++;
            reverse_dfs(stck.top());
        }
        stck.pop();
    }

    for(int i = 1; i <= M; i++){
        if(scc[i*2-1] == scc[i*2]){
            // x와 !x가 같은 scc 안에 포함되어 있으므로 이 명제는 성립할 수 없음
            std::cout << "OTL" << '\n';
            return 0;
        }
    }

    std::cout << "^_^" << '\n';

    return 0;
}