// 수상 택시
// 스위핑 

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int N;
ll M, ans = 0, start, end;
std::vector<std::vector<ll> > arr;

int main(){
    
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < N; i++){
        ll x,y;
        std::vector<ll> vec;
        std::cin >> x >> y;
        if(x > y){
            vec.push_back(y);
            vec.push_back(x);
            arr.push_back(vec);
        }
    }

    std::sort(arr.begin(),arr.end());

    start = arr[0][0];
    end = arr[0][1];

    for(int i = 1; i < arr.size(); i++){
        if(arr[i][0] <= end){
            if(arr[i][1] > end){
                end = arr[i][1];
            }
        } else {
            ans += end - start;
            start = arr[i][0];
            end = arr[i][1];
        }
    }
    ans += end - start;

    std::cout << M + 2*ans << '\n';
    
    return 0;
}