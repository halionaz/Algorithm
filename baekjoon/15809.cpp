// 전국시대
// 분리 집합

#include <iostream>
#include <vector>
#include <algorithm>

int N, M, O, P, Q;
int parents[100001];
int army[100001];

int find(int x){
    // 조상을 찾는 함수

    if(x == parents[x]){
        return x;
    } else {
        parents[x] = find(parents[x]);
        return parents[x];
    }
}

void unite(int a, int b, int c){
    // c가 1이면 동맹, 2이면 전쟁
    int x = find(a);
    int y = find(b);

    if(x != y){
        if(c == 2 && army[x] == army[y]){
            army[x] = army[y] = 0;
        } else if(army[x] > army[y]){
            // 더 군사력이 큰 조상 기준으로 설정
            parents[y] = x;
            if(c == 1){
                // 동맹
                army[x] += army[y];
            } else {
                army[x] -= army[y];
            }
        } else {
            parents[x] = y;
            if(c == 1){
                // 동맹
                army[y] += army[x];
            } else {
                army[y] -= army[x];
            }
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;


    for(int i = 1; i <= N; i++){
        std::cin >> army[i];
        parents[i] = i;
    }

    for(int i = 0; i < M; i++){
        std::cin >> O >> P >> Q;
        unite(P,Q,O);
    }

    std::vector<int> ans;

    for(int i = 1; i <= N; i++){
        if(parents[i] == i && army[i] > 0){
            ans.push_back(army[i]);
        }
    }

    std::sort(ans.begin(), ans.end());
    std::cout << ans.size() << '\n';

    for(int i = 0; i < ans.size(); i++){
        std::cout << ans[i] << ' ';
    }

    std::cout << '\n';

    return 0;
}