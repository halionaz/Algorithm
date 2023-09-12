// 대표값2
// 정렬 & 사칙연산 & 수학

#include <iostream>
#include <algorithm>

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int arr[5];
    int sum = 0;

    for(int i = 0; i < 5; i++){
        std::cin >> arr[i];
        sum += arr[i];
    }

    std::sort(arr, arr + 5);

    std::cout << sum / 5 << '\n' << arr[2] << '\n';

    return 0;
}