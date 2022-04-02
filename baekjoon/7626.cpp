// 직사각형 
// 스위핑 & 세그먼트 트리 & 값 / 좌표압축

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;

int N;
ll ans = 0;
std::vector<ll> yPosition;
std::vector<std::vector<int> > arr;
std::vector<int> cntTree;
std::vector<ll> segTree;

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
            segTree[node] = (ll)yPosition[e] - (ll)yPosition[s-1];
        } else {
            if(s == e){
                segTree[node] = 0;
            } else {
                segTree[node] = segTree[node*2] + segTree[node*2+1];
            }
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    int height = (int)std::ceil(std::log2(N*2+5));
    int size = (1 << (height+1));
    cntTree.resize(size);
    segTree.resize(size);

    for(int i = 0; i < N; i++){
        std::vector<int> vec1, vec2;
        int x1,y1,x2,y2;
        std::cin >> x1 >> x2 >> y1 >> y2;
        yPosition.push_back(y1);
        yPosition.push_back(y2);
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
    std::sort(yPosition.begin(),yPosition.end());
    yPosition.erase(std::unique(yPosition.begin(),yPosition.end()),yPosition.end());

    for(int i = 0; i < arr.size(); i++){
        if(i){
            ans += (arr[i][0] - arr[i-1][0]) * segTree[1];
        }
        int diff = arr[i][3] ? -1 : 1;
        int z1 = std::lower_bound(yPosition.begin(),yPosition.end(),arr[i][1]) - yPosition.begin();
        int z2 = std::lower_bound(yPosition.begin(),yPosition.end(),arr[i][2]) - yPosition.begin();
        updateTree(1, 0, N*2-1 , z1+1, z2, diff);
    }

    std::cout << ans << '\n';

    return 0;
}