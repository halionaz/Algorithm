// 문
// 강한 연결 요소 & 2-sat
// 타잔 알고리즘

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

typedef long long ll;
typedef std::pair<int, int> pi;

const int MAX = 1000004;
int V, E, S, T;
int ind;
int visited[MAX]; 
bool scc[MAX];
std::vector<std::vector<int> > line;   
int sccInd=0; 

std::vector<int> res;
std::stack<int> stck;

int getSCC(int x){

    visited[x] = ++ind;
    int parent = visited[x];
    stck.push(x);

    for (int i = 0; i < line[x].size(); i++){
        int nxt = line[x][i];

        if (visited[nxt] == 0){
            // 아직 방문도 하지 않은 정점이면
            // scc 재귀 실행
            parent = std::min(parent, getSCC(nxt));
        } else if (!scc[nxt]){
            // 방문은 했지만, scc에 포함되지 않은 정점이면
            // 스택에 있는 정점을 ret이 나올 때 까지 차례로 빼며
            // scc로 묶어줌
            parent = std::min(parent, visited[nxt]);
        }
    }
    if (parent == visited[x]){
        while (1){
            int top = stck.top();
            stck.pop();
            // top은 sccInd번 scc에 속함
            res[top] = sccInd;
            scc[top] = true;
            if (top == x){
                break;
            }
        }
        sccInd++;
    }
    return parent;
}

int rev(int n){
    return n % 2 ? n - 1 : n + 1;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> E >> V;
    line = std::vector<std::vector<int> >(MAX, std::vector<int>());
    
    res = std::vector<int>(MAX, 0);

    for (int i = 0; i < E; i++){
        int at, bt, ac, bc;
        std::cin >> at >> ac >> bt >> bc;
        at = (ac == 0) ? ((at - 1) * 2) : (at * 2 - 1);
        bt = (bc == 0) ? ((bt - 1) * 2) : (bt * 2 - 1);

        // ~at이면 bt라도 만족해야 함
        line[rev(at)].push_back(bt);
        // ~bt이면 at라도 만족해야 함
        line[rev(bt)].push_back(at);
    }

    for (int i = 0; i < 2 * V; i++){
        if (!visited[i]){
            getSCC(i);
        }
    }

    for (int i = 0; i < V; i++){
        if (res[i * 2] == res[i * 2 + 1]){
            // 모순되는 경우 발생
            std::cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    line = std::vector<std::vector<int> >();
    std::vector<pi> order;

    for(int i = 0; i < 2* V; i++){
        order.push_back(std::make_pair(res[i],i));
    }

    std::sort(order.begin(),order.end(),std::greater<pi>());
    std::fill(res.begin(),res.end(),-1);

    for(pi p : order){
        int cur = p.second;
        if(res[(cur)/2] == -1){
            res[(cur)/2] = cur%2 ? 0 : 1;
        }
    }

    for(int i = 0; i < V; i++){
        std::cout << res[i] << '\n';
    }

    return 0;
}