// 여우가 정보섬에 올라온 이유
// 세그먼트 트리 & 스위핑

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

const int max = 200000;
const long long mod = 1e9 + 7;

int N, x, y;
long long ans = 0;
std::pair<int,int> arr[max+1];
std::vector<long long> segTree;

// Y 내림차순, X 오름차순
bool compare(std::pair<int,int> a, std::pair<int,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

long long updateTree(int node, int s, int e, int ind){
    if(ind < s || e < ind){
        return segTree[node];
    } else {
        if(s == e){
            return segTree[node] += 1;
        } else {
            int mid = (s+e)/2;
            return segTree[node] = (updateTree(node*2,s,mid,ind) + updateTree(node*2+1,mid+1,e,ind))%mod;
        }
    }

}
long long searchTree(int node, int s, int e, int l, int r){
    if(e < l || r < s){
        return 0;
    } else {
        if(l <= s && e <= r){
            return segTree[node];
        } else {
            int mid = (s+e)/2;
            return (searchTree(node*2,s,mid,l,r) + searchTree(node*2+1,mid+1,e,l,r))%mod;
        }
    }
}

int main(){
    int height = (int)std::ceil(std::log2(max*2+1));
    int size = (1 << (height+1));
    segTree.resize(size);

    scanf("%d",&N);

    for(int i = 0; i < N; i++){
        scanf("%d%d",&x,&y);
        arr[i] = std::make_pair(x+max,y);
        // 탐색을 용이하게 하기 위해 x값에는 max값을 더해 양수로 만들어줌
    }

    std::sort(arr,arr+N, compare);
    // y좌표 내림차순으로, x좌표 오름차순으로 정렬

    int prevY = arr[0].second;
    std::vector<int> cash;
    // y값이 같은 경우를 세지 않도록, y값은 바뀔 때 세그먼트 트리에 한번에 업데이트 해줌

    for(int i = 0; i < N; i++){

        // 만약 그 전 y값과 달라진다면, cash에 저장된 x들을 segTree에 업데이트
        if(prevY != arr[i].second){
            for(int j = 0; j < cash.size(); j++){
                updateTree(1,0,max*2,cash[j]);
            }
            cash.clear();
            prevY = arr[i].second;
        }
        if(0 < arr[i].first && arr[i].first < max*2){
            ans += (searchTree(1,0,max*2,0,arr[i].first-1)*searchTree(1,0,max*2,arr[i].first+1,max*2));
            ans %= mod;
        }
        cash.push_back(arr[i].first);
    }

    printf("%lld\n",ans);

    return 0;
}