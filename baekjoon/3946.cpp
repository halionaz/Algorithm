// 랜덤 걷기
// 다이나믹 프로그래밍
// top-down

// 가장 오른쪽 위치의 기댓값을 구해야 한다는데
// 워딩이 익숙하지 않아 헷갈릴 수 있음

// 동전을 던져서 랜덤 걷기를 했을 때, 최대로 오른쪽으로 갈 수 있는 위치가 나오게 될 것이고,
// 이 위치 좌표의 기댓값을 말하는 것

// 예시를 들자면
// 각 면의 확률이 0.5인 동전을 4번 던지는 경우
// 2^4 = 16 가지 경우의 수가 나오고

// L L L L 은 처음 위치가 가장 오른쪽에 있었으므로 => 0
// L L R R 은 처음과 마지막이 가장 오른쪽이므로 => 0
// R L L L  => 1
// R R L L  => 2
// ...

// dp[i][j] :: i번의 횟수가 남았고, 현재 위치가 j일때 가장 오른쪽 위치의 기댓값
// dp[i][j] = L*(dp[i-1][j+1] - 1) + R*(dp[i-1][max(j-1,0)] + 1) + (1-L-R)*(dp[i-1][j]))

#include <iostream>
#include <algorithm>

int P, N;
double L, R;
double dp[1001][1001];

double solve(int rest, int j){
    if(rest == 0){
        // 기댓값 계산 시작
        return j;
    } else {

        double &ret = dp[rest][j];

        if(ret != 1001){
            return ret;
        } 
        
        ret = L * (solve(rest - 1, j + 1) - 1);
        ret += R * (solve(rest - 1, std::max(j - 1, 0)) + 1);
        ret += (1 - L - R) * solve(rest - 1, j);

        return ret;
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cout << std::fixed;
    std::cout.precision(4);

    std::cin >> P;

    while(P--){

        // 초기화
        for(int i = 0; i < 1001; i++){
            for(int j = 0; j < 1001; j++){
                dp[i][j] = (double)1001;
            }
        }

        std::cin >> N >> L >> R;

        // N번의 걸음, 0에서 출발
        std::cout << solve(N, 0) << '\n';

    }

    return 0;
}