// Convex Hull
// 기하학 & 볼록 껍질

// 컨벡스 헐 - 그라함 스캔 알고리즘 사용
// 복습 필요

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int N, ans = 0;
std::vector<std::vector<ll> > arr;
std::vector<std::vector<ll> > stack;

ll ccw(std::vector<ll> n1, std::vector<ll> n2, std::vector<ll> n3){
    return n1[0]*n2[1] + n2[0]*n3[1] + n3[0]*n1[1] - (n2[0]*n1[1] + n3[0]*n2[1] + n1[0]*n3[1]);
}

bool cmp1(std::vector<ll> n1, std::vector<ll> n2){
    if(n1[0] == n2[0]){
        return n1[1] < n2[1]; 
    } else {
        return n1[0] < n2[0];
    }
}

bool cmp2(std::vector<ll> n1, std::vector<ll> n2){
    ll cp = ccw(arr[0], n1, n2);
    if(cp){
        return cp > 0;
    } else {
        // ccw가 0일 경우 좌표가 작은 순으로 나열 :: 얘를 점에 따라 적절히 배열해야되는데 어캐하지?
        return (n1[0] - arr[0][0])*(n1[0] - arr[0][0]) + (n1[1] - arr[0][1])*(n1[1] - arr[0][1]) < (n2[0] - arr[0][0])*(n2[0] - arr[0][0]) + (n2[1]-arr[0][1])*(n2[1]-arr[0][1]);
    }
}

bool cmp3(std::vector<ll> n1, std::vector<ll> n2){
    return (n1[0] - arr[0][0])*(n1[0] - arr[0][0]) + (n1[1] - arr[0][1])*(n1[1] - arr[0][1]) > (n2[0] - arr[0][0])*(n2[0] - arr[0][0]) + (n2[1]-arr[0][1])*(n2[1]-arr[0][1]);
}

int main(){

    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        int x, y;
        char c;
        std::vector<ll> vec;
        std::cin >> x >> y >> c;
        if(c == 'Y'){
            ans++;
            vec.push_back(x);
            vec.push_back(y);
            arr.push_back(vec);
        }
    }

    std::sort(arr.begin(),arr.end(), cmp1);
    std::sort(arr.begin()+1, arr.end(), cmp2);
    std::vector<std::vector<ll> > extra;

    stack.push_back(arr[0]);

    for(int i = 1; i < ans; i++){
        while(stack.size() >= 2){
            std::vector<ll> n1 = stack.back();
            stack.pop_back();
            std::vector<ll> n2 = stack.back();
            if(ccw(n2,n1,arr[i]) >= 0){
                // ccw가 맞을때만 n1을 stack에 넣어준다
                stack.push_back(n1);
                break;
            }  else {
                extra.push_back(n1);
            }
        }
        stack.push_back(arr[i]);
    }

    std::sort(extra.begin(), extra.end(), cmp3);

    std::cout << ans << '\n';

    for(int i = 0; i < stack.size(); i++){
        std::cout << stack[i][0] << ' ' << stack[i][1] << '\n';
    }
    for(int i = 0; i < extra.size(); i++){
        std::cout << extra[i][0] << ' ' << extra[i][1] << '\n';
    }
    


    return 0;
}