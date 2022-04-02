#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
std::string arr[500001];
// bool isSim[500001][500001];
int dp[500001], ans, N, K;
//dp[i] = i번째 원소를 마지막으로 하는 LIS의 길이
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for(int i = 1; i <= N; ++i){
        cin >> arr[i];
    }
    for(int i = 1; i <= N; ++i) {
        int here = 0;
        for(int j = 1; j < i; ++j) {
            bool isSim = false;
            for(int k = 0; k < K; k++){
                if(arr[i][k] == arr[j][k]){
                    isSim = true;
                    break;
                }
            }
            if(isSim){
                here = max(here, dp[j]);
            }
        }
        dp[i] = here + 1;
        ans = max(ans, dp[i]);
    }
    cout << N - ans << '\n';
    return 0;
}
