// 임계경로
// 깊이 우선 탐색 & 다이나믹 프로그래밍
// top-down

#include <iostream>
#include <vector>
#include <cstring>

const int maxCity = 10001;

struct r{
    int end;
    int cost;
    bool searched;
};

int N,M;
int start,end;
int max, roadMax;
std::vector<r> road[maxCity];
int dp[maxCity];
bool visited[maxCity];

int dfs(int tmp){
    if(tmp == end){
        return 0;
    } else {
        for(int i = 0; i < road[tmp].size(); i++){
            if(!visited[road[tmp][i].end]){
                int nextVal = dfs(road[tmp][i].end);
                if(nextVal+road[tmp][i].cost > dp[tmp]){
                    dp[tmp] = nextVal + road[tmp][i].cost;
                }
            } else {
                if(dp[road[tmp][i].end] + road[tmp][i].cost > dp[tmp]){
                    dp[tmp] = dp[road[tmp][i].end] + road[tmp][i].cost;
                }
            }
        }
        visited[tmp] = true;
        return dp[tmp];
    }
}

int roadDfs(int tmp, int cost){
    if(cost + dp[tmp] == max){
        int wayCnt = 1;

        for(int i = 0; i < road[tmp].size(); i++){
            if(!road[tmp][i].searched){
                // 이 도로에도 최대가 되게 하는 경로가 있는지 탐색해보자
                wayCnt += roadDfs(road[tmp][i].end,cost+road[tmp][i].cost);
                road[tmp][i].searched = true;
            }
        }

        return wayCnt;

    } else {
        return 0;
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(visited,false,sizeof(visited));
    memset(dp,0,sizeof(dp));

    std::cin>> N >> M;

    for(int i = 0; i < M; i++){
        int s;
        r cur;
        std::cin >> s >> cur.end >> cur.cost;
        cur.searched = false;
        road[s].push_back(cur);
    }

    std::cin >> start >> end;

    max = dfs(start); // 만나는 시간
    roadMax = roadDfs(start,0) - 1; // 최대 시간이 걸리는 도로 개수

    std::cout << max << '\n' << roadMax << '\n';

    return 0;

}