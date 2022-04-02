// 보물
// 그리디 알고리즘

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

int N;
int ans = 0;
std::vector<int> A;
std::vector<int> B;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        int x;
        std::cin >> x;
        A.push_back(x);
    }
    for(int i = 0; i < N; i++){
        int x;
        std::cin >> x;
        B.push_back(x);
    }

    std::sort(A.begin(),A.end());
    std::sort(B.begin(),B.end());

    // 결과 값을 가장 작게 만들기 위해서는 
    // A와 가장 큰 값, B의 가장 작은 값
    // B의 가장 큰 값, A의 가장 작은 값을 곱해줘야 함
    for(int i = 0; i < N; i++){
        ans += A[i]*B[N-1-i];
    }

    std::cout << ans << '\n';

    return 0;
}