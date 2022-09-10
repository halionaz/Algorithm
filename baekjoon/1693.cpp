// 트리 색칠하기
// 다이나믹 프로그래밍 & 트리에서의 다이나믹 프로그래밍
// top-down

#include <iostream>
#include <vector>
#include <algorithm>

const int inf = 999999999;

int N;
std::vector<int> line[100001];
int dp[100001][19];
// n개의 노드를 칠하는데 log_2^n 종류 색 필요
// dp[i][j] :: i 노드가 j 색일 때 i노드가 부모인 서브트리를 만드는 최소 비용

int query(int node, int prevNode, int color){
    if(dp[node][color]){
        return dp[node][color];
    } else {
        dp[node][color] = color;
        for(int i = 0; i < line[node].size(); i++){
            int min = inf;
            if(line[node][i] != prevNode){
                for(int c = 1; c <= 18; c++){
                    if(c != color){
                        min = std::min(min, query(line[node][i], node, c));
                    }
                }
                dp[node][color] += min;
            }
        }
    }
    return dp[node][color];
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 1; i <= N-1; i++){
        int a, b;
        std::cin >> a >> b;
        line[a].push_back(b);
        line[b].push_back(a);
    }

    int ans = inf;

    for(int i = 1; i <= 18; i++){
        ans = std::min(ans, query(1,0,i));
    }

    std::cout << ans << '\n';

    return 0;
}