// 사탕 돌리기
// 깊이 우선 탐색 & 다이나믹 프로그래밍

// dp와 사이클 체크의 기묘한 조합
// 기본적으로 dfs를 통해 가장 큰 경우의 수를 책정하지만
// 모든 노드를 탐색할 경우 시간초과가 남
// 따라서 사이클이 생기는 경우, 미리 사이클에 속한 노드의 dp를 설정해서 반복되는 탐색을 방지

// 다른 분들은 강한 연결 요소로도 푼 것 같은데,
// 어떻게 접근하는지 잘 모르겠음

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

const int inf = 1<<29;

int N, ans = 0;
int dp[200001]; // dp[i] :: i번 노드를 순환하는 사이클 칸 수
bool visited[200001];
std::stack<int> stck;

int dfs(int cur){
    if(dp[cur] != inf){
        // 이미 사이클이 계산된 애는 계산값 반환
        return dp[cur];
    }

    if(visited[cur]){

        // 만약 방문한 점에 도달했다면 사이클 계산

        std::vector<int> scc;

        int scc_size = 0;

        while(!stck.empty()){
            // cur에 다시 도달할 때 까지 stck에서 뽑아서 사이즈 계산
            scc.push_back(stck.top());
            scc_size++;
            if(stck.top() == cur){
                stck.pop();
                break;
            }
            stck.pop();
        }

        for(int i = 0; i < scc.size(); i++){
            dp[scc[i]] = scc_size;
        }

        return dp[cur];

    } else {

        stck.push(cur);
        // 사이클 계산을 위해 stck에 삽입
        visited[cur] = true;

        int j = 0, tmp = cur;
        while(tmp){
            j += tmp % 10;
            tmp /= 10;
        }
        int next = (cur + j)%N;
        if(next == 0){
            next = N;
        }

        int val = dfs(next);

        // 다음 노드로 dfs 진행
        // 사이클이 생기므로 dp[cur]에 값이 들어옴
        if(dp[cur] == inf){
            // 사이클이 안 생긴 경우 (cur에서 시작해서 사이클에 진입했으나, 정작 cur은 사이클에 속하지 않을 수 있음)
            dp[cur] = val + 1;
            stck.pop();
        }

        return dp[cur];

    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    std::fill(dp, dp + N + 1, inf);

    for(int i = 1; i <= N; i++){
        ans = std::max(ans, dfs(i));
    }
    
    std::cout << ans << '\n';

    return 0;
}