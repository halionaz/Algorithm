// Dance Dance Revolution
// 다이나믹 프로그래밍
// top-down

// DP이긴 한데 Top-Down 방식 (재귀) 사용
// 발의 위치와 다음 지점을 통한 DP로 기저(마지막)에 도달하면 0을 반환하고
// 점점 쌓아가는 방식으로 풀이

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

int inp;
std::vector<int> arr;
int dp[5][5][100000]; // dp[i][j][k] 발의 위치가 (i,j)이고, 다음에 k를 눌러야 할 때 최소 힘

int move(int from, int to)
{
    if (from == to)
    {
        return 1;
    }
    else if (from == 0)
    {
        return 2;
    }
    else
    {
        return std::abs(from - to) == 2 ? 4 : 3;
    }
}

int solve(int left, int right, int last)
{
    if (last == arr.size())
    {
        return 0;
    }
    int &ret = dp[left][right][last];
    if (ret != 0)
    {
        return ret;
    }
    else
    {
        return ret = std::min(move(left, arr[last]) + solve(arr[last], right, last + 1),
                              move(right, arr[last]) + solve(left, arr[last], last + 1));
    }
}

int main()
{

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while (true)
    {
        std::cin >> inp;
        if (!inp)
        {
            break;
        }
        arr.push_back(inp);
    }

    std::cout << solve(0, 0, 0) << '\n';

    return 0;
}