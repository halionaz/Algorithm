// 나눌 수 있는 부분 수열
// 수학 & 누적 합

// 10986과 완전히 똑같은 문제

// 수 A1, A2, A3 ... 가 주어졌을 때
// 연속된 부분 합이 M으로 나눠 떨어지는 구간의 개수를 구해야 함

// pSum[i]가 0~i까지의 누적합이라 하면,
// pSum[i]%M이 0인 경우 M으로 나눠 떨어지는 구간이 나오고,
// pSum[i]%M과 pSum[j-1]%M이 같으면, (pSum[i]-pSum[j-1])%M = 0 이므로 j~i 구간의 부분 합이 M으로 나눠 떨어짐

// 따라서 pSum[] 배열에 각 누적합의 M 나머지를 저장하고,
// pSum이 0인 경우 + pSum이 같은 경우의 "쌍" 개수 를 구하면 답임

#include <iostream>
#include <string.h>

typedef long long ll;

ll d, n;
ll pSum[50001];
ll cnt[1000001];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int c;

    std::cin >> c;

    while(c--){

        memset(pSum, 0, sizeof(pSum));
        memset(cnt, 0, sizeof(cnt));

        std::cin >> d >> n;

        for(int i = 0; i < n; i++){
            std::cin >> pSum[i];
            if(i){
                pSum[i] += pSum[i-1];
            }
            pSum[i] %= d;
            cnt[pSum[i]]++;
        }

        ll ans = cnt[0];

        for(int i = 0; i < d; i++){
            ans += (cnt[i]*(cnt[i]-1))/2;
        }

        std::cout << ans << '\n';

    }
}