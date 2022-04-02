// 세 용액
// 두 포인터 & 이분 탐색

// 두 용액과 달리 3개의 용액을 합쳐 0에 근접한 값 만들기
// 기준 용액을 N-2번씩 선택하고 나머지로 두 용액 문제를 풀면 됨


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int N;
long long ans = LLONG_MAX;
std::vector<long long> arr;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    arr.resize(N);

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());

    int i1, i2, i3;

    for(int i = 0; i < N-2; i++){

        int j = i + 1;
        int k = N - 1;

        while(j < k){

            long long sum = arr[i] + arr[j] + arr[k];

            if(llabs(sum) < ans){
                ans = llabs(sum);
                i1 = i;
                i2 = j;
                i3 = k;
            }

            if(sum < 0){
                j++;
            } else {
                k--;
            }

        }
    }

    std::cout << arr[i1] << ' ' << arr[i2] << ' ' << arr[i3] << '\n';

    return 0;
}