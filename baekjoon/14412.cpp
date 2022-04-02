// Ronald
// 애드 혹 & 구성적 & 그래프 이론

// 그래프가 두 완전 그래프로 이루어져 있으면 성립
// 그렇지 않다면 성립 X

// 완전 그래프 두개로만 전체 그래프를 표현할 수 있다면
// 한 완전 그래프의 각 노드를 차례로 토글 하는 것만으로
// 모두 연결 가능

#include <iostream>
#include <vector>

int N, M, a, b;
bool isComplete = true;
bool adj[1001][1001];
bool visited[1001];
std::vector<int> graph; // 한 완전 그래프 간선들 저장
std::vector<int> line[1001];

void dfs(int x){
    visited[x] = true;
    graph.push_back(x);
    for(int i = 0; i < line[x].size(); i++){
        if(!visited[line[x][i]]){
            dfs(line[x][i]);
        }
    }
}

void completeCheck(){
    for(int i = 0; i < graph.size(); i++){
        for(int j = i+1; j < graph.size(); j++){
            if(!adj[graph[i]][graph[j]]){
                isComplete = false;
                return;
            }
        }
    }
}

int main(){
    
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    while(M--){
        std::cin >> a >> b;
        line[a].push_back(b);
        line[b].push_back(a);
        adj[a][b] = 1;
        adj[b][a] = 1;
    }


    int ind = 0; // 그래프 수

    for(int i = 1; i <= N; i++){

        if(ind > 2){
            break;
        }
        if(!visited[i]){
            dfs(i);
            ind++;
            completeCheck();
            graph.clear();
            if(!isComplete){
                break;
            }
        }
    }

    if(ind == 2 && isComplete){
        std::cout << "DA\n";
    } else {
        std::cout << "NE\n";
    }

    return 0;
}