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

        swap(i - 1, i); // 항상 i-1에 1이 위치해 있으므로, 1과 i를 바꿔줌

        for(int j = i - 1; j > 1; j/=2){
            swap(j, j/2); // 최대 힙을 만들어주는 과정
        }
    }

    for(int i = 1; i <= N; i++){
        std::cout << arr[i] << ' ';
    }

    std::cout << '\n';

    return 0;
}