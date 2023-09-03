// 트리와 쿼리 2
// 최소 공통 조상 & 희소 배열

#include <iostream>
#include <vector>
#include <cstring>

typedef long long ll;

const ll maxNode = 100001;
const ll log = 17;

ll N, M;
std::vector<std::vector<ll> > line[maxNode];
ll parents[log+1][maxNode];
ll dist[maxNode];
ll depth[maxNode];

void makeTree(ll temp){
    for(ll i = 0; i < line[temp].size(); i++){
        ll next = line[temp][i][0];
        ll c = line[temp][i][1];
        if(depth[next] == -1){
            parents[0][next] = temp;
            dist[next] = dist[temp] + c;
            depth[next] = depth[temp] + 1;
            makeTree(next);
        }
    }
}

ll getLCA(ll a, ll b){
    // node A와 node B의 공통 조상 탐색

    if(depth[a] < depth[b]){
        ll tmp = a;
        a = b;
        b = tmp;
    }

    ll d = depth[a] - depth[b];
    ll ind = 0;

    while(d){
        if(d%2){
            a = parents[ind][a];
        }
        ind++;
        d/=2;
    }

    if(a!=b){
        for(ll i = log; i >= 0; i--){
            if(parents[i][a] != parents[i][b]){
                a = parents[i][a];
                b = parents[i][b];
            }
        }
        a = parents[0][a];
    }

    return a;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    memset(parents,-1,sizeof(parents));
    memset(depth,-1,sizeof(depth));

    for(ll i = 0; i < N-1; i++){

        ll u,v,w;

        std::cin >> u >> v >> w;

        std::vector<ll> a1;
        std::vector<ll> a2;

        a1.push_back(v);
        a1.push_back(w);
        a2.push_back(u);
        a2.push_back(w);

        line[u].push_back(a1);
        line[v].push_back(a2);
    }

    depth[1] = 0;
    makeTree(1);

    // 로그 스케일의 Sparse Tree 제작
    for(ll i = 0; i < log; i++){
        for(ll j = 1; j <= N; j++){
            if(parents[i][j] != -1){
                parents[i+1][j] = parents[i][parents[i][j]];
            }
        }
    }

    std::cin >> M;

    while(M--){

        ll control;

        std::cin >> control;

        if(control == 1){

            ll u,v;

            std::cin >> u >> v;

            ll distAns = dist[u] + dist[v] - 2*dist[getLCA(u, v)];

            std::cout << distAns << '\n';

        } else {

            ll u,v,k;

            std::cin >> u >> v >> k;

            k--;
            ll lca = getLCA(u, v);
            ll diff = depth[u] - depth[lca];

            if(diff >= k){

                for(int i = 0; k; i++){
                    if(k & 1){
                        u = parents[i][u];
                    }
                    k >>= 1;
                }
                std::cout << u << '\n';

            } else {
                k = depth[v] - depth[lca] + diff - k;
                for(int i = 0; k; i++){
                    if(k & 1){
                        v = parents[i][v];
                    }
                    k >>= 1;
                }
                std::cout << v << '\n';
            }
        }
    }
}