// ACM Craft
// 위상 정렬 & 다이나믹 프로그래밍

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
int tc,N,K,W;
int main(){
    std::cin >> tc;
    while(tc--){
        int inputNum[1001], times[1001], dp[1001];
        std::vector<int> order[1001];
        memset(inputNum,0,sizeof(inputNum));
        memset(times,0,sizeof(times));
        memset(dp,0,sizeof(dp));
        std::cin >> N >> K;
        for(int i = 1; i<=N; i++){
            std::cin >> times[i];
        }
        for(int i = 0; i < K; i++){
            int x,y;
            std::cin >> x >> y;
            order[x].push_back(y);
            inputNum[y]++;
        }
        std::cin>>W;
        std::queue<int> q;
        for(int i = 1; i<= N; i++){
            if(!inputNum[i]){
                q.push(i);
                dp[i] = times[i];
            }
        }
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            if(temp == W){
                break;
            } else {
                for(int i = 0; i < order[temp].size(); i++){
                    if(--inputNum[order[temp][i]] == 0){
                        q.push(order[temp][i]);
                    }
                    if(dp[order[temp][i]] < dp[temp] + times[order[temp][i]]){
                        dp[order[temp][i]] = dp[temp] + times[order[temp][i]];
                    }
                }
            }
        }
        std::cout << dp[W] <<'\n';
    }
}