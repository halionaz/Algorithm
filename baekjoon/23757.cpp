// 아이들과 선물 상자
// 우선순위 큐

#include <iostream>
#include <algorithm>
#include <queue>

int N, M;
int present[100001];
int greedy[100001];
std::priority_queue<int> que;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < N; i++){
        int inp;
        std::cin >> inp;
        que.push(inp);
    }
    for(int i = 0; i < M; i++){
        std::cin >> greedy[i];
    }

    for(int i = 0; i < M; i++){
        // i 번째 애 차례
        if(que.size() && que.top() >= greedy[i]){
            int val = que.top();
            que.pop();
            val -= greedy[i];
            if(val > 0){
                que.push(val);
            }
        } else {
            std::cout << 0 << '\n';
            return 0;
        }
    }
    std::cout << 1 << '\n';

    return 0;
}