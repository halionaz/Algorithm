// 성냥개비
// 다이나믹 프로그래밍 & 그리디 알고리즘

// 성냥의 개수가 주어졌을 때, 만들 수 있는 수의 최댓값과 최솟값을 구해야 함

// 최솟값은 다이나믹 프로그래밍으로 구해야 함
// dp[i]가 성냥 i개로 만들 수 있는 최솟값이면
// dp[i] = dp[i-2]*10 + dp[2], dp[i-3]*10 + dp[3], dp[i-4]*10 + dp[4] ... dp[i-7]*10 + dp[7] 중 최솟값
// (8개 이상의 성냥으로 만들 수 있는 한자리 수는 없음)
// 또한 6개 성냥으로 만들 수 있는 최소 한자리 수는 0이지만, 시작을 0으로 할 수는 없기 때문에
// dp[6] = 6이다. 다만, 계산 중간에 쓰이는 수는 0으로 들어가야 하므로
// num이라는 배열을 따로 만들어 최소 한자리 수를 따로 저장해놓음 

// 최댓값은 그리디 알고리즘으로 쉽게 구할 수 있음
// 자릿수가 최대한 많을 수록 수가 커지므로, 가장 적은 성냥으로 만들 수 있는 숫자인 1이 최대한 많이 들어가면 됨
// 짝수개 성냥이 주어진 경우 ex)6, -> 111 이 가장 큰 수
// 홀수개 성냥이 주어진 경우 ex)7, -> 711 이 가장 큰 수

#include <iostream>
#include <algorithm>

typedef long long ll;

int T, N;
ll dp[101]; // dp[i]는 성냥 i개로 만들 수 있는 최솟값
int num[9] = {0,0,1,7,4,2,0,8,10}; // num[i]는 성냥 i개로 만들 수 있는 1자리 수 최솟값

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    for(int i = 1; i < 9; i++){
        dp[i] = num[i];
    }

    // 숫자가 0으로 시작할 순 없으므로
    dp[6] = 6;

    for(int i = 9; i < 101; i++){

        dp[i] = dp[i-2]*10 + num[2]; 

        for(int j = 3; j < 8; j++){
            dp[i] = std::min(dp[i], dp[i-j]*10 + num[j]);
        }
    }

    std::cin >> T;

    while(T--){

        std::cin >> N;

        std::cout << dp[N] << ' ';

        if(N%2){
            // 홀수인 경우
            std::cout << 7;
            N -= 3;
        }

        for(int i = 0; i < N/2; i++){
            std::cout << 1;
        }

        std::cout << '\n';

    }

    return 0;
}