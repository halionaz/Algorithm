// N과 M (9)
// 백트래킹

// 중복되는 수열을 여러번 출력하면 안되며,
// 중복하는 수열은 M-1번째 수가 같을때, 
// M번째 수가 그 전 출력 수열과 같으면 중복되는 수열이므로
// (오름차순으로 정렬했으므로 무조건 전 수열과 비교만 하면 됨)
// 그 전 수열의 마지막 수를 저장하는 구현을 통해 문제 해결

#include <iostream>
#include <algorithm>

int N, M;
int ans[8], arr[8];
bool visited[8];

void dfs(int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++){
            std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
        return;
    }

    int last = -1;

    for(int i = 0; i < N; i++){
        if(!visited[i] && arr[i] != last){
            visited[i] = true;
            last = ans[cnt] = arr[i];
            dfs(cnt + 1);
            visited[i] = false;
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