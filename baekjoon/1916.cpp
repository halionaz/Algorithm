// 최소비용 구하기
// 데이크스트라

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

const int inf = 987654321;

int N, M, a, b, c;
int memo[1001];
std::vector<std::pair<int, int> >  line[1001];
std::priority_queue<std::pair<int, int> > que;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < 1001; i++){
        memo[i] = inf;
    }

    for(int i = 0; i < M; i++){
        std::cin >> a >> b >> c;
        line[a].push_back(std::make_pair(b,c));
    }

    int start, end;
    std::cin >> start >> end;

    memo[start] = 0;
    que.push(std::make_pair(0,start));

    while(!que.empty()){
        int dist = que.top().first * -1;
        int ind = que.top().second;
        que.pop();
        if(memo[ind] < dist){
            // 이미 다른 노드에서 이 노드로 오는 더 빠른 경우를 탐색했다면 pass
            
            // 이미 탐색했다면 현재 ind보다 먼저 탐색된 친구이므로
            // 무조건 dist보다 memo[ind]가 작음
            continue;
        }
        for(int i = 0; i < line[ind].size(); i++){
            int nextNode = line[ind][i].first;
            int newDist = dist + line[ind][i].second;
            if(newDist < memo[nextNode]){
                memo[nextNode] = newDist;
                que.push(std::make_pair(newDist * -1,nextNode));
            }
        }
    }

    std::cout << memo[end] << '\n';

    return 0;
}