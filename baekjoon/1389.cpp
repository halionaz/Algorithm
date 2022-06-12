// 케빈 베이컨의 6단계 법칙
// 플로이드-워셜

#include <iostream>
#include <cstring>

int N, M;
int grid[101][101];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j){
                grid[i][j] = 0;
            } else {
                grid[i][j] = 1000;
            }
        }
    }

    while(M--){
        int a, b;
        std::cin >> a >> b;
        grid[a][b] = grid[b][a] = 1;
    }

    for(int k = 1; k <= N; k++){
        // k 경유
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(grid[i][k] + grid[k][j] < grid[i][j]){
                    grid[i][j] = grid[i][k]+grid[k][j];
                }
            }
        }
    }
    int ansInd = 0;
    int kevin = 99999999;
    for(int i = 1; i <= N; i++){
        int sum = 0;
        for(int j = 1; j <= N; j++){
            sum += grid[i][j];
        }
        if(sum < kevin){
            ansInd = i;
            kevin = sum;
        }
    }

    std::cout << ansInd << '\n';

    return 0;
}