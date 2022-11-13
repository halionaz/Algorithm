// 돌 던지기
// 시뮬레이션 & 스택 & 다이나믹 프로그래밍

#include <iostream>
#include <stack>

// int 스택에 좌표를 저장해야 하므로, x,y 좌표를 y * M + x 로 저장해줌
// 스택은 그 인덱스에 돌을 놓았을 때, 돌이 부딪힐 좌표를 빠르게 알려주는 역할을 함
std::stack<int> d[30]; 
char Map[30000][30];
int N, M;

void update(int idx){

	int y = 0, x = idx;

	if(!d[idx].empty()){
		int cur = d[idx].top();
		x = cur % M; 
        y = cur / M;
	}

	while(y < N){

        // idx에 돌을 떨어뜨리면 (y,x)를 거침
		d[idx].push(y * M + x);

		if(y != N - 1 && Map[y + 1][x] == 'X'){
            // 아랫칸이 벽으로 막혀있다면
            return;
        }else if(y != N - 1 && Map[y + 1][x] == 'O'){
            // 아랫칸이 돌이라면
			if(x > 0 && Map[y][x-1] == '.' && Map[y+1][x-1] == '.'){
                // 왼쪽이 비어있고, 왼쪽 아래도 비어있다면
                // 왼쪽으로 미끄러짐
                x--;
            }else if(x < M - 1 && Map[y][x+1] == '.' && Map[y+1][x+1] == '.'){
                // 오른쪽이 비어있고, 오른쪽 아래도 비어있다면
                // 오른쪽으로 미끄러짐
                x++;
            }else{
                return;   
            }
		}
		y++;
	}
}

int main(){

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> N >> M;

	for(int i = 0; i < N;i++){
        for(int j = 0; j < M; j++){
            std::cin >> Map[i][j];
        }
    }

	int q; 
    
    std::cin >> q;

	while(q--){
		int idx; 
        std:: cin >> idx; 
        --idx;

		int c,y,x;

		while(true){

			if(d[idx].empty()){
                break;
            }

			c = d[idx].top();

			y = c/M, x = c%M;

			if(Map[y][x]=='.'){
                break;
            }

            // update 과정에서 들어찬 쓸데 없는 스택 요소 뺌으로써
            // 바로 분기점에서 시뮬레이션을 시작할 수 있도록 함
			d[idx].pop();
		}

		update(idx);

		c = d[idx].top(); // 결과적으로 그 인덱스에 떨어뜨렸을 때, 도착하는 지점
		y = c/M, x = c%M;
		Map[y][x] = 'O';
		d[idx].pop(); // 이제 여긴 들어찬 좌표이므로, 분기점에서 빼 줌

	}

	for(int i = 0;i < N;i++){
        for(int j = 0; j < M; j++){
            std::cout<<Map[i][j];
        }
        std::cout << '\n';
    }
    
	return 0;
}