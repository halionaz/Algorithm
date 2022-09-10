// Strongly Connected Component
// 강한 연결 요소
// 코사라주 알고리즘

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

const int maxNode = 10001;

int V, E, ind = 0;
std::vector<int> line[maxNode];
std::vector<int> reverseLine[maxNode];
std::vector<std::vector<int>> ans;
bool visited[maxNode];
std::stack<int> stck;

void dfs(int cur) {
  visited[cur] = true;
  for (int i = 0; i < line[cur].size(); i++) {
    if (!visited[line[cur][i]]) {
      dfs(line[cur][i]);
    }
  }
  stck.push(cur);
  return;
}

void reverseDfs(int cur) {
  visited[cur] = true;
  ans[ind].push_back(cur);
  for (int i = 0; i < reverseLine[cur].size(); i++) {
    if (!visited[reverseLine[cur][i]]) {
      reverseDfs(reverseLine[cur][i]);
    }
  }
}

int main() {

  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  memset(visited, false, sizeof(visited));

  std::cin >> V >> E;

  for (int i = 0; i < E; i++) {
    int a, b;
    std::cin >> a >> b;
    line[a].push_back(b);
    reverseLine[b].push_back(a);
  }

  // 순방향 DFS 실행
  for (int i = 1; i <= V; i++) {
    if (!visited[i]) {
      dfs(i);
    }
  }

  int K = 0;
  memset(visited, false, sizeof(visited));

  // 역방향 DFS 실행

  while (!stck.empty()) {
    if (!visited[stck.top()]) {
      K++;
      ans.push_back(std::vector<int>());
      reverseDfs(stck.top());
      ind++;
    }
    stck.pop();
  }

  for (int i = 0; i < K; i++) {
    std::sort(ans[i].begin(), ans[i].end());
  }

  std::sort(ans.begin(), ans.end());

  std::cout << K << '\n';
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      std::cout << ans[i][j] << ' ';
    }
    std::cout << -1 << '\n';
  }
  return 0;
}