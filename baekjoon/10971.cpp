// 외판원 순회 2
// 외판원 순회 문제 & 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍

// 사실 도시 개수가 그렇게 많지 않아 비트마스킹을 굳이 사용할 필요는 없으나
// 연습을 위해 이렇게 풀이

#include <iostream>
#include <string.h>
#include <algorithm>

const int inf = 987654321;

int N;
int line[10][10];
int dp[10][1<<10];

int dfs(int last, int visited){
    if(visited == (1 << N) - 1){
        // 모든 노드 순회 완료
        if(line[last][0] != 0){
            // 다시 시작점으로 돌아가는 길이 있다면 계산 시작
            return line[last][0];
        } else {
            // 길이 없으므로 불가능
            return inf;
        }
    }

    if(dp[last][visited] < inf){
        // 이미 저장된 dp값이 있다면 반환
        return dp[last][visited];
    }

    dp[last][visited] = inf;
    for(int i = 1; i < N; i++){
        if((visited&(1<<i)) == 0 && line[last][i] != 0){
            // 미방문 노드인 경우 들러봄
            dp[last][visited] = std::min(dp[last][visited], dfs(i, visited|(1<<i))+line[last][i]);
        }
    }

    // 길이 없다면, 길이 없다는 것을 표시
    // 굳이 표시하지 않는다 해도 논리 자체에는 문제 없으나
    // 이후 같은 상황에 도달한 경우, 미탐색과 구별이 되지 않아 시간낭비됨
    if(dp[last][visited] == inf){
        dp[last][visited] = inf-1;
    }

    return dp[last][visited];
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::fill(&dp[0][0], &dp[9][(1<<10)-1], inf);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> line[i][j];
        }
    }

    std::cout << dfs(0,1) << '\n';

    return 0;
}