// 반도체 설계
// 가장 긴 증가하는 부분 수열: o(n log n) & 이분 탐색 

// 이분 탐색은 2568.cpp에서처럼 algorithm STL의 lower_bound()를 이용해도 되나
// 본 문제에서는 직접 구현해 사용하였음

#include <iostream>
#include <vector>

int n;
std::vector<int> arr;
std::vector<int> LIS;

void binarySearch(int s, int e, int key){

    while(true){
        if(s > e){
            break;
        } else {
            int mid = (s+e)/2;
            if(LIS[mid] == key){
                return;
            } else if(LIS[mid] > key) {
                e = mid-1;
            } else {
                s = mid+1;
            }
        }
    }

    LIS[s] = key;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;

    arr.resize(n+1);

    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    for(int i = 0; i <n; i++){
        int len = LIS.size();
        if(len){
            if(LIS[len-1] < arr[i]){
                LIS.push_back(arr[i]);
            } else {
                binarySearch(0, len-1, arr[i]);
            }
        } else {
            LIS.push_back(arr[i]);
        }
    }

    std::cout << LIS.size() << '\n';

    return 0;
}