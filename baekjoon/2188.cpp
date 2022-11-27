// 축사 배정
// 이분 매칭

#include <iostream>
#include <vector>
#include <string.h>

int N, M, S, want;
std::vector<int> preference[201];
bool doneMatch[201];
int whoOccupy[201];

bool dfs(int cow){
    // 소가 들어갈 수 있는 축사에 대해 들어갈 수 있는지 판별
    for(int i = 0; i < preference[cow].size(); i++){
        int barn = preference[cow][i];

        // 이미 차지된 축사는 pass
        if(!doneMatch[barn]){
            doneMatch[barn] = true;
            if(whoOccupy[barn] == 0 || dfs(whoOccupy[barn])){
                whoOccupy[barn] = cow;
                return true;
            }
        }
    }

    return false;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 1; i <= N; i++){
        std::cin >> S;
        while(S--){
            std::cin >> want;
            preference[i].push_back(want);
        }
    }

    int ans = 0;

    for(int i = 1; i <= N; i++){
        memset(doneMatch, false, sizeof(doneMatch));
        if(dfs(i)){
            ans++;
        }
    }

    std::cout << ans << '\n';

    return 0;
}