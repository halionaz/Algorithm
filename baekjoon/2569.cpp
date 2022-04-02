// 짐정리
// 그리디 알고리즘 & 순열 사이클 분할

// 그리디 시스템을 구상하기가 어려웠던 문제
// 짐을 옮기다 보면 무조건 사이클이 생기게 됨 
// (원래 순서에 맞는 짐도 1개의 노드 사이클)

// 사이클마다 짐을 정리하면 되고, 사이클의 최소 힘을 만들어내는 방법은 다음과 같다
// - 사이클 내 최소 무게 짐을 옮겨가며 짐 정리
// - 전체 최소 무게 짐을 사이클 내 최소 무게와 바꾼 후 사이클을 모두 정리하고 다시 바꾸기

// 사이클 내 짐은 모두 그 무게만큼을 한번씩 써야 하고,
// 옮겨다니게 되는 짐이 짐 숫자 - 1만큼 답에 더해짐

#include <iostream>
#include <vector>
#include <algorithm>

int N, ans = 0;
bool visited[1000];
std::vector<std::pair<int, int> > load;
// first 짐의 무게, second 원래 index
// 정렬하면 순서가 바뀌므로 second에 원래 ind를 넣어 구분

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    load.resize(N);

    for(int i = 0; i < N; i++){
        std::cin >> load[i].first;
        load[i].second = i;
    }

    std::sort(load.begin(), load.end());
    // 짐 무게 순서로 정렬

    for(int i = 0; i < N; i++){
        if(!visited[i]){
            int cnt = 0;
            for(int j = i; !visited[j]; j = load[j].second){
                // 사이클이 있으니 언젠간 이미 visited했던 노드로 돌아옴
                visited[j] = true;
                ans += load[j].first;
                // 짐 무게 만큼 답에 추가
                cnt++;
            }
            // 전체 짐 중 최소 무게 짐을 사이클 내 최소 짐과 바꿔치기 한 후, 짐을 정리하고
            // 다시 최소 무게 짐과 최소 짐을 바꿔치는 경우
            // VS
            // 사이클 내 최소 짐으로 짐을 정리하는 경우
            ans += std::min(load[0].first*(cnt+1) + load[i].first,
            load[i].first*(cnt-2)
            );
        }
    }

    std::cout << ans << '\n';

    return 0;
}