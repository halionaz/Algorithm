// 색종이 붙이기
// 백트래킹 & 브루트포스 알고리즘

#include <iostream>
#include <algorithm>

const int inf = 987654321;

int map[10][10];
int paper[6] = { 0, 5, 5, 5, 5, 5 };
int res = inf;

void dfs(int y, int x, int cnt) {

	if (cnt > res){
        // 이미 cnt가 그 전 답을 넘겨버렸으니
        // 계산 포기
        return;
    }
    
	if (y == 10) {
        // 끝까지 돌았으므로 답 갱신
		res = std::min(res, cnt);
		return;
	}

	if (x == 10) {
	    // 다음줄
		dfs(y + 1, 0, cnt);
		return;
	}

	// 0이면 넘어감
	if (map[y][x] == 0) {
		dfs(y, x + 1, cnt);
	}

	// 크기 별로 재귀 돌려줌, 큰거부터 해야 최솟값 갱신 가능
	for (int size = 5; size >= 1; size--) {

		if (y + size > 10 || x + size > 10 || paper[size] == 0){
            continue;
        }

		bool canStck = true;

		// 붙일 수 있는 여부 확인
		for (int i = y; i < y + size; ++i) {
			for (int j = x; j < x + size; ++j)
				if (map[i][j] == 0) {
                    // 중간에 0이 끼어있다면 불가능
					canStck = false;
					break;
				}
			if (!canStck){
                break;
            };
		}

		if (!canStck){
            continue;
        };

		for (int i = y; i < y + size; ++i){
			for (int j = x; j < x + size; ++j){
				map[i][j] = 0;
                // 붙였으므로 0으로 설정
            }
        }
        
		paper[size]--;
		dfs(y, x + size, cnt + 1);
        
		for (int i = y; i < y + size; ++i){
			for (int j = x; j < x + size; ++j){
				map[i][j] = 1;
                // 다시 붙이기 전으로 회귀
            }
        }
		paper[size]++;
	}
}


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	for (int i = 0; i < 10; ++i){
		for (int j = 0; j < 10; ++j){
			std::cin >> map[i][j];   
        }
    }

	dfs(0, 0, 0);

	if (res == inf){
        res = -1;
    }
	std::cout << res << '\n';

	return 0;
}