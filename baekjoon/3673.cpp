// 나눌 수 있는 부분 수열
// 수학 & 누적 합

// 10986과 완전히 똑같은 문제

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