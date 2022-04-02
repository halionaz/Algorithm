// 녹색 옷 입은 애가 젤다지?
// 다익스트라

// 그래프로 구현했던 다익스트라를 배열로 구현했던 문제

#include <iostream>
#include <queue>

const int inf = 987654321;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int N, ind = 0;
int cost[125][125];
int memo[125][125];
std::priority_queue<std::pair<int, std::pair<int, int> > > pq;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(true){
        ind++;

        std::cin >> N;

        if(!N){
            break;
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                memo[i][j] = inf;
                std::cin >> cost[i][j];
            }
        }

        memo[0][0] = cost[0][0];
        pq.push(std::make_pair(memo[0][0]*(-1), std::make_pair(0,0)));

        while(!pq.empty()){
            int curCost = pq.top().first * -1;
            std::pair<int,int> cur = pq.top().second;
            pq.pop();

            if(memo[cur.first][cur.second] < curCost){
                continue;
            }
            for(int i = 0; i < 4; i++){
                int nextX = cur.first + dx[i];
                int nextY = cur.second + dy[i];
                if(0 <= nextX && nextX < N && 0<= nextY && nextY < N){
                    int newCost = curCost + cost[nextX][nextY];
                    if(newCost < memo[nextX][nextY]){
                        memo[nextX][nextY] = newCost;
                        pq.push(std::make_pair(newCost * -1, std::make_pair(nextX, nextY)));
                    }
                }
            }

        }

        std::cout << "Problem " << ind << ": " << memo[N-1][N-1] << '\n';

    }

    return 0;
}