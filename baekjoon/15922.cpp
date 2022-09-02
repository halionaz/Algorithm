// 아우으 우아으이야!! 
// 스위핑

#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int> > arr;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        int x, y;
        std::vector<int> vec(2);
        std:: cin >> vec[0] >> vec[1];
        arr.push_back(vec);
    }

    // 이미 arr은 정렬된 상태로 주어짐

    int start = arr[0][0];
    int end = arr[0][1];
    long long ans = 0;

    for(int i = 1; i < N; i++){
        if(arr[i][0] <= end){
            if(arr[i][1] > end){
                end = arr[i][1];
            }
        } else {
            ans += end-start;
            start = arr[i][0];
            end = arr[i][1];
        }
    }
    ans += end-start;
    std::cout << ans << '\n';
    return 0;
}