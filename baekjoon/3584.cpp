// 가장 가까운 공통 조상
// 최소 공통 조상 

// 본격적인 sparse table을 이용한 최소 공통 조상을 풀기 전 그 원리를 탐구해보는 문제
// 수가 크지 않아 로그 스케일의 sparse table 이용 불필요

#include <iostream>
#include <cstring>
int T,N;
int parent[10001];

int getDepth(int n){
    int depth = 0;
    int cur = n;
    while(cur != 0){
        // 부모가 0이면 그 노드가 root임
        depth++;
        cur = parent[cur];
    }
    return depth;
}

int main(){

    std::cin >> T;

    while(T--){

        std::cin >> N;
        memset(parent,0,sizeof(parent));

        for(int i = 0; i < N-1; i++){
            int a,b;
            std::cin >> a >> b;
            parent[b] = a;
        }

        int A, B;
        std::cin >> A >> B;

        int aDepth = getDepth(A), bDepth = getDepth(B);
        if(aDepth > bDepth){
            while(aDepth != bDepth){
                aDepth--;
                A = parent[A];
            }
        } else if(bDepth > aDepth){
            while(aDepth != bDepth){
                bDepth--;
                B = parent[B];
            }
        }
        while(A != B){
            A = parent[A];
            B = parent[B];
        }
        std::cout << A << '\n';
    }
    return 0;
}