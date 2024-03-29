// Cows
// 볼록 껍질 & 다각형의 넓이
// ccw 알고리즘 & 그라함 스캔 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

typedef long long ll;

int N;
std::vector<std::vector<ll> > arr;
std::vector<std::vector<ll> > stack;

ll ccw(std::vector<ll> n1, std::vector<ll> n2, std::vector<ll> n3){
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
        // ccw가 0일 경우 좌표가 작은 순으로 나열
        return (n1[0] + n1[1]) < (n2[0] + n2[1]);
    }
}

int main(){

    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::cin >> N;

    if(N < 3){
        std::cout << 0 << '\n';
        return 0;
    }

    for(int i = 0; i < N; i++){
        int x, y;
        std::vector<ll> vec;
        std::cin >> x >> y;
        vec.push_back(x);
        vec.push_back(y);
        arr.push_back(vec);
    }

    std::sort(arr.begin(),arr.end(), cmp1);
    std::sort(arr.begin()+1, arr.end(), cmp2);

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

    stack.push_back(stack[0]);

    // 컨벡스 헐 만들기 done
    // 이제 울타리 내 넓이를 구하면 됨

    // ccw를 통해 삼각형의 넓이를 구할 수 있음

    // 볼록 다각형의 넓이는 여러개의 삼각형으로 다각형을 쪼갠 후 더해주면 됨
    // 따라서 한 점 P를 고정하고, 두 점 X와 Y를 계속 순회하면서 더해주면 됨

    ll size = 0;

    for(int i = 0; i < stack.size()-1; i++){
        // size += ccw(stack[0], stack[i], stack[i+1]) / 2;
        size += (stack[i][0]*stack[i+1][1] - stack[i][1]*stack[i+1][0]) / 2;
    } 

    std::cout << size/50 << '\n';
    
    return 0;
}