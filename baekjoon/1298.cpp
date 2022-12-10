// 노트북의 주인을 찾아서
// 이분 매칭

#include <iostream>
#include <vector>
#include <string.h>

int N, M, a, b;
std::vector<int> line[101];
bool doneMatch[5001];
int whosePC[5001];

bool dfs(int person){
    for(int i = 0; i < line[person].size(); i++){
        int laptop = line[person][i];
        
        if(!doneMatch[laptop]){
            doneMatch[laptop] = true;
            if(whosePC[laptop] == 0 || dfs(whosePC[laptop])){
                whosePC[laptop] = person;
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

    for(int i = 0; i < M; i++){
        std::cin >> a >> b;
        line[a].push_back(b);
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