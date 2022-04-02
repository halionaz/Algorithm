// 축구 게임
// 그리디 알고리즘

// randau의 정리 이용

#include <iostream>
#include <algorithm>
#include <vector>

int N, sum = 0;
std::vector<int> arr;

unsigned nCk( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    arr.resize(N);

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
        sum += arr[i];
    }

    std::sort(arr.begin(),arr.end());

    if(sum == nCk(N,2)){

        bool ans = 1;
        sum = 0;

        for(int i = 0; i < N; i++){
            sum += arr[i];
            if(sum < nCk(i+1,2)){
                ans = 0;
                break;
            }
        }

        if(ans){
            std::cout << "1\n";
            return 0;
        }
    } 

    std::cout << "-1\n";

    return 0;
}