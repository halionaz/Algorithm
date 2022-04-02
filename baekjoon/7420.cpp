// 맹독 방벽
// 볼록 껍질

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;

int N, L;
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

double dist(std::vector<ll> n1, std::vector<ll> n2){
    ll dx = n1[0] - n2[0];
    ll dy = n1[1] - n2[1];
    return std::sqrt(dx*dx + dy*dy);
}

bool cmp2(std::vector<ll> n1, std::vector<ll> n2){
    ll cp = ccw(arr[0], n1, n2);
    if(cp){
        return cp > 0;
    } else {
        // ccw가 0일 경우 좌표가 작은 순으로 나열
        return dist(arr[0],n1) < dist(arr[0], n2);
    }
}

int main(){

    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::cin >> N >> L;

    for(int i = 0; i < N; i++){
        ll x, y;
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

    int barrier = stack.size();

    double ans = 0;

    for(int i = 0; i < barrier; i++){
        std::vector<ll> prev = stack[(i+barrier-1)%barrier];
        std::vector<ll> cur = stack[i];
        std::vector<ll> next = stack[(i+1)%barrier];

        double dist1 = dist(cur,next);
        double dist2 = dist(prev,cur);
        ans += dist1;

        ll innerDot = (prev[0]-cur[0])*(next[0]-cur[0]) + (prev[1]-cur[1])*(next[1] - cur[1]);
        double angle = 3.1415926535 -  std::acos((double)innerDot / dist1 / dist2); // 180도에서 각 빼기
        ans += L * angle;
    }

    std::cout << std::round(ans) << '\n';

    return 0;
}