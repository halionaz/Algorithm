// 열혈강호
// 이분 매칭

// 이분 매칭을 사용해보는 첫 문제
// 간선의 용량이 1인 네트워크 플로우 문제이지만,
// DFS를 통해 어렵지 않게 풀 수 있음.

// 1번 직원이 할 수 있는 일을 먼저 선택해본 후, (1번 일을 할 수 있다고 가정)
// 2번 직원이 할 수 있는 일이 1번이면, 직원 2를 일 1에 할당하고, 직원 1을 할 수 있는 다른 일에 배정
// 만약 직원 1이 할 수 있는 다른 일이 없다면, 직원 2는 매칭 불가

// 이를 반복하다보면 최대 매칭수가 도출됨

#include <iostream>
#include <vector>
#include <string.h>

int N, M, n, m;
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

    std::cin >> N >> M;

    for(int i = 1; i <= N; i++){
        
        std::cin >> m; // 할 수 있는 일의 개수

        for(int j = 0; j < m; j++){
            std::cin >> n;
            work[i].push_back(n);
        }
    }

    int ans = 0; // 최대 매칭수

    for(int i = 1; i <= N; i++){

        memset(doneMatch, false, sizeof(doneMatch));

        if(dfs(i)){
            // i번 직원이 일을 할 수 있다면?
            ans += 1;
        }
    }

    std::cout << ans << '\n';

    return 0;
}