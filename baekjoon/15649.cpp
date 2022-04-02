// N과 M (1)
// 백트래킹

#include <iostream>

void dfs(int N,int M,int depth,int *arr,int *visited){
    if(depth == M){
        for(size_t i = 0; i < M; i++){
            std::cout<<arr[i]<<' ';
        }
        std::cout<<'\n';
    } else {
        for(int i = 0; i<N; i++){
            if(!visited[i]){
                visited[i] = 1;
                arr[depth] = i+1;
                dfs(N,M,depth+1,arr,visited);
                visited[i] = 0;
            }
        }
    }
}

int main(){
    int N,M;
    std::cin >> N >> M;
    int visited[N];
    for(int i = 0; i < N; i++){
        visited[i] = 0;
    }
    int arr[M];
    dfs(N,M,0,arr,visited);
    return 0;
}
