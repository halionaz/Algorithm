// 통나무 건너뛰기
// 그리디 알고리즘

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

int T, N;
std::vector<int> len;
std::vector<int> idea;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        std::cin >> N;
        len.resize(N);
        idea.resize(N);

        for(int i = 0; i < N; i++){
            std::cin >> len[i];
        }

        std::sort(len.begin(), len.end());

        for(int i = 0; i < (N%2 ? N/2 + 1 : N / 2); i++){
            int l = i;
            int r = N - 1 - i;

            if(l != r){
                idea[l] = len[i*2];
                idea[r] = len[i*2+1];
            } else {
                idea[l] = len[i*2];
            }
        }

        int level = 0;

        for(int i = 0 ; i < N ; i++){
            if(i){
                level = std::max(level, std::abs(idea[i] - idea[i-1]));
            } else {
                level = std::max(level, std::abs(idea[i] - idea[N-1]));
            }
        }

        std::cout << level << '\n';

    }

    return 0;
}