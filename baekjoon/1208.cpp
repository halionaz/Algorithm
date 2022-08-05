// 부분수열의 합 2
// 이분 탐색 & 중간에서 만나기

// 생각하기 꽤 힘든 문제
// meet in the middle 알고리즘 사용
// 완전 탐색을 진행하면 2^40만큼 걸리므로 시간 무조건 초과

// 따라서 앞과 뒤를 완전 탐색을 진행하여 2^20 ≈ 100,0000 소요시키고
// 뒷부분 부분 수열에 대해 앞부분에 들어맞는 경우가 있는지 확인

// 1450, 냅색문제와 유사한 풀이

#include <iostream>
#include <map>

int N, S;
int arr[40];
std::map<int, int> mp; // mp[i] :: 배열의 앞쪽에서, 합이 i인 부분 수열의 개수
long long ans = 0;

void leftSum(int ind, int sum){
    if(ind == N/2){
        mp[sum] += 1;
    } else {
        leftSum(ind+1, sum); // ind를 포함 안하는 경우
        leftSum(ind+1, sum + arr[ind]); // ind가 포함된 경우
    }
}

void rightSum(int ind, int sum){
    if(ind == N){
        ans += mp[S-sum];
    } else {
        rightSum(ind+1, sum);
        rightSum(ind+1, sum + arr[ind]);
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> S;

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    leftSum(0,0);
    rightSum(N/2, 0);

    // 크기가 양수여야 하므로 아무 것도 선택하지 않은 합 0은 빼야 함
    if(S == 0){
        ans -= 1;
    }

    std::cout << ans << '\n';

    return 0;
}