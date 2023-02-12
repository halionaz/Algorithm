// 수 지우기
// 그리디 알고리즘

// 812348 이 있고, 8을 지울 수 있을 때, 가장 뒤에 있는 8을 지워야 되므로
// 뒤에서 부터 지우면 될 것 같음

// 근데 생각해보면 또 그렇진 않음
// 1932451 이 있고, 1을 지울 수 있을 땐, 193245보다 932451이 더 큼
// 따라서 큰 수는 뒤에 것을, 작은 수는 앞에 것을 지우는 것이 유리하다는 결론에 이름

// 이를 알고리즘으로 유사하게 옮겨보면
// 최종 수의 자릿수는 알고 있으므로, 최종 수를 앞에서 부터 채워나가고
// 큰 수부터 대입이 가능한지 체크하는 식으로 탐색해나감
// 큰 수를 넣기 위해 원래 수에서 지워야 하는 수가, 가능한 수준이라면 그 수를 넣고,
// 지울 수 없는 경우엔 그 다음 후보로 넘김

#include <iostream>
#include <string>

std::string firstNum, erase, ans;
int eraseNum[10] = {0,};
int num[10] = {0,};
int pointer = 0;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> firstNum;
    std::cin >> erase;

    for(int i = 0; i < firstNum.length(); i++){
        num[firstNum[i] - '0']++;
    }
    for(int i = 0; i < erase.length(); i++){
        eraseNum[erase[i] - '0']++;
        num[erase[i] - '0']--;
    }
    // eraseNum에는 지워져야 하는 숫자 정보가,
    // num에는 최종 숫자에 들어가야 하는 숫자 정보가 저장되어 있음

    for(int i = 0; i < firstNum.length() - erase.length(); i++){
        for(int cand = 9; cand >= 0; cand--){
            // 큰 수부터 후보로 탐색함
            if(num[cand] != 0){
                // cand가 최종 숫자에 들어갈 수 있음

                // cand가 들어가기 위해 지워져야 하는 숫자 개수 카운팅
                int count[10] = {0,};
                for(int j = pointer; firstNum[j] - '0' != cand; j++){
                    count[firstNum[j] - '0']++;
                }

                bool canDo = true;
                for(int i = 0; i < 10; i++){
                    if(count[i] > eraseNum[i]){
                        // 지워져야 하는 숫자 개수가, 지울 수 있는 숫자보다 많다면 불가능함
                        canDo = false;
                        break;
                    }
                }

                if(canDo){
                    // cand가 이번 자리에 들어갈 수 있음
                    num[cand]--;
                    for(; firstNum[pointer] - '0' != cand; pointer++){
                        // pointer 위치 이동
                        eraseNum[firstNum[pointer] - '0']--;
                    }
                    ans += cand + '0';
                    pointer += 1;
                    break;
                }
            }
        }
    }

    std::cout << ans << '\n';

    return 0;
}