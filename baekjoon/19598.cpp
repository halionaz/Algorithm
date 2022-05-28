// 최소 회의실 개수
// 그리디 알고리즘 & 스위핑 & 우선순위 큐

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

typedef long long ll;

int N, ans = 1;
std::vector<std::pair<ll, ll> > meetings;
std::priority_queue<int, std::vector<int>, std::greater<int> > q;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        ll s, e;
        std::cin >> s >> e;
        meetings.push_back(std::make_pair(s, e));
    }

    std::sort(meetings.begin(), meetings.end());

    // 큐에는 끝나는 시간이 저장됨
    q.push(meetings[0].second);

    for(int i = 1; i < N; i++){

        while(!q.empty() && q.top() <= meetings[i].first){
            // 만약 그 전에 시작한 회의의 끝나는 시간보다
            // 지금 회의의 시작시간이 뒤라면, 그 전은 끝낼 수 있으므로 pop
            q.pop();
        }
        q.push(meetings[i].second);
        ans = std::max(ans, (int)q.size());

    }

    std::cout << ans << '\n';

    return 0;
}