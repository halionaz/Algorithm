// Mearlin QA (Large)
// 애드 혹 & 그리디 알고리즘

// 공부가 더 필요함..
// 비용만 들어가는 주문은 처음에 미리 다 시전해버리는 게 좋고 (답에 영향 없음)
// 그 이후에 각 재료를 선택하는 순열에 따라 답을 계산하는 것 같은데 조금 더 연구가 필요함..!!
// 거의 이해하지 못한 채 풀었음

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

        valuableSpells.clear();
        for(int i = 0; i < 100; i++){
            spells[i].clear();
        }

        std::cin >> N >> M;

        for(int i = 0; i < N; i++){
            int maxCost = 0;
            spells[i].resize(M);
            for(int j = 0; j < M; j++){
                std::cin >> spells[i][j];
                maxCost = std::max(maxCost, spells[i][j]);
            }
            if(maxCost > 0){
                valuableSpells.push_back(spells[i]);
            }
        }

        if(valuableSpells.size() == 0){
            // 버는게 없으므로 0 출력
            std::cout << "Case #" << t << ": " << 0 << '\n';
            continue;
        }

        ans = 0;

        std::vector<int> permute(M);
        for(int i = 0; i < M; i++){
            permute[i] = i;
        }

        do{

            int vals = 0;
            for(int i = 0; i < valuableSpells.size(); i++){
                int val = 0;
                int costs = 0;

                for(int j = 0; j < M; j++){
                    costs += valuableSpells[i][permute[j]];
                    val = std::max(val, costs);
                }
                vals += val;

            }
            ans = std::max(ans, vals);

        } while(std::next_permutation(permute.begin(), permute.end()));

        std::cout << "Case #" << t << ": " << ans << '\n';

    }

    return 0;
}