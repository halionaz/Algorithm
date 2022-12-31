// 눈 치우기
// 구현 & 정렬 & 그리디 알고리즘

#include <functional>
#include <iostream>
#include <algorithm>

int N;
int height[101];

bool cmp(int x, int y){
    return x > y;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> height[i];
    }


    int ans = 0;

    while(true){
        std::sort(height, height + N + 1, cmp);
        // 첫번째 눈 치우기
        ans += 1;
        int first;
        for(int i = 0; i < N; i++){
            if(height[i] > 0){
                // 눈이 있으면?
                height[i] -= 1; // 치운다
                first = i;
                break;
            }
        }
        // 두번째 눈 치우기
        for(int i = 0; i < N; i++){
            if(i != first && height[i] > 0){
                // 처음이랑 다른 애고
                // 눈이 있으면?
                height[i] -= 1;
                break;
            }
        }
        bool done = true;
        for(int i = 0; i < N; i++){
            if(height[i] > 0){
                done = false;
            }
        }
        if(done){
            // 눈이 다 없어졌다면
            break;
        }
    }

    std::cout << (ans > 1440 ? -1 : ans) << '\n';

    return 0;
}