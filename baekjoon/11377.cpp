// 열혈강호 3
// 이분 매칭

// 각 일을 직원과 매칭 시켜줘야 하는데,
// 직원 중 K명은 2개의 일을 맡을 수 있음

// 따라서 먼저 전체 직원에 대해 이분 매칭을 한번 시켜준 후,
// 다시 이분 매칭을 한번 더 돌려주어 K명에 대해 일을 할 수 있는 경우를 탐색

#include <iostream>
#include <vector>
#include <string.h>

int N, M, K;
std::vector<int> work[1001]; // 할 수 있는 일 저장
bool doneMatch[1001]; // 각 일의 매칭이 끝났는지를 저장
int whoWorks[1001]; // 각 일에 배정된 사람을 저장

bool dfs(int worker){
    // 직원이 할 수 있는 모든 일에 대해 매칭이 가능한지 도전
    for(int i = 0; i < work[worker].size(); i++){
        int W = work[worker][i];

        // 이미 현 직원의 탐색에서 차지가 완료되어버린 점은 pass
        if(!doneMatch[W]){

            doneMatch[W] = true;
            // 비어있거나, 그 일에 할당되어있는 직원을 옮길 수 있다면
            if(whoWorks[W] == 0 || dfs(whoWorks[W])){
                whoWorks[W] = worker;
                return true;
            }
        }
    }

    // 매칭 불가
    return false;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M >> K;

    int x, y;
    
    for(int i = 1; i <= N; i++){
        std::cin >> x;
        while(x--){
            std::cin >> y;
            work[i].push_back(y);
        }
    }

    int ans = 0;
    
    for(int i = 1; i <= N; i++){
        memset(doneMatch, false, sizeof(doneMatch));
        if(dfs(i)){
            ans += 1;
        }
    }
    
    // 2번 일하는 K명 탐색
    for(int i = 1; i <= N; i++){
        memset(doneMatch, false, sizeof(doneMatch));
        if(dfs(i)){
            ans += 1;
            K -= 1;
            if(K == 0){
                // K명이 다 찼으므로 탐색 종료
                break;
            }
        }
    }

    std::cout << ans << '\n';

    return 0;
}