// 들쥐의 탈출
// 이분 매칭

#include <iostream>
#include <utility>
#include <vector>
#include <string.h>
#include <math.h>

typedef std::pair<double, double> loc;

int N, M, S, V;
double x, y;
loc rats[101];
loc tunnels[101];
std::vector<int> line[101];
bool doneMatch[101];
int whoseIn[101];

double dist(loc A, loc B){
    // A와 B 사이의 거리를 구하는 함수
    return sqrt((A.first-B.first)*(A.first-B.first) + (A.second-B.second)*(A.second-B.second));
}

bool dfs(int rat){
    for(int i = 0; i < line[rat].size(); i++){
        int T = line[rat][i];

        if(!doneMatch[T]){
            doneMatch[T] = true;
            if(whoseIn[T] == 0 || dfs(whoseIn[T])){
                whoseIn[T] = rat;
                return true;
            }
        }
    }

    return false;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M >> S >> V;

    for(int i = 1; i <= N; i++){
        std::cin >> rats[i].first >> rats[i].second;
    }
    for(int i = 1; i <= M; i++){
        std::cin >> tunnels[i].first >> tunnels[i].second;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            // i번 쥐가 j번 터널을 사용할 수 있는가?
            double d = dist(rats[i], tunnels[j]);
            if(d <= (double)S*V){
                line[i].push_back(j);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++){
        memset(doneMatch, 0, sizeof(doneMatch));
        if(dfs(i)){
            ans += 1;
        }
    }

    std::cout << N - ans << '\n';

    return 0;
}