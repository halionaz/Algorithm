// 임계경로

#include <iostream>
#include <vector>
#include <cstring>

const int maxCity = 10001;

int N,M;
int start,end;
int max, roadMax;
std::vector<std::vector<int> > road[maxCity];
int dp[maxCity];
bool visited[maxCity];

int dfs(int tmp){
    if(tmp == end){
        return 0;
    } else {
        for(int i = 0; i < road[tmp].size(); i++){
            if(!visited[road[tmp][i][0]]){
                int nextVal = dfs(road[tmp][i][0]);
                if(nextVal+road[tmp][i][1] > dp[tmp]){
                    dp[tmp] = nextVal+road[tmp][i][1];
                }
            } else {
                if(dp[road[tmp][i][0]] + road[tmp][i][1] > dp[tmp]){
                    dp[tmp] = dp[road[tmp][i][0]] + road[tmp][i][1];
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
            if(!road[tmp][i][2]){
                wayCnt += roadDfs(road[tmp][i][0],cost+road[tmp][i][1]);
                road[tmp][i][2] = 1;
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
        int s,e,c;
        std::cin >> s >> e >> c;
        std::vector<int> arr;
        arr.push_back(e);
        arr.push_back(c);
        arr.push_back(0);
        road[s].push_back(arr);
    }

    std::cin >> start >> end;

    max = dfs(start);
    roadMax = roadDfs(start,0) - 1;

    std::cout << max << '\n' << roadMax << '\n';

    return 0;

}