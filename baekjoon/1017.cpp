// 소수 쌍
// 이분 매칭 & 소수 판정 & 에라토스테네스의 체

// 두 수의 합이 소수가 되게 하려면
// 짝수 + 짝수 / 홀수 + 홀수는 짝수(2의 배수)이므로 소수가 될 수 없고
// 무조건 홀수 + 짝수 만이 소수가 될 가능성이 있으므로
// 두 이분 그래프를 홀수 집합과 짝수 집합으로 나누어 구성하여
// 이분매칭을 시도하고, 소수로 판정될 때 연결해줌

#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
#include <algorithm>

int N, inp, firstNum;
bool isPrime[2001];
bool AOdd = true;
std::vector<int> A; // 집합 A
std::vector<int> B; // 집합 B
std::vector<int> line[51]; // 간선 저장
bool doneMatch[51]; // 이 수의 매칭이 끝났는지를 저장
int whichMatch[51]; // 이 수에 연결된 수가 무엇인지 저장

bool dfs(int ANum){

    if(ANum == 0){
        // 첫 수는 매칭 해놓고 생각 중이므로
        // 첫 수 등장 시 false를 무조건 뱉는다
        return false;
    }

    for(int i = 0; i < line[ANum].size(); i++){
        int BNum = line[ANum][i];
        if(!doneMatch[BNum]){
            doneMatch[BNum] = true;
            // 이 B 수가 매칭이 아예 안되어 있거나, 배정되어있는 A 수가 다른 B 수로 옮길 수 있다면
            if(whichMatch[BNum] == -1 || dfs(whichMatch[BNum])){
                whichMatch[BNum] = ANum;
                return 1;
            }
        }
    }

    // 매칭 불가
    return 0;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    std::cin >> firstNum;

    A.push_back(firstNum);
    if(firstNum % 2){
        // 첫 수가 홀수이면, A는 홀수 집합
        AOdd = true;
    } else {
        // 첫 수가 짝수이면, A는 짝수 집합
        AOdd = false;
    }

    for(int i = 1; i < N; i++){
        std::cin >> inp;
        if(inp%2){
            // 홀수
            if(AOdd){
                A.push_back(inp);
            } else {
                B.push_back(inp);
            }
        } else {
            // 짝수
            if(AOdd){
                B.push_back(inp);
            } else {
                A.push_back(inp);
            }
        }
    }

    // 소수 리스트 찾아내기
    // 두 수의 합이 최대 1999까지 될 수 있으므로 2000까지 구해놓는다 < 이게 틀린 이유였음..
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= int(std::sqrt(2001)); i++){
        if(isPrime[i]){
            for(int j = i*i; j < 2001; j += i){
                isPrime[j] = false;
            }
        }
    }

    // 홀수 개수와 짝수 개수가 안 맞다면 어차피 모든 소수쌍을 매칭할 수 없음
    if(A.size() != B.size()){
        std::cout << -1 << '\n';
        return 0;
    }

    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            if(isPrime[A[i] + B[j]]){
                // i번째 홀수와 j번째 짝수를 연결한게 소수라면, 간선 형성
                line[i].push_back(j);
            }
        }
    }

    std::vector<int> answer;

    for(int i = 0; i < line[0].size(); i++){
        // 첫 수와 연결될 여지가 있는 애들 모두 조사
        memset(whichMatch, -1, sizeof(whichMatch));

        int Bcand = line[0][i];

        whichMatch[Bcand] = 0;

        int match = 1;

        for(int j = 1; j < A.size(); j++){
            memset(doneMatch, false, sizeof(doneMatch));
            if(dfs(j)){
                match += 1;
            }
        }

        if(match == B.size()){
            // 모두 매칭이 가능하면
            // 경우의 수 추가
            answer.push_back(B[Bcand]);
        }
    }

    if(answer.size()){
        std::sort(answer.begin(), answer.end());
        for(int i = 0; i < answer.size(); i++){
            std::cout << answer[i] << ' ';
        }
    } else {
        std::cout << -1;
    }
    std::cout << '\n';

    return 0;
}