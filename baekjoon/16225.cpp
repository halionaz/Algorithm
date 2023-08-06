// 제271회 웰노운컵
// 그리디 알고리즘 & 우선순위 큐

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N, A[200001], B[200001];
std::vector<std::vector<int> > problems;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        std::cin >> B[i];
    }
    for(int i = 0; i < N; i++){
        // B[i]를 기준으로 문제 정렬
        std::vector<int> vec;
        vec.push_back(B[i]);
        vec.push_back(A[i]);
        problems.push_back(vec);
    }

    std::sort(problems.begin(),problems.end());

    // B의 오름차순으로 정렬했을 때 첫문제는 A 꺼 
    // (B가 자신이 없으므로 어떤 선택지를 내놓아도 고르지 않음)
    long long ans = problems[0][1]; 

    std::priority_queue<int> q;

    // 어차피 문제를 반반씩 가져가므로 N/2-1번 루프
    // 1문제는 위에서 가져감

    for(int i = 1; i < N/2; i++){
        // 2문제씩 나눠서 큐에 삽입
        q.push(problems[2*i-1][1]);
        q.push(problems[2*i][1]);

        // max큐이므로 자동으로 나에게 가장 유리한 문제 선정됨
        // 2 ~ 2i 까지의 문제들 중 가장 A값이 큰 문제를 고름
        ans += q.top();
        q.pop();
    }

    std::cout << ans << '\n';

    return 0;
}