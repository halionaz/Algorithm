// Parcel
// 다이나믹 프로그래밍

// 4 중첩 for문으로 풀면 시간 초과 

// arr를 오름차순으로 정렬하여
// (arr[j_1] + arr[i]) < (arr[i+1] + arr[j_2]) 로 만든 후
// 앞쪽걸 미리 선회 한 후, 
// 뒤의 것을 적용하는 경우 가능한지 판별

#include <iostream>
#include <algorithm>

int W,N;
int arr[5000];
bool dp[400001] = {0};

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> W >> N;

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    std::sort(arr, arr+N);

    for(int i = 0; i < N - 2; i++){
        for(int j = 0; j < i; j++){
            dp[arr[i] + arr[j]] = true;
        }

        for(int j = i + 2; j < N; j++){
            int rest = W - arr[i+1] - arr[j];
            if(rest < 0){
                break;
            }
            if(rest <= 400000 && dp[rest]){
                std::cout << "YES\n";
                return 0;
            }
        }
    }

    std::cout << "NO\n";

    return 0;
}