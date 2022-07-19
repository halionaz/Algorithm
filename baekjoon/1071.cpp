// 소트
// 우선순위 큐 & 그리디 알고리즘

#include <iostream>
#include <queue>

// N :: 숫자 개수
// num :: 숫자 종류 개수
int N, num = 0;
int cnt[1001] = {0};
std::priority_queue<int, std::vector<int>, std::greater<int> > min_que;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    int inp;
    for(int i = 0; i < N; i++){
        std::cin >> inp;
        if(!cnt[inp]){
            num++;
        }
        cnt[inp]++;
    }

    // 한 종류만 있을 경우 다 출력
    if(num == 1){
        while(N--){
            std::cout << inp << ' ';
        }
        std::cout << '\n';
        return 0;
    }

    // 일단 순서대로 (작은 애를 앞으로) 우선순위 큐에 삽입 (종류 별로 한번씩)
    for(int i = 0; i <= 1000; i++){
        if(cnt[i]){
            min_que.push(i);
        }
    }


    int prev = -2;

    while(min_que.size() > 2){
        int cur = min_que.top();
        min_que.pop();
        if(prev + 1 == cur){
            // 그 전 수와 연속한다면
            // 현재 수를 뛰어넘어 그 다음 작은 수를 먼저 출력
            std::cout << min_que.top() << ' ';
            prev = min_que.top();
            if(--cnt[min_que.top()] == 0){
                min_que.pop();
            }
            min_que.push(cur);
        } else {
            // 연속하지 않다면 현재 수 모두 출력
            while(cnt[cur]){
                std::cout << cur << ' ';
                cnt[cur]--;
            }
            prev = cur;
        }
    }

    // 큐에 남아있는 수 출력 (두 종류만 남아있음)

    int cur = min_que.top();
    min_que.pop();
    if(cur + 1 == min_que.top()){
        // 연속한다면, 역순으로
        while(cnt[min_que.top()]--){
            std::cout << min_que.top() << " ";
        }
        while(cnt[cur]--){
            std::cout << cur << " ";
        }
    } else {
        // 연속하지 않는다면
        if(prev + 1 == cur){
            // 그 전수랑 현재 수랑 연속한다면, 그 다음수를 한번만 일단 출력함
            std::cout << min_que.top() << " ";
            cnt[min_que.top()]--;
        }
        // 현재 수 모두 출력
        while(cnt[cur]--){
            std::cout << cur << " ";
        }
        // 그 다음 수 모두 출력
        while(cnt[min_que.top()]--){
            std::cout << min_que.top() << " ";
        }
    }

    std::cout << '\n';

    return 0;
}