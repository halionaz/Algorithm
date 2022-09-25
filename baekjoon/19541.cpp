// 역학 조사
// 시뮬레이션 & 그리디 알고리즘

#include <iostream>
#include <vector>

const int maxNum = 100001;

int N, M;
std::vector<int> party[maxNum];
bool memo[maxNum];
bool first[maxNum];
bool last[maxNum];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < M; i++){
        int n;
        std::cin >> n;
        for(int j = 0; j < n; j++){
            int participant;
            std::cin >> participant;
            party[i].push_back(participant);
        }
    }

    // 최종 감염 여부 판단
    for(int i = 1; i <= N; i++){
        std::cin >> memo[i];
        first[i] = last[i] = memo[i];
    }

    for(int i = M-1; i >= 0; i--){
        // 역순으로 돌림
        bool isClean = false;
        for(int j = 0; j < party[i].size(); j++){
            if(!memo[party[i][j]]){
                // clean한 사람이 모임에 한명이라도 있음
                // 그 당시에는 이 파티는 청정 파티였던 것.
                isClean = true;
                break;
            }
        }
        if(isClean){
            for(int j = 0; j < party[i].size(); j++){
                // clean하다면, 초기 비감염자 후보임
                first[party[i][j]] = memo[party[i][j]] = false;
            }
        }
    }

    // 초기 감염자 후보가 추려졌으므로 시뮬레이션 돌려봄
    for(int i = 1; i<= N; i++){
        memo[i] = first[i];
    }

    for(int i = 0; i < M; i++){
        int isInfected = false;
        for(int j = 0; j < party[i].size(); j++){
            if(memo[party[i][j]]){
                // 한명이라도 감염 시 이 파티는 오염됨 
                isInfected = true;
                break;
            }
        }
        if(isInfected){
            for(int j = 0; j < party[i].size(); j++){
                memo[party[i][j]] = true;
            }
        }
    }
    bool ans = true;
    for(int i = 1; i <= N; i++){
        if(memo[i] != last[i]){
            // 시뮬레이션 돌려본 결과가 최종값과 다름
            ans = false;
            break;
        }
    }

    if(ans){

        std::cout << "YES\n";

        for(int i = 1; i <= N; i++){
            std::cout << first[i] << ' ';
        }

        std::cout << '\n';

    } else {
        std::cout << "NO\n";
    }

    return 0;
}