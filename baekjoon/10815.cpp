// 숫자 카드
// 이분 탐색

// C++ Set 자료구조 이용

// #include <iostream>
// #include <set>

// typedef long long ll;

// int N,M;
// std::set<ll> S;

// int main(){

//     std::ios_base::sync_with_stdio(0);
//     std::cin.tie(0);

//     std::cin >> N;

//     for(int i = 0; i < N; i++){
//         ll inp;
//         std::cin >> inp;
//         S.insert(inp);
//     }

//     std::cin >> M;

//     for(int i = 0; i < M; i++){
//         ll inp;
//         std::cin >> inp;
//         std::cout << S.count(inp) << ' ';
//     }
//     std::cout << '\n';
    

//     return 0;
// }

// 이분 탐색 알고리즘 이용

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N,M;
vector<ll> arr;

int search(ll val){
    int s = 0;
    int e = N-1;
    int m;
    while(1){
        if(e<s){
            break;
        } else {

            m = (s+e)/2;

            if(val == arr[m]){
                // 찾으면 1 반환
                return 1;
            } else if (val > arr[m]){
                s = m + 1;
            } else {
                e = m - 1;
            }

        }
    }
    // 없으면 0 반환
    return 0;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        ll inp;
        cin >> inp;
        arr.push_back(inp);
    }

    // 이분 탐색을 위한 정렬
    sort(arr.begin(),arr.end());

    cin >> M;

    for(int i = 0; i < M; i++){
        ll inp;
        cin >> inp;
        cout << search(inp) << ' ';
    }
    cout << '\n';

    return 0;
}