// 책 페이지
// 수학

// start가 0으로 끝나는 수고, end가 9로 끝나는 수라면 마지막 자리가 등장하는 개수를 구하긴 쉬움
// (end / 10) - (start / 10) + 1 만큼 등장함
// 예를 들어 10 ~ 39라면, 0~9가 3번 반복됨. 즉 (3 - 1) + 1번 반복되는 것임

// 10의 자리도 똑같은데
// 100 ~ 299라면, 우선 1의 자리 수는 0~9가 (29 - 10 + 1)번 반복되는 것이므로 20번 반복되고,
// 이후 10~29 구간에서 10의 자리수의 횟수를 구하면
// 0~9가 (2 - 1 + 1)번 반복되므로 2번 반복됨. 단 이건 10의 자리수를 계산한 것이므로 자릿수만큼 10을 곱해서 답에 더해줌

// 이 규칙을 이용해 start를 항상 0으로 맞춰놓고, end를 9로 맞춰놓은 후 자릿수 만큼 곱해주는 계산 반복

#include <iostream>

typedef long long ll;

ll start = 1;
ll end;
int point = 1; // 자릿수
int ans[10];

void cal(ll N, ll point){
    // N 숫자에서 등장하는 숫자들을 답에 더해주는 함수

    // point는 자릿수
    while(N > 0){
        ans[N % 10] += point;
        N /= 10;
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> end;

    while(start <= end){
        // 앞자리 0으로 맞추기
        while(start%10 != 0 && start <= end){
            cal(start, point);
            start += 1;
        }
        if(start > end){
            break;
        }
        // 끝자리 9로 맞추기
        while(end%10 != 9 && start <= end){
            cal(end, point);
            end -= 1;
        }

        // (end - start + 1)*자릿수 만큼 답에 더해줌
        start /= 10;
        end /= 10;

        for(int i = 0; i < 10; i++){
            ans[i] += point*(end - start + 1);
        }

        point *= 10;
    }

    for(int i = 0; i < 10; i++){
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}