// 줄 세우기
// 위상 정렬

// 들어오는 선의 개수가 0인 애들 부터 큐에 넣어서
// bfs를 거쳐주고, 그 다음 들어오는 선의 개수가 0인 애들 탐색을 반복하면
// 위상 정렬이 이루어진다

#include <iostream>
#include <vector>
#include <queue>

int N,M;
int inputNum[32001];
std::vector<int> line[32001];

int main(){
    std::cin >> N >> M;
    int a,b;
    for(int i = 0; i < M; i++){
        std::cin >> a >> b;
        inputNum[b]++;
        line[a].push_back(b);
    }
    std::queue<int> q;
    for(int i = 1; i < N+1; i++){
        if(inputNum[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        std::cout << temp << ' ';
        for(int i = 0; i<line[temp].size(); i++){
            if(--inputNum[line[temp][i]] == 0){
                q.push(line[temp][i]);
            }
        }
    }
    std::cout << '\n';
    return 0;
}