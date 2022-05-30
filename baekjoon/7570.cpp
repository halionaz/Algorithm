// 줄 세우기
// 다이나믹 프로그래밍

// 가장 긴 증가하는 부분 수열 아이디어 이용
// 헝클어진 줄을 최소 횟수로 정렬하는 방법이므로
// 이미 정렬되어있는 가장 긴 증가하는 부분 수열을 구한 후
// 전체 명수에서 빼면 답이 나옴

// 단 움직이는 것에 제한이 걸려있음
// (제일 앞으로 보내거나, 제일 뒤로만 보낼 수 있음)
// 따라서 부분수열에 연속적이지 않다면, 답이 구해지지 않음
// 때문에 가장 긴 '연속하는' 부분 수열을 구해야 함

#include <iostream>
#include <algorithm>

int N, lis = 0;
int order[1000001]; // 서 있는 순서대로 번호 정렬
int ind[1000001]; // 원래 번호대로 서있는 순서 정렬
int dp[1000001];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> order[i];
        ind[order[i]] = i;
    }

    for(int i = 0 ; i<N; i++){

        // 기존 방식으로 했더니 시간 초과 발생
        // dp[i] = 1;
        // for(int j = 0; j < i; j++){
        //     if(order[j] + 1 == order[i] && dp[i] < dp[j] + 1){
        //         dp[i] = dp[j] + 1;
        //     }
        // }

        dp[i] = dp[ind[order[i] - 1]] + 1;

        lis = std::max(lis, dp[i]);
    }

    std::cout << N - lis << '\n';

    return 0;
}