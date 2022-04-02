// 성격 진단 테스트
// 강한 연결 요소

// 그다지 어렵지 않았던 scc 문제
// 우선순위를 그래프로 나타냈을 때, scc가 등장하면 모순임
// 즉 같은 scc를 하나의 그룹으로 출력해주면 되고
// 알파벳 순서로 정렬만 하면 됨

#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

int N, ind;
bool isInCase[26], visited[26];
std::vector<int> line[26];
std::vector<int> rev_line[26];
std::vector<std::vector<int> > scc_vec;

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
    scc_vec[ind].push_back(cur);
    for(int i = 0; i < rev_line[cur].size(); i++){
        if(!visited[rev_line[cur][i]]){
            rev_dfs(rev_line[cur][i]);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(true){

        // 변수 초기화
        ind = 0;
        memset(isInCase, false, sizeof(isInCase));
        for(int i = 0; i < 26; i++){
            line[i].clear();
            rev_line[i].clear();
        }
        scc_vec.clear();

        std::cin >> N;

        if(!N){
            break;
        }

        for(int i = 0; i < N; i++){
            int inp[5];
            for(int j = 0; j < 5; j++){
                char c;
                std::cin >> c;
                inp[j] = c - 'A';
                isInCase[inp[j]] = true;
            }
            char base;
            std::cin >> base;
            int b = base - 'A';
            for(int j = 0; j < 5; j++){
                if(b != inp[j]){
                    line[inp[j]].push_back(b);
                    rev_line[b].push_back(inp[j]);
                }
            }
        }

        // for(int i = 0; i < 26; i++){
        //     std::cout << i << " : ";
        //     for(int j = 0; j < line[i].size(); j++){
        //         std::cout << line[i][j] << ' ';
        //     }
        //     std::cout << '\n';
        // }

        memset(visited, false, sizeof(visited));

        for(int i = 0; i < 26; i++){
            if(isInCase[i] && !visited[i]){
                dfs(i);
            }
        }

        memset(visited, false, sizeof(visited));

        while(!stck.empty()){
            if(!visited[stck.top()]){
                scc_vec.push_back(std::vector<int>());
                rev_dfs(stck.top());
                std::sort(scc_vec[ind].begin(), scc_vec[ind].end());
                ind++;
            }
            stck.pop();
        }

        std::sort(scc_vec.begin(), scc_vec.end());

        for(int i = 0; i < scc_vec.size(); i++){
            for(int j = 0; j < scc_vec[i].size(); j++){
                std::cout << char(scc_vec[i][j] + 'A') << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';

    }

    return 0;
}