// 수상 택시
// 스위핑 

// 시작점보다 끝점이 앞에 있는 택시 주문만 받음
// 시작점이 끝점보다 앞에 있는 친구들은 결국 0->M까지의 여정 중에 내리게 되기 때문

// 결국 역방향 택시 승객을 모두 태운 후, 
// 역방향 주문을 모두 처리하고 (왔던 방향을 거슬러서 감)
// 다시 M으로 돌아오면 그것이 답

// 즉 역방향 택시 주문들의 연결선들을 구하면 답을 구할 수 있음

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int N;
ll M, ans = 0, start, end;
std::vector<std::vector<ll> > arr;

int main(){
    
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < N; i++){
        ll x,y;
        std::vector<ll> vec;
        std::cin >> x >> y;
        if(x > y){
            // x < y인 경우는 받을 필요가 없음
            // 그냥 0 -> M으로 가는 길에 내려주면 됨
            vec.push_back(y);
            vec.push_back(x);
            arr.push_back(vec);
        }
    }

    std::sort(arr.begin(),arr.end());

    start = arr[0][0];
    end = arr[0][1];

    for(int i = 1; i < arr.size(); i++){
        if(arr[i][0] <= end){
            if(arr[i][1] > end){
                end = arr[i][1];
            }
        } else {
            ans += end - start;
            start = arr[i][0];
            end = arr[i][1];
        }
    }
    ans += end - start;

    std::cout << M + 2*ans << '\n';
    
    return 0;
}