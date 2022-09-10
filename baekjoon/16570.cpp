// 앞뒤가 맞는 수열 
// kmp

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int N;
int ans;
int max = -1;
std::vector<ll> A;

std::vector<int> getPi(){
    std::vector<int> pi(N,0);
    int begin = 1, matched = 0;
    while(begin+matched < N){
        if(A[begin+matched] == A[matched]){
            matched++;
            pi[begin+matched-1] = matched;
            if(matched > max){
                // max값 갱신
                ans = 1;
                max = matched;
            } else if (matched == max){
                ans++;
            }
        } else {
            if(matched == 0){
                begin++;
            } else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

int main(){

    std::cin >> N;

    for(int i = 0; i < N; i++){
        ll a;
        std::cin >> a;
        A.push_back(a);
    }

    // 앞쪽부터 자를 수 있기에, 뒤를 기준으로 한 pi값을 구함
    std::reverse(A.begin(),A.end());

    std::vector<int> pi = getPi();
    if(max == -1){
        std::cout << -1 << '\n';
    } else {
        std::cout << max << ' ' << ans << '\n';
    }
    return 0;
}