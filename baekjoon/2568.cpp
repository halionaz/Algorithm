// 전깃줄 - 2
// 가장 긴 증가하는 부분 수열: o(n log n)

// LIS

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int N;
int inpArr[500001];
std::vector<int> Aarr;
std::vector<int> arr;
std::vector<int> LIS;
std::vector<int> indArr;
std::set<int> ans;
std::vector<int> realAns;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    
    for(int i = 0; i < N; i++){
        int x,y;
        std::cin >> x >> y;
        inpArr[x] = y;
    }

    for(int i = 1; i < 500001; i++){
        if(inpArr[i]){
            Aarr.push_back(i);
            arr.push_back(inpArr[i]);
        }
    }

    int length;

    for(int i = 0; i < N; i++){
        length = LIS.size();
        if(length){
            if(LIS[length-1] < arr[i]){
                LIS.push_back(arr[i]);
                indArr.push_back(length);
            } else {
                int ind = std::lower_bound(LIS.begin(),LIS.end(),arr[i])-LIS.begin();
                indArr.push_back(ind);
                LIS[ind] = arr[i];
            }
        } else {
            LIS.push_back(arr[i]);
            indArr.push_back(0);
        }
    }

    int answer = N - LIS.size();

    std::cout << answer << '\n';

    int cnt = LIS.size() - 1;
    int ind = N-1;

    while(cnt > -1){
        if(indArr[ind] == cnt){
            cnt--;
            ans.insert(arr[ind]);
            ind--;
        } else {
            ind--;
        }
    }
    for(int i = 0; i < N; i++){
        if(!ans.count(inpArr[Aarr[i]])){
            realAns.push_back(Aarr[i]);
        }
    }
    std::sort(Aarr.begin(),Aarr.end());
    for(int i = 0; i < answer; i++){
        std::cout << realAns[i] << '\n';
    }

    return 0;
}