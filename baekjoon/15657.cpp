// N과 M (8)
// 백트래킹

// 쉬운 백트래킹 문제,
// 전체 수열을 사전 순으로 증가하도록 출력해야 하므로
// 첫 배열을 정렬한 후 DFS를 진행하면 자연히 사전순으로 탐색됨

#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
int arr[8];
std::vector<int> ans;

void dfs(int depth){
    if(depth == M){
        for(int i = 0; i < M; i++){
            std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++){
        if(depth == 0 || arr[i] >= ans.back()){
            ans.push_back(arr[i]);
            dfs(depth+1);
            ans.pop_back();
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    std::sort(arr, arr+N);

    dfs(0);

    return 0;
}