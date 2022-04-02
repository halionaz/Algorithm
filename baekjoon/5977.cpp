// Mowing the Lawn
// 다이나믹 프로그래밍 & 덱을 이용한 다이나믹 프로그래밍

// 슬라이딩 윈도우 기법
// dp[i] = max(Esum[i] - Esum[j] + dp[j-1]) (i-K <= j <= i)  :: j+1 ~ i 까지의 합 + j까지의 최대 효율
// dp[i] = Esum[i] + max(dp[j-1] - Esum[j]) (i-K <= j <= i)
// dp[j-1] - Esum[j]의 최댓값을 탐색

#include <iostream>
#include <deque>
#include <algorithm>

typedef long long ll;

int N, K;
ll Esum[100001] = {0,};
ll dp[100001];
std::deque<int> deq; //index 값만 저장하면 되므로 int

ll cal(int i){
    return dp[i-1] - Esum[i];
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> K;

    for(int i = 1; i <= N; i++){
        ll val;
        std::cin >> val;
        Esum[i] = Esum[i-1] + val;
    }

    for(int i = 1; i <= N; i++){
        if(!deq.empty() && deq.front() < i - K){
            deq.pop_front();
        }
        while(!deq.empty() && cal(deq.back()) < cal(i)){
            deq.pop_back();
        }
        deq.push_back(i);
        dp[i] = Esum[i] + cal(deq.front());
        if(i <= K){
            // i <= K 인 경우 단순히 처음부터 다 더한게 더 클 수도 있음
            dp[i] = std::max(dp[i],Esum[i]);
        }
    }

    std::cout << dp[N] << '\n';

    return 0;
}