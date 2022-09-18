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
ll cost[log+1][maxNode];
ll depth[maxNode];

void makeTree(ll temp){
    for(ll i = 0; i < line[temp].size(); i++){
        ll next = line[temp][i][0];
        ll c = line[temp][i][1];
        if(depth[next] == -1){
            parents[0][next] = temp;
            cost[0][next] = c;
            depth[next] = depth[temp] + 1;
            makeTree(next);
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> N;
    memset(parents,-1,sizeof(parents));
    memset(cost,0,sizeof(cost));
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

    for(ll i = 0; i < log; i++){
        for(ll j = 1; j <= N; j++){
            if(parents[i][j] != -1){
                parents[i+1][j] = parents[i][parents[i][j]];
                cost[i+1][j] = cost[i][parents[i][j]] + cost[i][j];
            }
        }
    }

    std::cin >> M;

    while(M--){
        ll control;
        std::cin >> control;
        if(control == 1){
            ll u,v;
            ll distAns = 0;
            std::cin >> u >> v;
            if(depth[u] < depth[v]){
                ll tmp = u;
                u = v;
                v = tmp;
            }

            ll d = depth[u] - depth[v];
            ll ind = 0;
            while(d){
                if(d%2){
                    distAns += cost[ind][u];
                    u = parents[ind][u];
                }
                ind++;
                d/=2;
            }
            if(u!=v){
                for(ll i = log; i >= 0; i--){
                    if(parents[i][u] != parents[i][v]){
                        distAns += cost[i][u] + cost[i][v];
                        u = parents[i][u];
                        v = parents[i][v];
                    }
                }
                distAns += cost[0][u] + cost[0][v];
            }
            std::cout << distAns << '\n';
        } else {

            ll u,v,k;
            std::cin >> u >> v >> k;
            k--;

            //lca 구하기
            ll a = u, b = v;
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
            ll lca = a;

            ll diff = depth[u] - depth[lca];
            if(diff >= k){
                for(int i = 0; k; i++){
                    if(k&1){
                        u = parents[i][u];
                    }
                    k >>= 1;
                }
                std::cout << u << '\n';
            } else {
                k = depth[v] - depth[lca] + diff - k;
                for(int i = 0; k; i++){
                    if(k&1){
                        v = parents[i][v];
                        k >>= 1;
                    }
                }
                std::cout << v << '\n';
            }
        }
    }
}


// 통과 코드 (위 코드는 C++ 실력 부족으로 인한 시간 초과)

// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;
// typedef pair<ll, ll> p;

// vector<p> g[101010];

// ll dp[101010][22];
// ll dist[101010];
// ll dep[101010];
// ll n;

// bool chk[101010];
// void dfs(ll now, ll d, ll c){
// 	chk[now] = 1;
// 	dep[now] = d;
// 	dist[now] = c;
// 	for(auto i : g[now]){
// 		ll nxt = i.first;
// 		if(chk[nxt]) continue;
// 		ll nxtCost = i.second + c;
// 		dp[nxt][0] = now;
// 		dfs(nxt, d+1, nxtCost);
// 	}
// }
// void makeTree(){
// 	for(int j=1; j<22; j++){
// 		for(int i=1; i<=n; i++){
// 			dp[i][j] = dp[dp[i][j-1]][j-1];
// 		}
// 	}
// }
// ll getLca(ll u, ll v){
// 	if(dep[u] > dep[v]) swap(u, v);
// 	ll diff = dep[v] - dep[u];
// 	for(int i=0; diff; i++){
// 		if(diff & 1) v = dp[v][i];
// 		diff >>= 1;
// 	}
// 	if(u == v) return u;
// 	for(int i=21; i>=0; i--){
// 		if(dp[u][i] != dp[v][i]) u = dp[u][i], v = dp[v][i];
// 	}
// 	return dp[u][0];
// }
// ll getDist(ll u, ll v){
// 	ll lca = getLca(u, v);
// 	return dist[u] + dist[v] - 2*dist[lca];
// }
// ll getkth(ll u, ll v, ll k){
// 	ll lca = getLca(u, v);
// 	ll diff = dep[u] - dep[lca];
// 	k--;
// 	if(diff >= k){
// 		for(int i=0; k; i++){
// 			if(k & 1) u = dp[u][i];
// 			k >>= 1;
// 		}
// 		return u;
// 	}

// 	k = dep[v] - dep[lca] + diff - k;
// 	for(int i=0; k; i++){
// 		if(k & 1) v = dp[v][i];
// 		k >>= 1;
// 	}
// 	return v;
// }
// int main(){
// 	ios_base::sync_with_stdio(0); cin.tie(0);
// 	cin >> n;
// 	for(int i=1; i<n; i++){
// 		ll s, e, x; cin >> s >> e >> x;
// 		g[s].push_back({e, x});
// 		g[e].push_back({s, x});
// 	}
// 	dfs(1, 1, 0); 
//     makeTree();
// 	int m; cin >> m;
// 	while(m--){
// 		int op; cin >> op;
// 		if(op == 1){
// 			ll a, b; cin >> a >> b;
// 			cout << getDist(a, b) << "\n";
// 		}else{
// 			ll a, b, c; cin >> a >> b >> c;
// 			cout << getkth(a, b, c) << "\n";
// 		}
// 	}
// }