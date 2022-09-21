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
        // 최대한 세 공장에서 공구하는게 좋음
        if(arr[i+1] > arr[i+2]){
            // 현재 3번째 공장의 수요가 적으므로
            // 세 공장 공구를 최대로 하기 위해 앞 두 공장에서 차이만큼 공구하고 감
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
        // 공구를 했음에도 수요가 남은 현재 공장꺼 사기
        ans += B * arr[i];
    }

    std::cout << ans << '\n';

    return 0;
}