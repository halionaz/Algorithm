// 정점들의 거리
// 최소 공통 조상 & 희소 배열

#include <iostream>
#include <cstring>
#include <vector>

const int log = 16;
const int maxNode = 40001;

int N, M;
std::vector<std::vector<int> > line[maxNode];

// sparse table
int parents[log+1][maxNode]; // 노드의 로그 부모의 노드 번호 저장
int dist[log+1][maxNode]; // 노드의 로그 부모까지의 거리 저장

int depth[maxNode];

void makeTree(int tmp){
    for(int i = 0; i < line[tmp].size(); i++){
        int nextNode = line[tmp][i][0];
        int c = line[tmp][i][1];
        if(depth[nextNode] == -1){
            parents[0][nextNode] = tmp;
            dist[0][nextNode] = c;
            depth[nextNode] = depth[tmp] + 1;
            makeTree(nextNode);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(parents,-1,sizeof(parents));
    memset(dist,0,sizeof(dist));
    memset(depth,-1,sizeof(depth));

    std::cin >> N;

    for(int i = 0; i < N-1; i++){
        int a,b,c;
        std::cin >> a >> b >> c;
        std::vector<int> a1;
        std::vector<int> a2;
        a1.push_back(b);
        a1.push_back(c);
        a2.push_back(a);
        a2.push_back(c);
        line[a].push_back(a1);
        line[b].push_back(a2);
    }

    depth[1] = 0;

    // 1번 노드를 root로 하는 트리 만들기
    makeTree(1);

    // sparse table 만들기
    for(int i = 0; i < log; i++){
        for(int j = 1; j <= N; j++){
            if(parents[i][j] != -1){
                // root가 아니라면
                parents[i+1][j] = parents[i][parents[i][j]];
                dist[i+1][j] = dist[i][parents[i][j]] + dist[i][j];
            }
        }
    }

    std::cin >> M;

    while(M--){
        
        int a,b;
        std::cin >> a >> b;
        // a와 b까지의 거리를 구해야 함

        int ans = 0;
        if(depth[a] < depth[b]){
            int tmp = a;
            a = b;
            b = tmp;
        }
        int d = depth[a] - depth[b]; // 깊이 차이
        int ind = 0;

        while(d){
            if(d%2){
                ans += dist[ind][a];
                a = parents[ind][a];
            }
            d/=2;
            ind++;
        }

        if(a!=b){
            for(int i = log; i >= 0; i--){
                if(parents[i][a] != parents[i][b]){
                    ans += dist[i][a] + dist[i][b];
                    a = parents[i][a];
                    b = parents[i][b];
                }
            }
            ans += dist[0][a] + dist[0][b];
        }
        std::cout << ans << '\n';
    }

    return 0;
}