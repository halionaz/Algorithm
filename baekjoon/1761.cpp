// 정점들의 거리
// 최소 공통 조상

#include <iostream>
#include <cstring>
#include <vector>

const int log = 16;
const int maxNode = 40001;

int N, M;
std::vector<std::vector<int> > line[maxNode];
int parents[log+1][maxNode];
int dist[log+1][maxNode];
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
    makeTree(1);

    for(int i = 0; i < log; i++){
        for(int j = 1; j <= N; j++){
            if(parents[i][j] != -1){
                parents[i+1][j] = parents[i][parents[i][j]];
                dist[i+1][j] = dist[i][parents[i][j]] + dist[i][j];
            }
        }
    }

    std::cin >> M;

    while(M--){
        int a,b;
        std::cin >> a >> b;
        int ans = 0;
        if(depth[a] < depth[b]){
            int tmp = a;
            a = b;
            b = tmp;
        }
        int d = depth[a] - depth[b];
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