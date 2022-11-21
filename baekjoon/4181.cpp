// Convex Hull
// 기하학 & 볼록 껍질
// 그라함 스캔 알고리즘

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
        // ccw가 0일 경우 좌표가 기준점과 가까운 순으로 나열 :: 얘를 점에 따라 적절히 배열해야되는데 어캐하지?
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
            // 볼록껍질에 속하는 노드만 저장
            ans++;
            vec.push_back(x);
            vec.push_back(y);
            arr.push_back(vec);
        }
    }

    // 좌표값 기준으로 정렬, 기준점 선택
    std::sort(arr.begin(),arr.end(), cmp1);
    // 기준점 기준으로 반시계 방향으로 정렬, 만약 직선을 이룬다면 좌표가 가까운 것이 앞에 오게끔
    std::sort(arr.begin()+1, arr.end(), cmp2);
    
    std::vector<std::vector<ll> > extra;

    // 시작점으로 돌아오는 부분에서의 평행선 순서 처리를 위해 컨벡스 헐 탐색
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

    // 처음에 반시계방향으로 정렬할 때 수직선 상에 있는 점은 가까운 순서대로 정렬했지만,
    // 시작점으로 돌아오는 쪽에서 수직선 상에 놓이게 되면 먼 노드가 먼저 출력되어야 함
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