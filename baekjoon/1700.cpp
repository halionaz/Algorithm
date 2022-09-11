// 멀티탭 스케줄링
// 그리디 알고리즘

#include <iostream>

int N, K;
int schedule[101], plug[101];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> K;

    for(int i = 0; i < K; i++){
        std::cin >> schedule[i];
    }

    int ans = 0;

    for(int i = 0; i < K; i++){

        bool pass = false;

        for(int j = 0; j < N; j++){
            if(plug[j] == schedule[i]){
                // 이미 꽂혀 있다면
                pass = true;
                break;
            }
        }

        if(pass){
            continue;
        }

        for(int j = 0; j < N; j++){
            if(plug[j] == 0){
                // 비어있는 구멍을 찾았다면
                plug[j] = schedule[i];
                pass = true;
                break;
            }
        }

        if(pass){
            continue;
        }

        int lastUseInd;
        int lastUseNum = -1;

        for(int j = 0; j < N; j++){
            // 각 플러그에 꽂혀있는 기기가
            // 1. 나중에 다시 안 쓰이는 경우
            // 2. 가장 마지막에 다시 쓰이는 경우
            // 뽑아서 현재 기기를 꽂음

            int l = i + 1;

            for(; l < K; l++){

                if(plug[j] == schedule[l]){
                    break;
                }
            }

            if(l > lastUseNum){
                // 더 마지막에 쓰인 애로 갱신
                lastUseNum = l;
                lastUseInd = j;
            }
        }

        plug[lastUseInd] = schedule[i];
        ans += 1;

    }

    std::cout << ans << '\n';

    return 0;
}