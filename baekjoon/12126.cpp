// Mearlin QA (Large)
// 애드 혹 & 그리디 알고리즘

// 비용만 들어가는 주문은 처음에 미리 다 시전해버리는 게 좋음 (답에 영향 없음)

#include <iostream>
#include <vector>
#include <algorithm>

int T, N, M, ans;
std::vector<int> spells[100];
std::vector<std::vector<int> > valuableSpells;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    for(int t = 1; t <= T; t++){

        // 변수 초기화
        valuableSpells.clear();
        for(int i = 0; i < 100; i++){
            spells[i].clear();
        }

        std::cin >> N >> M;

        for(int i = 0; i < N; i++){
            // 주문을 시전하여 얻을 수 있는 가치 계산
            int maxCost = 0;
            spells[i].resize(M);
            for(int j = 0; j < M; j++){
                std::cin >> spells[i][j];
                maxCost = std::max(maxCost, spells[i][j]);
            }
            if(maxCost > 0){
                // 주문을 통해 무언갈 얻을 수 있다면
                valuableSpells.push_back(spells[i]);
            }
        }

        if(valuableSpells.size() == 0){
            // 버는게 없으므로 0 출력
            std::cout << "Case #" << t << ": " << 0 << '\n';
            continue;
        }

        // 계산 전 버는게 없는 주문들은 다 시전해버렸다고 가정

        ans = 0;

        std::vector<int> permute(M);

        for(int i = 0; i < M; i++){
            permute[i] = i;
        }

        do{
            // 어떤 재료를 마지막에 남기냐에 따라 주문의 순서는 정해질 수 밖에 없음
            // 재료를 산정하는 순서를 순열을 통해 모든 경우를 돌려봄
            // (재료 순서를 통해 어떤 재료를 마지막에 남길지 결정)
            int vals = 0;

            for(int i = 0; i < valuableSpells.size(); i++){
                int val = 0;
                int costs = 0;

                // 재료를 계산하는 순서에 따라 각 시점 별 costs가 달라짐
                for(int j = 0; j < M; j++){
                    costs += valuableSpells[i][permute[j]];
                    val = std::max(val, costs);
                }
                vals += val;
            }

            // 정답 갱신
            ans = std::max(ans, vals);

        } while(std::next_permutation(permute.begin(), permute.end()));

        std::cout << "Case #" << t << ": " << ans << '\n';

    }

    return 0;
}