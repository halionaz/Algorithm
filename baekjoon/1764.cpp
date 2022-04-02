// 듣보잡
// 정렬 & 이분 탐색

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int N,M;
    std::cin>>N>>M;
    std::vector<std::string> noneHeard;
    std::vector<std::string> ans;
    noneHeard.resize(N);
    for(int i = 0; i < N; i++){
        std::cin >> noneHeard[i];
    }
    std::sort(noneHeard.begin(),noneHeard.end());
    std::string inp;
    for(int i = 0; i < M; i++){
        std::cin >> inp;
        if(std::binary_search(noneHeard.begin(),noneHeard.end(),inp)){
            ans.push_back(inp);
        }
    }
    std::sort(ans.begin(),ans.end());
    std::cout<<ans.size()<<'\n';
    for(int i = 0; i < ans.size(); i++){
        std::cout<<ans[i]<<'\n';
    }
    return 0;
}