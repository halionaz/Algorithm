// 중앙값 제거

#include<iostream>
#include <queue>
#include <algorithm>
#include <cmath>
 
int N;
long long ans = 0;
long long arr[2000001];
 
int main()
{

    std::priority_queue<long long> Max_PQ, Min_PQ;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%lld", &arr[i]);
    }

    std::sort(arr, arr + N);

    for(int i = 0; i < (N%2 ? N/2+1 : N/2); i++){
        ans += (long long)std::floor(std::log2(arr[i]));
    }

    std::cout << ans+1 << '\n';

}