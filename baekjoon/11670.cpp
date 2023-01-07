// 초등 수학
// 이분 매칭

#include <iostream>
#include <string.h>
#include <utility>
#include <vector>
#include <algorithm>

typedef long long ll;

int N;
std::pair<ll, ll> pr[2501];
std::vector<ll> ans;
std::vector<int> line[2501];
bool doneMatch[20000];
int whichMatch[20000];
int whichAns[20000];

bool dfs(int problem){
    for(int i = 0; i < line[problem].size(); i++){
        int answer = line[problem][i];
        if(!doneMatch[answer]){
            doneMatch[answer] = true;
            if(whichMatch[answer] == 0 || dfs(whichMatch[answer])){
                whichMatch[answer] = problem;
                whichAns[problem] = answer;
                return true;
            }
        }
    }
    return false;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 1; i <= N; i++){
        std::cin >> pr[i].first >> pr[i].second;
        ans.push_back(pr[i].first + pr[i].second);
        ans.push_back(pr[i].first - pr[i].second);
        ans.push_back(pr[i].first * pr[i].second);
    }

    // 중복되는 답 지우기
    std::sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());

    // 각 문제 - 답 간 간선 연결
    for(int i = 1; i <= N; i++){
        ll a1 = std::lower_bound(ans.begin(), ans.end(), pr[i].first + pr[i].second) - ans.begin();
        ll a2 = std::lower_bound(ans.begin(), ans.end(), pr[i].first - pr[i].second) - ans.begin();
        ll a3 = std::lower_bound(ans.begin(), ans.end(), pr[i].first * pr[i].second) - ans.begin();
        line[i].push_back(a1);
        line[i].push_back(a2);
        line[i].push_back(a3);
    }

    int matchN = 0;

    for(int i = 1; i <= N; i++){
        memset(doneMatch, false, sizeof(doneMatch));
        if(dfs(i)){
            matchN += 1;
        }
    }

    if(matchN != N){
        std::cout << "impossible\n";
    } else {
        for(int i = 1; i <= N; i++){
            ll answer = ans[whichAns[i]];
            std::cout << pr[i].first << ' ';
            if(pr[i].first + pr[i].second == answer){
                std::cout << '+';
            } else if(pr[i].first - pr[i].second == answer){
                std::cout << '-';

            } else {
                std::cout << '*';

            }
            std::cout << ' ' << pr[i].second << " = " << answer << '\n';
        }
    }

    return 0;
}