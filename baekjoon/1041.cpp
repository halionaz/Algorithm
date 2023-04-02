// 주사위
// 그리디 알고리즘

// N > 1일 때,
// N * N * N 정육면체를 만들 때,
// 세 면이 보이는 주사위는 윗 꼭짓점 4개 뿐이고,
// 두 면이 보이는 주사위는 위 모서리 (N-2)*4개 + 옆 모서리 (N-1)*4개
// 한 면이 보이는 주사위는 윗면 (N-2)^2개 + 옆면 (N-2)*(N-1)*4개

// 주사위의 면을 0~5로 인덱싱 했을 경우, 두 면의 합이 5이면 마주보는 면
// 이를 참조하여 최소 2개 면, 3개 면을 구해줌

#include <iostream>
#include <algorithm>

typedef long long ll;

int N;
int dice[6];
ll ans = 0;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    int maxSide = 0;
    int min1side = 51, min2side = 102, min3side = 153;

    for(int i = 0 ; i < 6; i++){
        std::cin >> dice[i];
        maxSide = std::max(maxSide, dice[i]);
        min1side = std::min(min1side, dice[i]);
    }


    if(N == 1){
        // N이 1일 때 예외 처리
        for(int i = 0; i < 6; i++){
            ans += dice[i];
        }

        std::cout << ans - maxSide << '\n';
        return 0;
    }

    for(int i = 0; i < 6; i++){
        for(int j = i+1; j < 6; j++){
            if(i + j == 5){
                // i면과 j면이 마주보므로 케이스 성립 X
                continue;
            }
            min2side = std::min(min2side, dice[i] + dice[j]);
            for(int k = j+1 ; k < 6; k++){
                if(i + k == 5 || j + k == 5){
                    continue;
                }
                min3side = std::min(min3side, dice[i] + dice[j] + dice[k]);
            }
        }
    }

    ans += 4 * min3side;
    ans += (8 * N - 12) * min2side;
    ans += (5 * (ll)N*N - 16 * N + 12) * min1side;

    std::cout << ans << '\n';

    return 0;
}