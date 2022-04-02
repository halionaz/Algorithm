// 라면 사기 (Large)
// 그리디 알고리즘 

#include <iostream>

typedef long long ll;

ll N, B, C, eff;
ll arr[1000004];
ll ans = 0;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> B >> C;

    if(C > B){
        // 따로 사는게 나음
        C = B;
    }

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    for(int i = 0; i < N; i++){
        if(arr[i+1] > arr[i+2]){
            eff = std::min(arr[i], arr[i+1] - arr[i+2]);
            ans += (B+C)*eff;
            arr[i] -= eff;
            arr[i+1] -= eff;
            eff = std::min(arr[i], std::min(arr[i+1], arr[i+2]));
            ans += (B+2*C)*eff;
            arr[i] -= eff;
            arr[i+1] -= eff;
            arr[i+2] -= eff;
        } else {
            eff = std::min(arr[i], std::min(arr[i+1], arr[i+2]));
            ans += (B+2*C)*eff;
            arr[i] -= eff;
            arr[i+1] -= eff;
            arr[i+2] -= eff;
            eff = std::min(arr[i], arr[i+1]);
            ans += (B+C)*eff;
            arr[i] -= eff;
            arr[i+1] -= eff;
        }
        ans += B * arr[i];
    }

    std::cout << ans << '\n';

    return 0;
}