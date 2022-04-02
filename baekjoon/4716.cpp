// 풍선
// 그리디 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int N, A, B;
std::vector<std::vector<int> > arr;

bool cmp(std::vector<int> arr1, std::vector<int> arr2){
    return arr1[0] > arr2[0];
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(1){

        arr.clear();

        std::cin >> N >> A >> B;

        arr.resize(N);

        if(!N && !A && !B){
            break;
        }

        for(int i = 0; i < N; i++){
            arr[i].resize(4);
            std::cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
            arr[i][0] = abs(arr[i][2] - arr[i][3]);
        }

        std::sort(arr.begin(), arr.end(), cmp);

        int ans = 0;

        for(int i = 0; i < N; i++){
            int &from = arr[i][2] > arr[i][3] ? B : A;
            if(from){
                int cnt = std::min(from, arr[i][1]);
                from -= cnt;
                arr[i][1] -= cnt;
                ans += cnt*std::min(arr[i][2], arr[i][3]);
            }
            ans += std::max(arr[i][2], arr[i][3])*arr[i][1];
        }

        std::cout << ans << '\n';
    }

    return 0;
}