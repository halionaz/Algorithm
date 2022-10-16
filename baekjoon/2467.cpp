// 용액
// 두 포인터 & 이분 탐색

// 2470 두 용액과 완전히 같은 문제
// 단 두 용액은 정렬되지 않은 채로 입력이 들어오고 이 문제는 정렬된 채로 들어옴

#include <iostream>
#include <vector>
#include <cstdlib>

typedef long long ll;

int N;
std::vector<ll> arr;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    arr.resize(N);

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    int l = 0, r = N - 1;
    int ansL = 0, ansR = N-1;
    ll dist = abs(arr[l] + arr[r]);
    while(l < r){
        ll newDist = arr[l] + arr[r];
        if(abs(newDist) < dist){
            dist = abs(newDist);
            ansL = l;
            ansR = r;
        }
        if(newDist < 0){
            l++;
        } else {
            r--;
        }
    }
    std:: cout << arr[ansL] << ' ' <<arr[ansR] << '\n';

    return 0;
}