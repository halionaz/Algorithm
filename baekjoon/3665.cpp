// 최종 순위
// 위상 정렬

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
int N;
int inpNum[501];
int order[501];
int line[501][501];
int main(){
    int T,M;
    std::cin>>T;
    while(T--){
        memset(inpNum,0,sizeof(inpNum));
        memset(line,0,sizeof(line));
        std::cin >> N;
        for(int i = 1; i < N+1; i++){
            std::cin >> order[i];
        }
        for(int i = 1; i < N+1; i++){
            for(int j = i+1; j < N+1; j++){
                line[order[i]][order[j]] = 1;
                inpNum[order[j]]++;
            }
        }
        std::cin >> M;
        for(int j = 0; j < M; j++){
            int a,b;
            std::cin >> a >> b;
            if(line[a][b]){
                line[a][b] = 0;
                line[b][a] = 1;
                inpNum[a]++;
                inpNum[b]--;
            } else {
                line[a][b] = 1;
                line[b][a] = 0;
                inpNum[a]--;
                inpNum[b]++;
            }
        }
        std::queue<int> q;
        std::vector<int> ans;
        for(int i = 1; i <= N; i++){
            if(!inpNum[i]){
                q.push(i);
            }
        }
        int manyAns = 0;
        while(!q.empty()){
            if(q.size() > 1){
                // 큐에 들어있는 개수가 1보다 크다는 것은
                // 동시에 inpDegree가 0인 애들이 많다는 것이고
                // 이들 간의 순서를 결정할 수 없으므로
                // 확실한 순위를 찾을 수 없다는 것
                manyAns = 1;
                break;
            }
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(int j = 1; j < N+1; j++){
                if(line[temp][j]){
                    if(--inpNum[j] == 0){
                        q.push(j);
                    }
                }
            }
        }
        if(ans.size() != N){
            // inp degree가 0이 아니고 아직 남아서
            // 탐색을 거치지 못한 노드가 남아 있으므로
            // 위상 정렬 불가
            std::cout << "IMPOSSIBLE" << '\n';
        } else {
            if(manyAns){
                std::cout << "?" << '\n';
            } else {
                for(int i = 0; i < N; i++){
                    std::cout << ans[i] << ' ';
                }
                std::cout << '\n';
            }
        }
    }
    return 0;
}