// 궁금한 민호
// 플로이드-워셜

#include <iostream>
#include <cstring>

int N, ans;
int line[21][21];
bool road[21][21];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    memset(road, 1, sizeof(road));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> line[i][j];
        }
    }

    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(i != j && i != k && j != k){
                    if(line[i][j] == line[i][k] + line[k][j]){
                        // i-j간 도로는 없어도 된다~
                        road[i][j] = false;
                    } else if(line[i][j] > line[i][k] + line[k][j]) {   
                        // 논리적으로 말이 안됨
                        std::cout << -1 << '\n';
                        return 0;
                    }
                }
            }
        }
    }

    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            if(road[i][j]){
                ans += line[i][j];
            }
        }
    }

    std::cout << ans << '\n';

    return 0;
}