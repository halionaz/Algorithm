// 이중 우선순위 큐
// 우선순위 큐

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cstring>

const int chunk =  1000001;
bool isActive[chunk];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int T,k;
    std::cin >> T;

    while(T--){
        std::priority_queue<std::pair<int,int> > maxQ;
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int, int> >,std::greater<std::pair<int, int> > > minQ;
        
        std::cin >> k;

        for(int i = 0; i < k; i++){
            char inp;
            int n;
            std::cin >> inp >> n;
            if(inp == 'I'){
                maxQ.push(std::make_pair(n,i));
                minQ.push(std::make_pair(n,i));
                isActive[i] = true;
            }else{
                if(n == 1){
                    // 최댓값 삭제
                    while(!maxQ.empty() && !isActive[maxQ.top().second]){
                        maxQ.pop();
                    }
                    if(!maxQ.empty()){
                        isActive[maxQ.top().second] = false;
                        maxQ.pop();
                    }
                } else {
                    // 최솟값 삭제
                    while(!minQ.empty() && !isActive[minQ.top().second]){
                        minQ.pop();
                    }
                    if(!minQ.empty()){
                        isActive[minQ.top().second] = false;
                        minQ.pop();
                    }
                }
            }
        }
        // 큐에서 밀린 연산 처리
        while(!minQ.empty() && !isActive[minQ.top().second]){
            minQ.pop();
        }
        while(!maxQ.empty() && !isActive[maxQ.top().second]){
            maxQ.pop();
        }
        if(minQ.empty()){
            std::cout << "EMPTY\n";
        } else {
            std::cout << maxQ.top().first <<' '<<minQ.top().first <<'\n';
        }
    }
    return 0;
}