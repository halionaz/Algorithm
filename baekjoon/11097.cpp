// 도시 계획
// 강한 연결 요소 & 플로이드-워셜

// 같은 scc끼리 묶은 후,
// 같은 scc 안에서 최소 간선을 선택하면 서로 다 이어짐

// 다른 scc 끼리는 플로이드 워셜을 통해 이어지는 최소 간선 선택
// 예를 들면 scc1 -> scc2, scc2->scc3, scc1->scc3
// 이 경우 마지막 간선은 필요 없음

// 플로이드 워셜을 마지막에 녹아내기가 겁나 까다로웠다..

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

int T, N, ind;
bool visited[301];
bool scc_line[301][301];
int scc[301];
std::vector<int> line[301];
std::vector<int> rev_line[301];
std::vector<int> scc_vec[301];
std::vector<std::vector<int> > ans;
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

    std::cin >> T;

    while(T--){

        //변수 초기화

        ind = 0;
        ans.clear();
        memset(scc_line, false, sizeof(scc_line));
        for(int i = 0; i < 301; i++){
            line[i].clear();
            rev_line[i].clear();
            scc_vec[i].clear();
        }

        std::cin >> N;

        for(int i = 1; i<= N; i++){
            std::string s;
            std::cin >> s;
            for(int j = 1; j <= N; j++){
                if(s[j-1] == '1' && i != j){
                    line[i].push_back(j);
                    rev_line[j].push_back(i);
                }
            }
        }

        memset(visited, false, sizeof(visited));

        for(int i = 1; i <= N; i++){
            if(!visited[i]){
                dfs(i);
            }
        }

        memset(visited, false, sizeof(visited));

        while(!stck.empty()){
            if(!visited[stck.top()]){
                rev_dfs(stck.top());
                ind++;
            }
            stck.pop();
        }

        for(int i = 0; i < ind; i++){
            for(int j = 0; j < scc_vec[i].size(); j++){

                // scc 간 간선 연결
                for(int l = 0; l < line[scc_vec[i][j]].size(); l++){
                    if(i != scc[line[scc_vec[i][j]][l]]){
                        scc_line[i][scc[line[scc_vec[i][j]][l]]] = true;
                    }
                }

                // 한 scc 내 간선 연결
                if(scc_vec[i].size() > 1){
                    if(j > 0){
                        std::vector<int> vec(2);
                        vec[0] = scc_vec[i][j-1];
                        vec[1] = scc_vec[i][j];
                        ans.push_back(vec);
                    }
                    if(j == scc_vec[i].size() - 1){
                        std::vector<int> vec(2);
                        vec[0] = scc_vec[i][j];
                        vec[1] = scc_vec[i][0];
                        ans.push_back(vec);
                    }
                }
            }
        }

        // 플로이드 워셜 통해서 필요없는 scc간 간선 제거
        for(int k = 0; k < ind; k++){
            for(int i = 0; i < ind; i++){
                for(int j = 0; j < ind; j++){
                    if(scc_line[i][j] && scc_line[i][k] && scc_line[k][j]){
                        // i->k와 k->j 가 있으면 i->j는 필요 없음
                        scc_line[i][j] = false;
                    }
                }
            }
        }

        // 남은 간선 답에 추가
        for(int i = 0; i < ind; i++){
            for(int j = 0; j < ind; j++){
                if(scc_line[i][j]){
                    std::vector<int> vec(2);
                    vec[0] = scc_vec[i][0];
                    vec[1] = scc_vec[j][0];
                    ans.push_back(vec);
                }
            }
        }

        std::cout << ans.size() << '\n';

        for(int i = 0; i < ans.size(); i++){
            std::cout << ans[i][0] << ' ' << ans[i][1] << '\n';
        }

    }

    return 0;
}