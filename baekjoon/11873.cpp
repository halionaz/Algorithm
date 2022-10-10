// 최대 직사각형
// 스택

// 6549의 스택 풀이에서 영감을 받음

#include <iostream>
#include <stack>
#include <algorithm>

int N, M;
bool arr[1001][1001];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(true){

        std::cin >> N >> M;

        if(N == 0 && M == 0){
            break;
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                std::cin >> arr[i][j];
            }
        }

        int ans = 0;
        std::stack<int> stck;
        int height[1001] ={0,}; // 이거 초기화 안해서 계속 틀렸음... 왜 반복문마다 고유한 height 배열 선언이 안되는거지? 0으로 초기화가 자동으로 안됨

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){

                if(arr[i][j]){
                    // 현재 칸이 1이라면
                    // j열의 연속된 1 개수 갱신
                    height[j] += 1;
                } else {
                    height[j] = 0;
                }

                while(!stck.empty() && height[j] <= height[stck.top()]){
                
                    // 스택에 쌓여있는 이전 높이보다 현 열의 높이가 짧을 경우
                    // 현 높이보다 큰 스택에 있는 높이들을 pop 해주면서 답을 갱신해줌

                    int lastMaxHeight = height[stck.top()];
                    stck.pop();

                    int width;
                    if(stck.empty()){
                        // 스택이 비어있다면, 현 높이가 지금까지 탐색한 부분에서 가장 짧은 높이인 것이므로
                        // 그냥 0 ~ j까지가 width가 됨
                        width = j;
                    } else {
                        // 스택이 비어있지 않으면,
                        // 그 스택 요소가 현 높이보다 짧으므로, 그 요소를 제외한 width를 구함
                        width = j - stck.top() - 1;
                    }

                    ans = std::max(ans, width * lastMaxHeight);

                }

                stck.push(j);

            }

            while(!stck.empty()){
                int lastMaxHeight = height[stck.top()];
                stck.pop();

                int width;
                if(stck.empty()){
                    width = M;
                } else {
                    width = M - stck.top() - 1;
                }

                ans = std::max(ans, width * lastMaxHeight);
            }

        }

        std::cout << ans << '\n';

    }

    return 0;
}