// 단순 다각형
// 볼록 껍질
// ccw 알고리즘 & 그라함 스캔 알고리즘

// 어차피 아무 다각형이나 만들어도 되므로 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

typedef long long ll;

int C, N;
std::vector<std::vector<ll> > arr;

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

ll distance(std::vector<ll> n1, std::vector<ll> n2){
    ll dx = n1[0] - n2[0];
    ll dy = n1[1] - n2[1];
    return dx*dx + dy*dy;
}

bool cmp2(std::vector<ll> n1, std::vector<ll> n2){
    ll cp = ccw(arr[0], n1, n2);
    if(cp){
        return cp > 0;
    } else {
        // ccw가 0일 경우 좌표가 작은 순으로 나열
        return distance(arr[0],n1) < distance(arr[0],n2);
    }
}


int main(){

    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::cin >> C;

    while(C--){

        arr.clear();
        
        std::cin >> N;

        for(int i = 0; i < N; i++){
            std::vector<ll> vec(3);
            std::cin >> vec[0] >> vec[1];
            vec[2] = i;
            arr.push_back(vec);
        }

        std::sort(arr.begin(),arr.end(), cmp1); // 기준점 정하기
        std::sort(arr.begin()+1, arr.end(), cmp2); // 첫 점 기준 반시계방향으로 정렬

        int j = arr.size() - 1;

        // 첫번째 점 - j번째 점 - j-1번째 점이 직선을 이루는
        // 맨 뒤에 X개의 점들은 거리가 먼 순서로 배열
        for(int i = arr.size() - 1; i >= 1; i--){
            if(ccw(arr[0], arr[j], arr[j-1]) == 0){
                j--;
            } else {
                break;
            }
        }

        std::reverse(arr.begin() + j, arr.end());

        for(int i = 0; i < arr.size(); i++){
            std::cout << arr[i][2] << ' ';
        }

        std::cout << '\n';
    }


    return 0;
}