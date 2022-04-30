// 수열 정렬
// 정렬

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int N;
std::vector<std::pair<int, int> > A;
std::vector<int> ans;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    ans.resize(N);

    for(int i = 0; i < N; i++){
        int inp;
        std::cin >> inp;
        A.push_back(std::make_pair(inp, i));
    }

    std::sort(A.begin(), A.end());

    for(int i = 0; i < N; i++){
        ans[A[i].second] = i;
    }

    for(int i = 0; i < N; i++){
        std::cout << ans[i] << ' ';
    }

    std::cout << '\n';

    return 0;
}