// 커트라인
// 우선순위 큐

#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int N, k, x, ans;
std::priority_queue<int, std::vector<int>, std::greater<int> > minQue;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> k;

    for(int i = 0; i < N; i++){

        std::cin >> x;

        if(minQue.size() < k){
            minQue.push(x);
        } else {
            if(minQue.top() < x){
                minQue.pop();
                minQue.push(x);
            }
        }
    }

    std::cout << minQue.top() << '\n';

    return 0;
}