// 화성 지도
// 스위핑 & 세그먼트 트리

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int N;
long long ans = 0;
std::vector<std::vector<int> > arr;
std::vector<int> cntTree; // cnt의 값 저장
std::vector<int> segTree; // cnt가 1 이상인 y 개수 저장

void updateTree(int node, int s, int e, int l, int r, int diff){
    if(r < s || e < l){
        return;
    } else {
        if(l <= s && e <= r){
            cntTree[node] += diff;
        } else {
            int mid = (s+e)/2;
            updateTree(node*2,s,mid,l,r,diff);
            updateTree(node*2+1,mid+1,e,l,r,diff);
        }

        if(cntTree[node]){
            segTree[node] = e - s + 1;
        } else {
            if(s == e){
                segTree[node] = 0;
            } else {
                segTree[node] = segTree[node*2] + segTree[node*2+1];
            }
        }
    }
}

// int query(int node, int )

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    int height = (int)std::ceil(std::log2(30005));
    int size = (1<<(height+1));
    cntTree.resize(size);
    segTree.resize(size);

    for(int i = 0; i < N; i++){
        std::vector<int> vec1, vec2;
        int x1,y1,x2,y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        vec1.push_back(x1);
        vec1.push_back(y1);
        vec1.push_back(y2);
        vec1.push_back(0);
        vec2.push_back(x2);
        vec2.push_back(y1);
        vec2.push_back(y2);
        vec2.push_back(1);
        arr.push_back(vec1);
        arr.push_back(vec2);
    }

    std::sort(arr.begin(),arr.end());

    for(int i = 0; i < arr.size(); i++){
        if(i){
            ans += (arr[i][0] - arr[i-1][0]) * segTree[1];
        }
        int diff = arr[i][3] ? -1 : 1;
        // int diff = 1;
        updateTree(1,0,30000,arr[i][1],arr[i][2]-1,diff);
    }

    std::cout << ans << '\n';

    return 0;
}