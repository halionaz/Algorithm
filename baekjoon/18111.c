// 마인크래프트
// 브루트포스 알고리즘

#include <stdio.h>
#include <limits.h>

int main(void){
    int N,M,B;
    scanf("%d %d %d",&N,&M,&B);
    int world[N][M];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d",&world[i][j]);
        }
    }
    int ansH = 0;
    int ansT = INT_MAX;
    for(int i = 0; i < 257; i++){
        int inven = B;
        int time = 0;
        for(int x = 0; x < N; x++){
            for(int y = 0; y < M; y++){
                if(i<world[x][y]){
                    inven += world[x][y] - i;
                    time += 2*(world[x][y] - i);
                } else if (world[x][y]<i){
                    inven -= i-world[x][y];
                    time += i-world[x][y];
                }
            }
        }
        if( inven > -1 && time <= ansT){
            ansT = time;
            ansH = i;
        }
    }
    printf("%d %d\n",ansT,ansH);
    return 0;
}