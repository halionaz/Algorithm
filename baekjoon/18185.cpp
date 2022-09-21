// 라면 사기 (Small)
// 그리디 알고리즘

#include <iostream>
#include <algorithm>

int N, eff;
int arr[10003];
int ans = 0;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    for(int i = 0; i < N; i++){
        // 최대한 세 공장에서 공구하는게 좋음
        if(arr[i+1] > arr[i+2]){
            // 현재 3번째 공장의 수요가 적으므로
            // 세 공장 공구를 최대로 하기 위해 앞 두 공장에서 차이만큼 공구하고 감
            eff = std::min(arr[i], arr[i+1] - arr[i+2]);
            ans += 5 * eff;
            arr[i] -= eff;
            arr[i+1] -= eff;
            eff = std::min(arr[i], std::min(arr[i+1], arr[i+2]));
            ans += 7 * eff;
            arr[i] -= eff;
            arr[i+1] -= eff;
            arr[i+2] -= eff;
        } else {
            eff = std::min(arr[i], std::min(arr[i+1], arr[i+2]));
            ans += 7 * eff;
            arr[i] -= eff;
            arr[i+1] -= eff;
            arr[i+2] -= eff;
            eff = std::min(arr[i], arr[i+1]);
            ans += 5 * eff;
            arr[i] -= eff;
            arr[i+1] -= eff;
        }
        // 공구를 했음에도 수요가 남은 현재 공장꺼 사기
        ans += 3 * arr[i];
    }

    std::cout << ans << '\n';

    return 0;
}