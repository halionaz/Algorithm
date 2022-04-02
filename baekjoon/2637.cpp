// 장난감 조립
// 위상 정렬 & 다이나믹 프로그래밍

// 역행 간선을 저장하여 위상 정렬시키는 방법과
// 2차원 dp로 각 부품의 필요 개수를 계속해서 저장하는 방법이 있음

// 본 풀이에서는 역행 간선 사용
// 기본부품이 4가지만 있는게 아니라는 점을 깨닫지 못해 여러번 틀림

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M, X, Y, K;
int indegree[101];
int cnt[101];
std::vector<std::pair<int, int> > line[101];
std::queue<int> que;
std::vector<int> ans;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < M; i++){
        std::cin >> X >> Y >> K;
        line[X].push_back(std::make_pair(Y,K));
        indegree[Y]++;
    }
    // 마지막 부품이 무조건 indegree 0으로 시작
    que.push(N);
    cnt[N] = 1;

    while(!que.empty()){
        int cur = que.front();
        que.pop();

        if(line[cur].empty()){
            ans.push_back(cur);
        }

        for(int i = 0; i < line[cur].size(); i++){
            int next = line[cur][i].first;
            int count = line[cur][i].second;
            if(--indegree[next] == 0){
                que.push(next);
            }
            cnt[next] += cnt[cur]*count;
        }
    }

    std::sort(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++){
        std::cout << ans[i] << ' ' << cnt[ans[i]] << '\n';
    }

    return 0;
}