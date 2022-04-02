// 문
// 강한 연결 요소 & 2-sat

// 메모리 초과

// #include <iostream>
// #include <vector>
// #include <cstring>
// #include <stack>

// const int max = 500001;

// int N, M, ind = -1;
// std::vector<int> scc;
// int visited[max*2];
// std::vector<std::vector<int> > sccVec;
// std::vector<std::vector<int> > line;
// std::vector<std::vector<int> > rev_line;
// std::stack<int> stck;

// void dfs(int cur){
//     visited[cur] = true;
//     for(int i = 0; i < line[cur].size(); i++){
//         if(!visited[line[cur][i]]){
//             dfs(line[cur][i]);
//         }
//     }
//     stck.push(cur);
// }

// void rev_dfs(int cur){
//     visited[cur] = true;
//     scc[cur] = ind;
//     sccVec[ind].push_back(cur);
//     for(int i = 0; i < rev_line[cur].size(); i++){
//         if(!visited[rev_line[cur][i]]){
//             rev_dfs(rev_line[cur][i]);
//         }
//     }
// }

// int main(){

//     std::ios_base::sync_with_stdio(0);
//     std::cin.tie(0);

//     std::cin >> N >> M;
//     // 수로의 개수 N, 스위치 개수 M;
//     line.resize((M+1)*2);
//     rev_line.resize((M+1)*2);
//     scc.resize((M+1)*2);

//     for(int i = 0; i < N; i++){
//         int a,sa,b,sb;
//         std::cin >> a >> sa >> b >> sb;
//         a = sa ? a * 2 - 1 : a * 2;
//         b = sb ? b * 2 - 1 : b * 2;
//         line[a%2?a+1:a-1].push_back(b);
//         rev_line[b].push_back(a%2?a+1:a-1);
//         line[b%2?b+1:b-1].push_back(a);
//         rev_line[a].push_back(b%2?b+1:b-1);
//     }

//     memset(visited,false, sizeof(visited));

//     for(int i = 1; i <= M; i++){
//         if(!visited[i*2-1]){
//             dfs(i*2-1);
//         }
//         if(!visited[i*2]){
//             dfs(i*2);
//         }
//     }

//     memset(visited, false, sizeof(visited));

//     while(!stck.empty()){
//         if(!visited[stck.top()]){
//             ind++;
//             std::vector<int> vec;
//             sccVec.push_back(vec);
//             rev_dfs(stck.top());
//         }
//         stck.pop();
//     }

//     for(int i = 1; i <= M; i++){
//         if(scc[i*2-1] == scc[i*2]){
//             std::cout << "IMPOSSIBLE\n";
//             return 0;
//         }
//     }


//     memset(visited, -1, sizeof(visited));

//     for(int i = 0; i <= ind; i++){
//         if(visited[i] == -1){
//             visited[i] = 0;
//             for(int j = 0; j < sccVec[i].size(); j++){
//                 int node = sccVec[i][j]%2 ? sccVec[i][j] + 1 : sccVec[i][j] - 1;
//                 if(visited[scc[node]] == -1){
//                     visited[scc[node]] = 1;
//                 }
//             }
//         }
//     }
//     for(int i = 1; i <= M; i++){
//         std::cout << visited[scc[i*2-1]] << '\n';
//     }

//     return 0;
// }

// 통과 코드

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

typedef long long ll;
typedef std::pair<int, int> pi;

const int MAX = 1000004;
int V, E, S, T;
int ind;
int visited[MAX]; 
bool fin[MAX];
std::vector<std::vector<int> > line;   
int sccInd=0; 

std::vector<int> scc;
std::stack<int> stck;

int dfs(int x)
{
    visited[x] = ++ind;
    stck.push(x);

    int parent = visited[x];

    for (int i = 0; i < line[x].size(); i++)
    {
        int y = line[x][i];

        if (visited[y] == 0)
        {
            parent = std::min(parent, dfs(y));
        }
        else if (!fin[y])
        {
            parent = std::min(parent, visited[y]);
        }
    }
    if (parent == visited[x])
    {
        while (1){
            int t = stck.top();
            stck.pop();
            scc[t] = sccInd;
            fin[t] = true;
            if (t == x)
                break;
        }
        sccInd++;
    }
    return parent;
}

int rev(int n)
{
    return n % 2 ? n - 1 : n + 1;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> E >> V;
    line = std::vector<std::vector<int> >(MAX, std::vector<int>());
    
    scc = std::vector<int>(MAX, 0);
    for (int i = 0; i < E; i++)
    {
        int at, bt, ac, bc;
        std::cin >> at >> ac >> bt >> bc;
        at = (ac==0) ? ((at - 1) * 2) : (at * 2 - 1);
        bt = (bc == 0) ? ((bt - 1) * 2) : (bt * 2 - 1);

        line[rev(at)].push_back(bt);
        line[rev(bt)].push_back(at);
    }

    for (int i = 0; i < 2 * V; i++){
        if (!visited[i])
            dfs(i);
    }
    for (int i = 0; i < V; i++){
        if (scc[i * 2] == scc[i * 2 + 1])
        {
            std::cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    line = std::vector<std::vector<int> >();
    std::vector<pi> order;
    for(int i = 0; i <2* V; i++){
        order.push_back(std::make_pair(scc[i],i));
    }
    std::sort(order.begin(),order.end(),std::greater<pi>());
    std::fill(scc.begin(),scc.end(),-1);
    for(pi p : order){
        int cur = p.second;
        if(scc[(cur)/2]==-1){
            scc[(cur)/2]=cur%2?0:1;
        }
    }
    for(int i = 0; i < V; i++){
        std::cout << scc[i] << '\n';
    }
}