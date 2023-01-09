// 디지털 비디오 디스크(DVDs)
// 세그먼트 트리

// 최솟값, 최댓값 세그먼트 트리

// i ~ j 구간의 DVD 최솟값이 i이고 최댓값이 j라면
// 무조건 그 구간에는 손님이 원하는 DVD가 전부 존재한다고 봐도 됨
// 진상 손님이 DVD를 빼가는 것이 아닌 이상 i ~ j 구간에는 그 숫자 만큼의 DVD가 있고
// 최솟값과 최댓값이 각각 i와 j라는 것은 i ~ j의 DVD가 그 구간에 있다는 것임

#include <iostream>
#include <vector>
#include <cmath>

int T, N, K;
int arr[100000];
std::vector<int> maxTree;
std::vector<int> minTree;

int max(int a, int b){
    return a > b ? a : b;
}
int min(int a, int b){
    return a < b ? a : b;
}

int makeMaxTree(int node, int s, int e){
    if(s == e){
        return maxTree[node] = arr[s] = s;
    } else {
        int mid = (s + e) / 2;
        int left = makeMaxTree(node*2,s,mid);
        int right = makeMaxTree(node*2+1,mid+1,e);
        return maxTree[node] = max(left,right);
    }
}
int makeMinTree(int node, int s, int e){
    if(s == e){
        return minTree[node] = s;
    } else {
        int mid = (s+e) / 2;
        int left = makeMinTree(node*2,s,mid);
        int right = makeMinTree(node*2+1,mid+1,e);
        return minTree[node] = min(left,right);
    }
}

int searchMax(int node, int s, int e, int l, int r){
    if(l > e || r < s){
        return -1;
    }
    if(l <= s && e <= r){
        return maxTree[node];
    }
    int mid = (s+e)/2;
    int left = searchMax(node*2,s,mid,l,r);
    int right = searchMax(node*2+1,mid+1,e,l,r);
    return max(left,right);
}
int searchMin(int node, int s, int e, int l, int r){
    if(l > e || r < s){
        return 100001;
    }
    if(l <= s && e <= r){
        return minTree[node];
    }
    int mid = (s+e)/2;
    int left = searchMin(node*2,s,mid,l,r);
    int right = searchMin(node*2+1,mid+1,e,l,r);
    return min(left,right);
}

int updateMax(int node, int s, int e, int ind){
    if(ind < s || e < ind){
        return maxTree[node];
    } else {
        if(s == e){
            return maxTree[node] = arr[ind];
        } else {
            int mid = (s+e) / 2;
            return maxTree[node] = max(updateMax(node*2,s,mid,ind),updateMax(node*2+1,mid+1,e,ind));
        }
    }
}
int updateMin(int node, int s, int e, int ind){
    if(ind < s || e < ind){
        return minTree[node];
    } else {
        if(s == e){
            return minTree[node] = arr[ind];
        } else {
            int mid = (s+e) / 2;
            return minTree[node] = min(updateMin(node*2,s,mid,ind),updateMin(node*2+1,mid+1,e,ind));
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){
        maxTree.clear();
        minTree.clear();

        std::cin >> N >> K;

        int height = (int)std::ceil(std::log2(N));
        int size = (1 << (height+1));
        maxTree.resize(size);
        minTree.resize(size);

        makeMaxTree(1,0,N-1);
        makeMinTree(1,0,N-1);

        for(int i = 0; i < K; i++){
            int q,a,b;
            std::cin >> q >> a >> b;
            if(q){ // 위치 확인
                int maximum = searchMax(1,0,N-1,a,b);
                int minimum = searchMin(1,0,N-1,a,b);
                if(minimum == a && maximum == b){
                    std::cout << "YES" << '\n';
                } else {
                    std::cout << "NO" << '\n';
                }
            } else { // 진상 손님
                int tmp = arr[a];
                arr[a] = arr[b];
                arr[b] = tmp;
                updateMax(1,0,N-1,a);
                updateMax(1,0,N-1,b);
                updateMin(1,0,N-1,a);
                updateMin(1,0,N-1,b);
            }
        }

    }

    return 0;
}