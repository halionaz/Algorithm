// 한동이는 영업사원!
// 최소 공통 조상

#include <iostream>
#include <vector>
#include <cstring>

const int log = 15;
const int maxNum = 30001;

int N;
int depth[maxNum];
int parents[log+1][maxNum];
std::vector<int> road[maxNum];

void makeTree(int tmp){
    for(int i = 0; i < road[tmp].size(); i++){
        int next = road[tmp][i];
        if(depth[next] == -1){
            parents[0][next] = tmp;
            depth[next] = depth[tmp]+1;
            makeTree(next);
        }
    }
}

int main(){
    memset(depth,-1,sizeof(depth));
    memset(parents,-1,sizeof(parents));
    std::cin >> N;
    for(int i = 0; i < N-1; i++){
        int a,b;
        std::cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
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

    int M;
    int ans = 0;
    std::cin >> M;
    int prev = 1;
    while(M--){
        // a to b
        int next;
        std::cin >> next;

        int a = prev;
        int b = next;

        if(depth[a] < depth[b]){
            int tmp = a;
            a = b;
            b = tmp;
        }
        int d = depth[a] - depth[b];
        int ind = 0;
        while(d){
            if(d%2){
                a = parents[ind][a];
            }
            d/=2;
            ind++;
        }
        if(a != b){
            for(int i = log; i >= 0; i--){
                if(parents[i][a] != parents[i][b]){
                    a = parents[i][a];
                    b = parents[i][b];
                }
            }
            a = parents[0][a];
        }

        ans += depth[prev] + depth[next] - depth[a]*2;

        prev = next;

    }

    std::cout << ans << '\n';
    return 0;
}