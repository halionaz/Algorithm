// 특정 거리의 도시 찾기
// 너비 우선 탐색

// 답 오름차순 정렬을 안해서 황당하게 틀린 문제
// 다익스트라로 풀어도 될 듯 하다

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

int N, M, K, X;
int dist[300001];
std::vector<int> line[300001];
std::queue<int> que;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(dist, -1, sizeof(dist));

    std::cin>>N>>M>>K>>X;

    for(int i = 0; i < M; i++){
        int A, B;
        std::cin >> A >> B;
        line[A].push_back(B);
    }

    que.push(X);
    dist[X] = 0;

    std::vector<int> answer;

    while(!que.empty()){
        int cur = que.front();
        que.pop();
        if(dist[cur] == K){
            answer.push_back(cur);
        } else if(dist[cur] == K+1){
            break;
        }
        for(int i = 0; i < line[cur].size(); i++){
            if(dist[line[cur][i]] == -1){
                // 아직 방문 X
                que.push(line[cur][i]);
                dist[line[cur][i]] = dist[cur] + 1;
            }
        }
    }

    if(answer.size()){
        std::sort(answer.begin(), answer.end());
        for(int i = 0; i < answer.size(); i++){
            std::cout << answer[i] << '\n';
        }
    } else {
        std::cout << -1 << '\n';
    }

    return 0;
}