// 하우스 M.D.
// 강한 연결 요소 & 2-sat
// 코사라주 알고리즘

// 모든 환자가 죽게 되는지에 대해 검사하는 것이므로
// (a and b) or (c and d) or .... 를 판별하면 되며,
// 이를 드모르간 법칙으로 
// (-a or -b) and (-c or -d) and ... 을 판별한 후 뒤집으면 된다

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

const int max_symptom = 20001;

int N, M, ind;
int scc[max_symptom*2];
bool visited[max_symptom*2];
std::vector<int> line[max_symptom*2];
std::vector<int> reversed_line[max_symptom*2];
std::stack<int> stck;

void dfs(int cur){
    visited[cur] = true;
    for(int i = 0; i < line[cur].size(); i++){
        if(!visited[line[cur][i]]){
            dfs(line[cur][i]);
        }
    }
    stck.push(cur);
}

void rev_dfs(int cur){
    visited[cur] = true;
    scc[cur] = ind;
    for(int i = 0; i < reversed_line[cur].size(); i++){
        if(!visited[reversed_line[cur][i]]){
            rev_dfs(reversed_line[cur][i]);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(true){

        ind = -1;

        for(int i = 0; i < max_symptom*2; i++){
            line[i].clear();
            reversed_line[i].clear();
        }

        std::cin >> N >> M;

        if(!N && !M){
            break;
        }

        for(int i = 0; i < N; i++){
            int a, b;
            std::cin >> a >> b;
            // 증세가 일어나지 않으면 짝수, 일어나는 것은 홀수
            a = a < 0 ? (-a)*2 : a*2-1;
            b = b < 0 ? (-b)*2 : b*2-1;
            // a와 b 두 상태가 모두 만족되면 환자는 죽음 (a and b)
            // 즉, a가 아니거나, b가 아니면 환자는 살게 됨 (-a or -b)

            // a이면 b가 아니어야 죽지 않음
            line[a].push_back(b%2?b+1:b-1);
            reversed_line[b%2?b+1:b-1].push_back(a);
            // b이면 a가 아니어야 죽지 않음
            line[b].push_back(a%2?a+1:a-1);
            reversed_line[a%2?a+1:a-1].push_back(b);
        }

        memset(visited,false,sizeof(visited));

        for(int i = 1; i <= M; i++){
            if(!visited[i*2-1]){
                dfs(i*2-1);
            }
            if(!visited[i*2]){
                dfs(i*2);
            }
        }

        memset(visited, false, sizeof(visited));

        while(!stck.empty()){
            if(!visited[stck.top()]){
                ind++;
                rev_dfs(stck.top());
            }
            stck.pop();
        }

        int ans = 1;

        for(int i = 1; i <= M; i++){
            if(scc[i*2-1] == scc[i*2]){
                // 만약 증상이 일어나는 것과 일어나지 않는 것이 중첩된다면
                // 살아남는 것이 불가능한 것
                ans = 0;
                break;
            }
        }

        std::cout << ans << '\n';

    }

    return 0;
}