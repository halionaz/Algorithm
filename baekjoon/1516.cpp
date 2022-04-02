// 게임 개발
// 위상 정렬 & 다이나믹 프로그래밍

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, a;
int indegree[501] = {0};
int times[501];
int dp[501] = {0};
std::vector<std::vector<int> > order(501);
std::queue<int> que;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 1; i <= N; i++){
        std::cin >> times[i] >> a;
        while(a != -1){
            order[a].push_back(i);
            indegree[i]++;
            std::cin >> a;
        }
    }

    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0){
            que.push(i);
            dp[i] = times[i];
        }
    }

    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(int i = 0; i < order[cur].size(); i++){
            if(--indegree[order[cur][i]] == 0){
                que.push(order[cur][i]);
            }
            dp[order[cur][i]] = std::max(dp[order[cur][i]], dp[cur] + times[order[cur][i]]);
        }
    }

    for(int i = 1; i <= N; i++){
        std::cout << dp[i] << '\n';
    }

    return 0;
}