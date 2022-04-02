// LCA
// 최소 공통 조상

#include <iostream>
#include <vector>
#include <cstring>

const int log = 16;

int N,M;
int parents[log+1][100001]; 
int depth[100001];
std::vector<int> line[100001];

void makeTree(int cur){
    for(int i = 0; i < line[cur].size();i++){
        int next = line[cur][i];
        if(depth[next] == -1){
            parents[0][next] = cur;
            depth[next] = depth[cur] + 1;
            makeTree(next);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> N;

    memset(parents,-1,sizeof(parents));
    memset(depth,-1,sizeof(depth));

    for(int i = 0; i < N-1; i++){
        int a, b;
        std::cin >> a >> b;
        line[a].push_back(b);
        line[b].push_back(a);
    }

    depth[1] = 0;

    makeTree(1);

    for(int i = 0; i < log; i++){
        for(int j = 1; j <= N; j++){
            if(parents[i][j] != -1){
                parents[i+1][j] = parents[i][parents[i][j]];
            }
        }
    }

    std::cin >> M;
    
    while(M--){
        int a,b;
        std::cin >> a >> b;
        if(depth[a] < depth[b]){
            int tmp = a;
            a = b;
            b = tmp;
        }
        int dist = depth[a] - depth[b];
        int ind = 0;
        while(dist){
            if(dist%2){
                a = parents[ind][a];
            }
            ind++;
            dist /= 2;
        }

        if(a != b){
            for(int i = log; i >= 0; i--){
                while(parents[i][a] != parents[i][b]){
                    a = parents[i][a];
                    b = parents[i][b];
                }
            }
            a = parents[0][a];
        }
        std::cout << a << '\n';
    }

    return 0;
}