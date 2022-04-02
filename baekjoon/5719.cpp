// 거의 최단 경로
// 다익스트라 & 너비 우선 탐색

// 다익스트라 알고리즘을 이용해 최단 경로를 지워준 후
// 다시 다익스트라 알고리즘을 써서 거의 최단 경로 탐색 

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

const int inf = 987654322;

int N, M, S, D, U, V, P;
bool visited[500][500];
std::vector<std::pair<int, int> > graph[500];
std::vector<std::pair<int, int> > memo[500];

std::vector<int> dijkstra(){

    // 거리 저장
    std::vector<int> dist(N, inf);
    std::priority_queue<std::pair<int, int> > que;

    dist[S] = 0;
    que.push(std::make_pair(0, S));

    while(!que.empty()){
        int d = que.top().first * -1;
        int cur = que.top().second;
        que.pop();

        if(dist[cur] < d){
            // 이미 탐색했다면 pass
            continue;
        }

        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int nextDist = d + graph[cur][i].second;

            if(graph[cur][i].second == -1){
                // 삭제 되었다면 
                continue;
            }

            if(dist[next] > nextDist){
                dist[next] = nextDist;
                que.push(std::make_pair(-nextDist, next));
                // 경로 추가
                memo[next].clear();
                memo[next].push_back(std::make_pair(cur, nextDist));
            } else if(dist[next] == nextDist){
                memo[next].push_back(std::make_pair(cur, nextDist));
            }
        }
    }

    return dist;

}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(1){

        memset(visited, false, sizeof(visited));
        for(int i = 0; i < 500; i++){
            graph[i].clear();
            memo[i].clear();
        }

        std::cin >> N >> M;

        if(!N && !M){
            break;
        }

        std::cin >> S >> D;

        for(int i = 0; i < M; i++){
            std::cin >> U >> V >> P;
            graph[U].push_back(std::make_pair(V,P));
        }

        dijkstra();

        // 최단 경로 정점 지우기 BFS
        // 역순으로 지움
        std::queue<int> que;

        que.push(D);

        while(!que.empty()){
            int cur = que.front();
            que.pop();

            for(int i = 0; i < memo[cur].size(); i++){
                int next = memo[cur][i].first;
                if(visited[cur][next]) continue;

                visited[cur][next] = true;

                for(int j = 0; j < graph[next].size(); j++){
                    if(graph[next][j].first == cur){
                        graph[next][j].second = -1;
                    }
                }

                que.push(next);
            }
        }

        std::vector<int> ans = dijkstra();

        std::cout << (ans[D] == inf ? -1 : ans[D]) << '\n';

    }

    return 0;
}