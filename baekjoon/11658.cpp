// 구간 합 구하기 3
// 세그먼트 트리 & 다차원 세그먼트 트리 & 누적 합

// 펜윅 트리 이용

#include <iostream>

typedef long long ll;

int N, M;
int arr[1025][1025];
ll fenTree[1025][1025];

void updateTree(int x, int y, ll val){
    while(x <= N){
        int ty = y;
        while(ty <= N){
            fenTree[x][ty] = fenTree[x][ty] + val;
            ty = ty + (ty & -ty);
        }
        x = x + (x & -x);
    }
}

ll query(int x, int y){
    ll ret = 0;
    while(x){
        int ty = y;
        while(ty){
            ret += fenTree[x][ty];
            ty = ty - (ty & -ty);
        }
        x = x - (x & -x);
    }
    return ret;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            std::cin >> arr[i][j];
            updateTree(i, j, arr[i][j]);
        }
    }

    while(M--){
        int ord;
        std::cin >> ord;
        if(ord){
            int x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            std::cout << query(x2,y2) - query(x2, y1 -1) - query(x1 - 1, y2) + query(x1-1, y1-1) << '\n';
        } else {
            int x, y, c;
            std::cin >> x >> y >> c;
            updateTree(x, y, c - arr[x][y]);
            arr[x][y] = c;
        }
    }

    return 0;
}