// 나머지 합
// 수학 & 누적 합

// 수 A1, A2, A3 ... 가 주어졌을 때
// 연속된 부분 합이 M으로 나눠 떨어지는 구간의 개수를 구해야 함

// pSum[i]가 0~i까지의 누적합이라 하면,
// pSum[i]%M이 0인 경우 M으로 나눠 떨어지는 구간이 나오고,
// pSum[i]%M과 pSum[j-1]%M이 같으면, (pSum[i]-pSum[j-1])%M = 0 이므로 j~i 구간의 부분 합이 M으로 나눠 떨어짐

// 따라서 pSum[] 배열에 각 누적합의 M 나머지를 저장하고,
// pSum이 0인 경우 + pSum이 같은 경우의 "쌍" 개수 를 구하면 답임

#include <iostream>

typedef long long ll;

int N, M;
ll pSum[1000001]; // 누적합을 M으로 나누었을 때 나머지 저장
ll cnt[1001]; // 각 나머지 별 개수 저장
ll ans;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < N; i++){

        std::cin >> pSum[i];
        if(i){
            // 첫 입력이 아니라면
            pSum[i] += pSum[i-1];
        }
        pSum[i] %= M;
        cnt[pSum[i]] += 1;
    }

    ans = cnt[0]; // 0~i까지의 부분합이 이미 M으로 나눠 떨어지는 경우들 카운트

    for(int i = 0; i < M; i++){
        ans += (cnt[i] * (cnt[i]-1)) / 2; // 나머지가 같은 경우의 쌍 (조합) 더해주기
    }

    std::cout << ans << '\n';

    return 0;
}