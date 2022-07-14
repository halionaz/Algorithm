// Strahler 순서
// 위상 정렬

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int T, K, M, P;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        std::cin >> K >> M >> P;

        int inpNum[1001];
        std::pair<int, int> ord[1001];
        std::vector<int> line[1001];

        for(int i = 0; i < 1001; i++){
            ord[i] = std::make_pair(0, 0);
        }

        for(int i = 0; i < P; i++){
            int s, e;
            std::cin >> s >> e;
            line[s].push_back(e);
            inpNum[e]++;
        }

        std::queue<int> que;

        for(int i = 1; i <= M; i++){
            if(inpNum[i] == 0){
                ord[i].first = 1;
                que.push(i);
            }
        }

        while(!que.empty()){
            int cur = que.front();
            que.pop();

            for(int i = 0; i < line[cur].size(); i++){
                if(ord[line[cur][i]].first == 0 || ord[line[cur][i]].first < ord[cur].first){
                    ord[line[cur][i]].first = ord[cur].first;
                    ord[line[cur][i]].second = 1;
                } else if(ord[line[cur][i]].first == ord[cur].first){
                    ord[line[cur][i]].second++;
                }

                if((--inpNum[line[cur][i]]) == 0){
                    if(ord[line[cur][i]].second >= 2){
                        ord[line[cur][i]].first++;
                        ord[line[cur][i]].second = 1;
                    }
                    que.push(line[cur][i]);
                }
            }
        }

        std::cout << K << " " << ord[M].first << '\n';

    }

    return 0;
}