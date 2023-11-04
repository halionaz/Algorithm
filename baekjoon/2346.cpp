// 풍선 터뜨리기
// 자료 구조 & 덱

#include <iostream>
#include <deque>

int N, inp;
std::deque<std::pair<int, int> > balloons;

int main()
{

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for (int i = 1; i <= N; i++)
    {
        std::cin >> inp;
        balloons.push_back(std::make_pair(i, inp));
    }

    while (!balloons.empty())
    {
        std::cout << balloons.front().first << ' ';
        int cnt = balloons.front().second;
        balloons.pop_front();
        if (cnt < 0)
        {
            // 음수면
            cnt = -cnt;
            for (int i = 0; i < cnt; i++)
            {
                balloons.push_front(balloons.back());
                balloons.pop_back();
            }
        }
        else
        {
            // 양수면
            cnt = cnt - 1;
            for (int i = 0; i < cnt; i++)
            {
                balloons.push_back(balloons.front());
                balloons.pop_front();
            }
        }
    }

    std::cout << '\n';

    return 0;
}