#include <bits/stdc++.h>
#include <cstring>
#define N     10001
#define INF   0x7fffffff
#define point std::pair< int, int >
#define edge  std::pair< int, int >

int num, cnt, seg;
std::vector< edge > graph[N];
int min_dis[N];

auto main() -> int
{
    std::cin >> num >> cnt >> seg;
    for (int i = 1; i <= cnt; i++)
    {
        int start;
        int end;
        int value;
        std::cin >> start >> end >> value;
        for (int j = 0; j < seg; j++)
        {
            graph[j * num + start].emplace_back((j + 1) % seg * num + end,
                                                value);
        }
    }
    for (int i = 1; i <= num * seg; i++)
    {
        min_dis[i] = 1e9;
    }
    std::priority_queue< edge, std::vector< edge >, std::greater< edge > > pri;
    min_dis[1] = 0;
    pri.emplace(0, 1);  //{边权，起点}
    while (!pri.empty())
    {
        int tmp = pri.top().first;
        int cur = pri.top().second;
        pri.pop();
        if (tmp <= min_dis[cur])
        {
            for (auto edg : graph[cur])
            {
                int ttmp = min_dis[cur] + 1;
                if (min_dis[cur] < edg.second)
                {
                    ttmp += static_cast< int >(std::ceil(
                                (edg.second - min_dis[cur]) * 1.0 / seg)) *
                            seg;
                }
                if (ttmp < min_dis[edg.first])
                {
                    min_dis[edg.first] = ttmp;
                    pri.emplace(min_dis[edg.first], edg.first);
                }
            }
        }
    }
    if (min_dis[num] == 1e9)
    {
        std::cout << -1;
    } else
    {
        std::cout << min_dis[num];
    }
    return 0;
}
