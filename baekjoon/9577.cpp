// 토렌트
// 이분 매칭

#include <iostream>
#include <vector>
#include <string.h>

int T;
int N, M;
bool line[101][101]; // line[i][j] :: i 시간대에 j 조각을 받을 수 있는지
bool doneMatch[101];
int whenMatch[101];

bool dfs(int curTime){
    for(int i = 1; i <= 100; i++){
        if(line[curTime][i]){
            // i조각 수신 가능
            if(!doneMatch[i]){
                doneMatch[i] = true;
                
                if(whenMatch[i] == -1 || dfs(whenMatch[i])){
                    whenMatch[i] = curTime;
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 101; j++){
                line[i][j] = false;
            }
            memset(whenMatch, -1, sizeof(whenMatch));
        }

        std::cin >> N >> M;

        for(int i = 0; i < M; i++){
            int t1, t2, a, q;
            std::cin >> t1 >> t2 >> a;
            for(int j = 0; j < a; j++){
                std::cin >> q;

                for(int k = t1; k < t2; k++){
                    // k초 시간대에 q 조각을 받을 수 있음
                    line[k][q] = true;
                }
            }
        }

        int cnt = 0;
        bool isDone = false;

        for(int i = 0; i < 101; i++){
            memset(doneMatch, false, sizeof(doneMatch));

            if(dfs(i)){
                cnt += 1;
            }

            if(cnt == N){
                // 조각이 다 모였으면
                isDone = true;
                std::cout << i + 1 << '\n';
                break;
            }
        }

        if(!isDone){
            std::cout << -1 << '\n';
        }

    }

    return 0;
}