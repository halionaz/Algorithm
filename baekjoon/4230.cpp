// 사랑과 전쟁
// 강한 연결 요소 & 2-sat
// 코사라주 알고리즘

// 문제 상황이 미친 문제
// "평소 어둠의 커뮤니티 고동넷의 회원이던 철승이는 이 파티에 자주 보던 얼굴들이 있는 것을 발견했고, 
// 한 사람의 귀띔으로 이 부부들 사이에는 수 많은 불륜 관계가 있다는 것을 알게 되었다"
// "각 부부는 서로 이성이지만, 불륜 관계는 동성간에도 일어날 수 있음에 주의하라"

#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

const int max_num = 32;

int N, M, ind;
int scc[max_num*2];
int sccBool[max_num*2];
bool visited[max_num*2];
// a번째 부부 :: aw = 2*(a+1)-1, ah = 2*(a+1)
std::vector<int> line[max_num*2];
std::vector<int> rev_line[max_num*2];
std::vector<int> sccArr[max_num*2];
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
    sccArr[ind].push_back(cur);
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

        // init
        ind = -1;
        for(int i = 0; i < max_num*2; i++){
            line[i].clear();
            rev_line[i].clear();
            sccArr[i].clear();
        }

        std::cin >> N >> M;

        if(!N && !M){
            break;
        }

        // 보람이는 무조건 1, 즉 철승이는 무조건 0
        // 앞으로 모든 불륜 관계인 사람 두명 다 1이거나, 한명만 0이어야 함
        // 즉, 불륜 관계인 두 사람 모두가 0일 수는 없음

        // 보람이가 1이어야 하므로 보람∨보람 도 관계식에 추가
        line[2].push_back(1);
        rev_line[1].push_back(2);

        for(int i = 0; i < M; i++){
            int aN, bN;
            char aC, bC;
            std::cin >> aN >> aC;
            std::cin >> bN >> bC;
            aN++; bN++;
            aN = aC == 'w' ? aN*2-1 : aN*2;
            bN = bC == 'w' ? bN*2-1 : bN*2;
            line[aN%2?aN+1:aN-1].push_back(bN); // aN이 0이면 bN은 1
            rev_line[bN].push_back(aN%2?aN+1:aN-1);
            line[bN%2?bN+1:bN-1].push_back(aN); // bN이 0이면 aN은 1
            rev_line[aN].push_back(bN%2?bN+1:bN-1);
        }

        memset(visited, false, sizeof(visited));

        for(int i = 1; i <= N; i++){
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

        bool canAns = true;

        for(int i = 1; i <= N; i++){
            if(scc[i*2-1] == scc[i*2]){
                // 부부가 같은 scc에 포함됨
                canAns = false;
                break;
            }
        }

        if(!canAns){
            std::cout << "bad luck\n";
        } else {
            memset(sccBool, -1, sizeof(sccBool));
            for(int i = 0; i <= ind; i++){
                if(sccBool[i] == -1){
                    sccBool[i] = 0;
                    for(int j = 0; j < sccArr[i].size(); j++){
                        int node = sccArr[i][j]%2?sccArr[i][j]+1:sccArr[i][j]-1;
                        if(sccBool[scc[node]] == -1){
                            sccBool[scc[node]] = sccBool[i] ? 0 : 1;
                        }
                    }
                }
            }

            for(int i = 2; i <= N; i++){
                if(sccBool[scc[i*2-1]]){
                    std::cout << i-1 << "w ";
                } else {
                    std::cout << i-1 << "h ";
                }
            }
            std::cout << '\n';
        }

    }

    return 0;
}