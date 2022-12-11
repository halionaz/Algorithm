// 리유나는 세일러복을 좋아해
// 이분 매칭

#include <iostream>
#include <vector>
#include <string.h>

int N, M;
double shirts[201];
double collor[201];
std::vector<int> line[201];
bool doneMatch[201];
int whichMatch[201];

bool dfs(int shirt){
    for(int i = 0; i < line[shirt].size(); i++){
        int C = line[shirt][i];
        if(!doneMatch[C]){
            doneMatch[C] = true;

            if(whichMatch[C] == 0 || dfs(whichMatch[C])){
                whichMatch[C] = shirt;
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
        std::cin >> shirts[i];
    }
    for(int i = 1; i <= M; i++){
        std::cin >> collor[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if((collor[j] >= shirts[i] * 0.5 && collor[j] <= shirts[i] * 0.75) || (collor[j] >= shirts[i] && collor[j] <= shirts[i] * 1.25)){
                line[i].push_back(j);
            }
        }
    }

    int ans = 0;

    for(int i = 1; i <= N; i++){
        memset(doneMatch, false, sizeof(doneMatch));
        if(dfs(i)){
            ans += 1;
        }
    }

    std::cout << ans << '\n';

    return 0;
}