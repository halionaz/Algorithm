#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

ll N, G, K, S, L;
bool O;
std::vector<std::vector<ll> > nec;
std::vector<std::vector<ll> > arr;

bool compare(std::vector<ll> a, std::vector<ll> b){
    ll a_val = (G/a[0]) + a[1];
    ll b_val = (G/b[0]) + b[1];
    return a_val > b_val;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> G >> K;
    // N개의 재료, G마리 이하까지 가능, K개 제외 가능

    for(int i = 0; i < N; i++){
        std::vector<ll> vec(3);
        std::cin >> vec[0] >> vec[1] >> vec[2];
        if(vec[2]){
            arr.push_back(vec);
        } else {
            nec.push_back(vec);
        }
    }

    std::sort(arr.begin(), arr.end(), compare);

    // for(int i = 0; i < arr.size(); i++){
    //     std::cout << arr[i][0] << ' ' << arr[i][1] << ' ' << arr[i][2] << '\n';
    // }

    for(ll ans = 0; ans < 1000000001; ans++){
        ll germ = 0;
        for(int i = 0; i < nec.size(); i++){
            germ += std::max((ll)1, ans - nec[i][1]) * nec[i][0];
        }

        for(int i = 0; i < N - nec.size() - K; i++){
            germ += std::max((ll)1, ans - arr[i][1]) * arr[i][0];
        }

        if(germ > G){
            std::cout << ans - 1 << '\n';
            break;
        }
    }

    return 0;
}