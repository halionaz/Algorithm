// 문제집
// 위상 정렬 & 우선순위 큐

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

int N, M;
std::vector<int> order[32001];
int inputNum[32001];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(inputNum,0,sizeof(inputNum));

    std::cin >> N >> M;

    while(M--){
        int A,B;
        std::cin>>A>>B;
        inputNum[B]++;
        order[A].push_back(B);
    }

    // 1~N 오름차순 순으로 풀어야 하는 조건이 있으므로, 우선순위 큐 사용 
    std::priority_queue<int,std::vector<int>,std::greater<int> > q;
    std::vector<int> ans;

    for(int i = 1; i <= N; i++){
        if(!inputNum[i]){
            q.push(i);
        }
    }

    int temp,next;

    while(!q.empty()){
        temp = q.top();
        q.pop();
        ans.push_back(temp);
        for(int i = 0; i < order[temp].size(); i++){
            next = order[temp][i];
            if(--inputNum[next] == 0){
                q.push(next);
            }
        }
    }

    for(int i = 0; i < N; i++){
        std::cout << ans[i] << ' ';
    }
    
    std::cout << '\n';
    return 0;
}