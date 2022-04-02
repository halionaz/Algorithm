// 소트
// 우선순위 큐 & 그리디 알고리즘

#include <iostream>
#include <queue>

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

            std::cout << min_que.top() << ' ';
            prev = min_que.top();
            if(--cnt[min_que.top()] == 0){
                min_que.pop();
            }
            min_que.push(cur);
        } else {
            while(cnt[cur]){
                std::cout << cur << ' ';
                cnt[cur]--;
            }
            prev = cur;
        }
    }

    int cur = min_que.top();
    min_que.pop();
    if(cur + 1 == min_que.top()){
        while(cnt[min_que.top()]--){
            std::cout << min_que.top() << " ";
        }
        while(cnt[cur]--){
            std::cout << cur << " ";
        }
    } else {
        if(prev + 1 == cur){
            std::cout << min_que.top() << " ";
            cnt[min_que.top()]--;
        }
        while(cnt[cur]--){
            std::cout << cur << " ";
        }
        while(cnt[min_que.top()]--){
            std::cout << min_que.top() << " ";
        }
    }

    std::cout << '\n';

    return 0;
}