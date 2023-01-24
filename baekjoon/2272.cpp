// 램프
// 수학 & 애드 혹

// 문제를 수학적으로 단순화 시키면
// 0001 -> 0011 -> 0101 -> 1111 -> 0000 -> 0000 ->
// 즉 상태가 S일 때, 그 다음번은 S^(S << 1)이 됨

// 또, 2의 승수번째에서 램프의 모양은 다음과 같음
// K번째 (K는 2의 승수) 램프
// 1 0 0 0 ... (0이 K-1개) 1
// ex) 2번째 램프 1 0 1
// ex) 4번째 램프 1 0 0 0 1
// ex) 8번째 램프 1 0 0 0 0 0 0 0 1

// 2의 승수번째 램프는 2의 승수를 shift 한 후 XOR 연산을 한 것이고
// 2^30 ≒ 1,000,000,000을 이용해서 각 승수 30번 안에 문제를 해결함

// 정리하자면
// 주어진 램프 배열을 lamp[0..N-1]이라 할 때, 
// 이를 (1 << k)번만큼 shifting하면, 
// 귀납적으로 i번째 값은 lamp[i] ^ lamp[(i + (1 << k)) % N]가 됨
// 따라서 M을 2의 거듭제곱의 합으로 분해해서 답을 구함

#include <iostream>

int N, M;
int lamp[1000001];
int tmp[1000001];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < N; i++){
        std::cin >> lamp[i];
    }

    for(int i = 1; i <= M; i*=2){
        if(i & M){
            // 킹능성 on
            for(int j = 0; j < N; j++){
                // i만큼 비트 이동한 친구와 XOR 연산
                tmp[j] = lamp[j]^lamp[(i+j)%N];
            }
            for(int j = 0; j < N; j++){
                lamp[j] = tmp[j];
            }
        }
    }

    for(int i = 0; i < N; i++){
        std::cout << lamp[i] << '\n';
    }

    return 0;
}