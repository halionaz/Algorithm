// 중앙값 제거
// 그리디 알고리즘 & 정렬

#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
 
int N;
long long ans = 0;
long long arr[2000001];
 
int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    std::sort(arr, arr + N);

    for(int i = 0; i < (N%2 ? N/2+1 : N/2); i++){
        ans += (long long)std::floor(log2(arr[i]));
    }

    std::cout << ans+1 << '\n';

}