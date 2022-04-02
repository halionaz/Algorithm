// 힙 정렬
// 그리디 알고리즘

#include <iostream>

int N;
int arr[100001];

void swap(int a, int b){
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    arr[1] = 1;
    
    for(int i = 2; i <= N; i++){
        arr[i] = i;

        swap(i - 1, i);

        for(int j = i - 1; j > 1; j/=2){
            swap(j, j/2);
        }
    }

    for(int i = 1; i <= N; i++){
        std::cout << arr[i] << ' ';
    }

    std::cout << '\n';

    return 0;
}