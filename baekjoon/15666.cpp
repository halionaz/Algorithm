// N과 M (12)
// 백트래킹

#include <iostream>
#include <algorithm>

int N, M;
int arr[9];
int ans[9];

void dfs(int last, int depth){
    if(depth == M){
        // 길이가 M이 되었으므로, 답 조건 충족
        // 출력
        for(int i = 0; i < M; i++){
            std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
    } else {
        // 중복되는 수열이 생기면 안되므로, 같은 수열이 생성되는 것을 방지
        int lastLastChar = 0;
        for(int i = last; i < N; i++){
            if(lastLastChar != arr[i]){
                lastLastChar = arr[i];
                ans[depth] = arr[i];
                dfs(i, depth + 1);
            }
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

    dfs(0, 0);     

    return 0;
}