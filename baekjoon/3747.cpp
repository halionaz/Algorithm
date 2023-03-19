// 완벽한 선거!
// 2-sat & 강한 연결 요소
// inf_input & 타잔 알고리즘

// 타잔 알고리즘을 써보는 첫 문제

#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

const int max = 1001*2;
int n, m, cnt, scc[max], chk[max];
std::vector<int> line[max];
std::vector<std::vector<int> > res;
std::stack<int> stk;

int getSCC(int now) {

  chk[now] = ++cnt;
  int ret = chk[now];
  stk.push(now);

    for (int nxt : line[now]) {
        if(!chk[nxt]){
            // 아직 방문도 하지 않은 정점이면
            // scc 재귀 실행
            ret = std::min(ret, getSCC(nxt));
        } else if (!scc[nxt]){
            // 방문은 했지만, scc에 포함되지 않은 정점이면
            // 스택에 있는 정점을 ret이 나올 때 까지 차례로 빼며
            // scc로 묶어줌
            ret = std::min(ret, chk[nxt]);
        }
    } 

    if (ret == chk[now]){
        res.push_back(std::vector<int>());

        while (1) {
            int top = stk.top();
            stk.pop();
            // top이 포함된 scc 넘버링
            scc[top] = res.size();
            // scc 리스트에 top 넣어주기
            res[res.size() - 1].push_back(top);
            if (top == now){
                break;
            }
        }
    }
    return ret;
}

int f(int u) {
    // ~u를 반환하는 함수
    return u > n ? u-n : u+n;
}

int main() {

    while (~scanf("%d %d", &n, &m)) {

        // 초기화
        for (int i = 0; i < max; i++) {
            chk[i] = scc[i] = 0;
            line[i].clear();
        }
        cnt = 0;
        while (!stk.empty()) stk.pop();
        res.clear();

        // 입력 받기
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (u < 0) u = -u + n;
            if (v < 0) v = -v + n;
            // ~u면 v라도 만족해야 됨
            line[f(u)].push_back(v);
            // ~v면 u라도 만족해야 됨
            line[f(v)].push_back(u);
        }

        for (int i = 1; i <= 2*n; i++) {
            if (!chk[i]){
                getSCC(i);
            }
        }

        int flag = 0;

        for (int i = 1; i <= n; i++) {
            if (scc[i] == scc[i+n]){
                // 모순되는 경우가 생긴다면
                flag = 1;
                break;
            }
        }
        puts(flag ? "0" : "1");
    }

    return 0;
}