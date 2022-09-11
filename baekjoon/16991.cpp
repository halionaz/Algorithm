// 외판원 순회 3
// 외판원 순회 문제 & 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍
// top-down

// [2098, 외판원 순회] 문제에서 자료형만 double로 변하고,
// 각 노드간 거리를 직접 구해야하는 문제

// 자릿수 표현때문에 계속 틀렸음... 앞으로 문제 조건 잘 확인하자

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>

const int inf = 987654321;

double line[16][16];
double dp[16][1<<16];
int N;
std::pair<int, int> position[16];

double dfs(int last, int visited){

    double &ret = dp[last][visited];

    if(visited == (1 << N) - 1){
        // 모든 노드 순회 완료
        if(line[last][0] == 0){
            // 시작점으로 돌아가는 길이 없으므로 불가능
            return inf;
        } else {
            // 다시 시작점으로 돌아가는 길이 있다면 계산 시작
            return line[last][0];
        }
    }

    if(ret != -1){
        // 이미 저장된 dp값이 있다면 반환
        return ret;
    }

    ret = inf;
    for(int i = 0; i < N; i++){
        if((visited&(1<<i)) == 0 && line[last][i] != 0){
            // 미방문 노드이고, 길이 존재할 경우 들러봄
            ret = std::min(ret, dfs(i, visited|(1<<i))+line[last][i]);
        }
    }

    return ret;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> position[i].first >> position[i].second;
    }

    // 거리 계산
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            line[i][j] = sqrt(pow(position[i].first-position[j].first,2)+pow(position[i].second-position[j].second,2));
        }
    }

    // DP 값 초기화
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < (1<<16); j++){
            dp[i][j] = -1;
        }
    }

    printf("%.8f\n", dfs(0, 1));

    return 0;
}