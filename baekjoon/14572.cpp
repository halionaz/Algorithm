// 스터디 그룹
// 그리디 알고리즘 & 두 포인터 & 비트마스킹

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int N, K, D, M, d;
int algCnt[31];
std::vector<std::pair<int, int> > students;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> K >> D;

    for(int i = 0; i < N; i++){
        std::cin >> M >> d;
        // 현재 학생이 알고있는 알고리즘을 비트마스킹으로 저장
        int alg = 0;
        for(int j = 0; j < M; j++){
            int inp;
            std::cin >> inp;
            alg |= (1 << (--inp));
        }
        students.push_back(std::make_pair(d, alg));
    }

    // 학생의 실력 순으로 정렬
    std::sort(students.begin(), students.end());

    int l = 0, r = 0, ans = 0;

    while(r < N){
        // 투 포인터를 통한 각 경우의 수 계산
        while(students[r].first - students[l].first > D){
            // 난이도 차가 많이 나서 성립하지 않는 경우
            // l을 뒤로 땡겨야 함
            for(int i = 0; i < K; i++){
                if(students[l].second & (1 << i)){
                    // 빠져야 하는 애가 들고 있는 알고리즘이면 카운트에서 제외
                    algCnt[i] -= 1;
                }
            }
            l++;
        }
        
        // r을 통해 증가된 알고리즘 카운트 변경
        for(int i = 0; i < K; i++){
            if(students[r].second & (1 << i)){
                algCnt[i] += 1;
            }
        }

        // 효율성 계산
        int curE = 0;
        for(int i = 0; i < K; i++){
            if(algCnt[i] > 0 && algCnt[i] < r - l + 1){
                // 알고리즘을 아는 사람이 1명이라도 있지만, 모두가 알지는 않는 알고리즘 더하기
                curE++;
            }
        }

        curE = curE * (r - l + 1);
        ans = std::max(ans, curE);

        r++;
    }

    std::cout << ans << '\n';

    return 0;
}