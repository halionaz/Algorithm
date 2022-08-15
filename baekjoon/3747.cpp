// 완벽한 선거!
// 2-sat & 강한 연결 요소

// inf_input

// 내 알고리즘

// #include <iostream>
// #include <vector>
// #include <stack>
// #include <cstring>

// const int max = 1001;

// int N, M, ind;
// int scc[max*2];
// bool visited[max*2];
// std::vector<int> line[max*2];
// std::vector<int> reversed_line[max*2];
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

// void reverse_dfs(int cur){
//     visited[cur] = true;
//     scc[cur] = ind;
//     for(int i = 0; i < reversed_line[cur].size(); i++){
//         if(!visited[reversed_line[cur][i]]){
//             reverse_dfs(reversed_line[cur][i]);
//         }
//     }
// }

// int main(){

//     std::ios_base::sync_with_stdio(0);
//     std::cin.tie(0);
//     while(!std::cin.eof()){

//         ind = -1;
//         std::cin >> N >> M;

//         while(M--){
//             int i, j;
//             std::cin >> i >> j;
//             i = i < 0 ? (-i)*2 : i*2-1;
//             j = j < 0 ? (-j)*2 : j*2-1;
//             line[i%2?i+1:i-1].push_back(j);
//             reversed_line[j].push_back(i%2?i+1:i-1);
//             line[j%2?j+1:j-1].push_back(i);
//             reversed_line[i].push_back(j%2?j+1:j-1);
//         }

//         memset(visited, false, sizeof(visited));

//         for(int i = 1; i <= N; i++){
//             if(!visited[i*2-1]){
//                 dfs(i*2-1);
//             }
//             if(!visited[i*2]){
//                 dfs(i*2);
//             }
//         }

//         memset(visited, false, sizeof(visited));

//         while(!stck.empty()){
//             if(!visited[stck.top()]){
//                 ind++;
//                 reverse_dfs(stck.top());
//             }
//             stck.pop();
//         }

//         int ans = 1;

//         for(int i = 1; i <= N; i++){
//             if(scc[i*2-1] == scc[i*2]){
//                 ans = 0;
//                 break;
//             }
//         }

//         for(int i = 0; i <= N*2; i++){
//             line[i].clear();
//             reversed_line[i].clear();
//         }

//         std::cout << ans << '\n';

//     }

//     return 0;

// }


// 맞은 제출 


#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

const int max = 1001*2;
int n, m, cnt, scc[max], chk[max], ans[max];
std::vector<int> gph[max];
std::vector<std::vector<int> > res;
std::stack<int> stk;

int getSCC(int now) {
   chk[now] = ++cnt;
   int ret = chk[now];
   stk.push(now);
   for (int nxt : gph[now]) {
       if (!chk[nxt]) ret = std::min(ret, getSCC(nxt));
       else if (!scc[nxt]) ret = std::min(ret, chk[nxt]);
   }
   if (ret != chk[now]) return ret;
   res.push_back(std::vector<int>());
   while (1) {
       int top = stk.top();
       stk.pop();
       scc[top] = res.size();
       res[res.size() - 1].push_back(top);
       ans[top] = res.size();
       if (top == now) break;
   }
   return ret;
}

int f(int u) {
    return u>n ? u-n : u+n;
}

int main() {
    while (~scanf("%d %d", &n, &m)) {
        for (int i = 0; i < max; i++) {
            chk[i] = scc[i] = ans[i] = 0;
            gph[i].clear();
        }
        cnt = 0;
        while (!stk.empty()) stk.pop();
        res.clear();

        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (u < 0) u = -u + n;
            if (v < 0) v = -v + n;
            gph[f(u)].push_back(v);
            gph[f(v)].push_back(u);
        }

        for (int i = 1; i <= 2*n; i++) {
            if (!chk[i]) getSCC(i);
        }

        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (ans[i] == ans[i+n]) flag = 1;
        }
        puts(flag ? "0" : "1");
    }

    return 0;
}