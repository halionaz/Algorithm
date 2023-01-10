// N-Queen
// 백트래킹

#include <iostream>
#include <cstdlib>
#include <string.h>

int N, ans = 0;
int isFull[16];

bool promising(int depth, int i){
    // depth 열의 i행에 queen을 둘 수 있는지 판단
    for(int j = 0; j < N; j++){
        if(isFull[j] == i){
            return false;
        }
    }

    for(int j = 0; j < depth; j++){
        if(depth - j == std::abs(i - isFull[j])){
            return false;
        }
    }

    return true;
}

void putQueen(int depth){
    if(depth == N){
        ans += 1;
        return;
    }

    for(int i = 0; i < N; i++){
        if(promising(depth, i)){
            isFull[depth] = i;
            putQueen(depth + 1);
            isFull[depth] = -1;
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    memset(isFull, -1, sizeof(isFull));

    putQueen(0);

    std::cout << ans << '\n';
    
    return 0;

}