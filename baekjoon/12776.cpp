// Swap Space
// 그리디 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
typedef std::vector<ll> p;

int N;
std::vector<p> arr;

bool cmp(p a, p b){
    ll valA = a[1] - a[0];
    ll valB = b[1] - b[0];
    if(valA >= 0 && valB < 0){
        return true;
    } else if(valA < 0 && valB >= 0){
        return false;
    } else if(valA < 0){
        // 둘다 뒤에 것이 앞에 것보다 작을 때
        return a[1] > b[1];
    } else {
        // 둘다 클 때
        return a[0] < b[0];
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;


    for(int i = 0; i < N; i++){
        std::vector<ll> vec(2);
        std::cin >> vec[0] >> vec[1];
        arr.push_back(vec);
    }

    std::sort(arr.begin(),arr.end(),cmp);

    ll a = 0;
    ll b = 0;
    for(int i = 0; i < N; i++){
        ll valA = std::max(a, a - b + arr[i][0]);
        ll valB = -a + b - arr[i][0] + arr[i][1] + valA;
        a = valA;
        b = valB;
    }

    std::cout << a << '\n';

    return 0;
}