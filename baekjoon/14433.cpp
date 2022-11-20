// 한조 대기 중
// 이분 매칭

// 이분 매칭 기본 문제

#include <iostream>
#include <vector>
#include <string.h>

int N, M, K1, K2;
int a, b;
std::vector<int> trollPick1[301];
std::vector<int> trollPick2[301];
bool doneMatch[1001]; // 각 영웅의 매칭이 끝났는지를 저장
int whoPicks[1001]; // 각 영웅에 배정된 사람을 저장

bool dfs1(int player){
    // 팀 1번 용 dfs 함수
    // 이 플레이어가 선택할 수 있는 트롤픽을 모두 돌면서 트롤픽 배정이 가능한지 체크
    for(int i = 0; i < trollPick1[player].size(); i++){

        int pick = trollPick1[player][i];

        // 이 픽이 이미 이번 플레이어의 탐색에서 한번 거쳐간 픽이라면 탐색 X
        if(!doneMatch[pick]){
            doneMatch[pick] = true;
            if(whoPicks[pick] == 0 || dfs1(whoPicks[pick])){
                whoPicks[pick] = player;
                return true;
            }
        }
    }

    return false;
}
bool dfs2(int player){
    // 팀 2번 용 dfs 함수
    // 이 플레이어가 선택할 수 있는 트롤픽을 모두 돌면서 트롤픽 배정이 가능한지 체크
    for(int i = 0; i < trollPick2[player].size(); i++){

        int pick = trollPick2[player][i];

        // 이 픽이 이미 이번 플레이어의 탐색에서 한번 거쳐간 픽이라면 탐색 X
        if(!doneMatch[pick]){
            doneMatch[pick] = true;
            if(whoPicks[pick] == 0 || dfs2(whoPicks[pick])){
                whoPicks[pick] = player;
                return true;
            }
        }
    }

    return false;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M >> K1 >> K2;

    for(int i = 0; i < K1; i++){
        std::cin >> a >> b;
        trollPick1[a].push_back(b);
    }
    for(int i = 0; i < K2; i++){
        std::cin >> a >> b;
        trollPick2[a].push_back(b);
    }

    int pickCnt1 = 0, pickCnt2 = 0;

    for(int i = 1; i <= N; i++){
        memset(doneMatch, false, sizeof(doneMatch));

        if(dfs1(i)){
            // i번 팀원이 트롤픽 가능하다면
            pickCnt1 += 1;
        }
    }

    memset(whoPicks, 0, sizeof(whoPicks));

    for(int i = 1; i <= N; i++){
        memset(doneMatch, false, sizeof(doneMatch));
        if(dfs2(i)){
            pickCnt2 += 1;
        }
    }

    std::cout << (pickCnt1 < pickCnt2 ? "네 다음 힐딱이" : "그만 알아보자") << '\n';

    return 0;
}