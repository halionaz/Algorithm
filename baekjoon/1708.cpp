// 볼록 껍질
// 기하학 & 볼록 껍질
// ccw 알고리즘 & 그라함 스캔 알고리즘

// 컨벡스 헐 - 그라함 스캔을 사용하는 기초 문제

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

typedef long long ll;

int N;
std::vector<std::vector<ll> > arr;
std::vector<std::vector<ll> > stack;

ll ccw(std::vector<ll> n1, std::vector<ll> n2, std::vector<ll> n3){
    // n1 -> n2 -> n3의 방향성 판별
    // 양수 : 반시계 방향
    // 0 : 직선
    // 음수 : 시계 방향
    // (n2[0]-n1[0])*(n3[1]-n1[1]) - (n3[0]-n1[0])*(n2[1]-n1[1])
    return n1[0]*n2[1] + n2[0]*n3[1] + n3[0]*n1[1] - (n2[0]*n1[1] + n3[0]*n2[1] + n1[0]*n3[1]);
}

bool cmp1(std::vector<ll> n1, std::vector<ll> n2){
    if(n1[1] == n2[1]){
        return n1[0] < n2[0];
    } else {
        return n1[1] < n2[1];
    }
}

bool cmp2(std::vector<ll> n1, std::vector<ll> n2){
    ll cp = ccw(arr[0], n1, n2);
    if(cp){
        return cp > 0;
    } else {
        // ccw가 0일 경우 (직선일 경우) 좌표가 작은 순으로 나열
        return std::abs(n1[0] + n1[1]) < std::abs(n2[0] + n2[1]);
    }
}

int main(){

    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        int x, y;
        std::vector<ll> vec;
        std::cin >> x >> y;
        vec.push_back(x);
        vec.push_back(y);
        arr.push_back(vec);
    }

    // 일단 y좌표와 x좌표가 작은 순으로 정렬해 기준 좌표를 만듦
    std::sort(arr.begin(),arr.end(), cmp1);
    // 기준 좌표를 제외한 나머지는 반시계 방향으로 정렬
    std::sort(arr.begin()+1, arr.end(), cmp2);

    // 스택에 두개의 점 넣고 시작
    stack.push_back(arr[0]);
    stack.push_back(arr[1]);

    for(int i = 2; i < N; i++){
        while(stack.size() >= 2){
            std::vector<ll> n1 = stack.back();
            stack.pop_back();
            std::vector<ll> n2 = stack.back();

            if(ccw(n2,n1,arr[i]) > 0){
                // ccw가 맞을때만 n1을 stack에 넣어준다

                stack.push_back(n1);
                break;
            }
        }

        stack.push_back(arr[i]);

    }

    std::cout << stack.size() << '\n';

    return 0;
}