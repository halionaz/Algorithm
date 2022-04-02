// 돌 던지기
// 시뮬레이션

#include <iostream>
#include <stack>

std::stack<int> d[30]; // int 스택에 좌표를 저장해야 하므로, x,y 좌표를 y * M + x 로 저장해준다.
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

		d[idx].push(y * M + x);

		if(y != N - 1 && Map[y + 1][x] == 'X'){
            return;
        }else if(y != N - 1 && Map[y + 1][x] == 'O'){
			if(x > 0 && Map[y][x-1] == '.' && Map[y+1][x-1] == '.'){
                x--;
            }else if(x < M - 1 && Map[y][x+1] == '.' && Map[y+1][x+1] == '.'){
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

			d[idx].pop();
		}

		update(idx);

		c=d[idx].top();
		y=c/M,x=c%M;
		Map[y][x]='O';
		d[idx].pop();

	}

	for(int i = 0;i < N;i++){
        for(int j = 0; j < M; j++){
            std::cout<<Map[i][j];
        }
        std::cout << '\n';
    }
    
	return 0;
}