// 수 정렬하기 3
// 정렬

// 단순하게 저장받았다가 정렬하면 
// 8MB 메모리 초과가 뜸
// 따라서 각 수 별로 카운팅 해야됨

// #include <iostream>
// #include <algorithm>

// int N;
// int arr[10000000];

// int main(){

//     std::ios_base::sync_with_stdio(0);
//     std::cin.tie(0);

//     std::cin >> N;

//     for(int i = 0; i < N; i++){
//         std::cin >> arr[i];
//     }

//     std::sort(arr, arr + N);

//     for(int i = 0; i < N; i++){
//         std::cout << arr[i] << '\n';
//     }

//     return 0;
// }

#include <iostream>

int N, inp;
int cnt[10001];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> inp;
        cnt[inp]++;
    }

    for(int i = 1; i <= 10000; i++){
        while(cnt[i]--){
            std::cout << i << '\n';
        }
    }

    return 0;
}
