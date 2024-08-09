#include <bits/stdc++.h>
#define N   100001
#define M   2000001
#define INF 0x3f3f3f3f

struct
{
    int end;
    int value;
    int next;
} edge[M];

int num;
int cnt;
int fre;
int ecnt;
int head[N];
bool vis[N];
int dis[N];
// int pre[N];

void init(int num, int cnt)
{
    for (int i = 0; i < num; i++)
    {
        head[i] = -1;
    }
    for (int i = 0; i < cnt; i++)
    {
        edge[i].next = -1;
    }
}

void add(int start, int end, int value)
{
    int idt = ecnt++;
    edge[idt].end = end;
    edge[idt].next = head[start];
    edge[idt].value = value;
    head[start] = idt;
}

void dij(int start)
{
    std::priority_queue< std::pair< int, int > > pri;
    for (int i = 0; i < num * (fre + 1); i++)
    {
        dis[i] = INF;
    }
    dis[start] = 0;
    pri.emplace(0, start);
    while (!pri.empty())
    {
        int tmp = pri.top().second;
        pri.pop();
        if (vis[tmp])
        {
            continue;
        }
        // std::cout << "<" << tmp << std::endl;
        vis[tmp] = true;
        for (int j = head[tmp]; j != -1; j = edge[j].next)
        {
            int end = edge[j].end;
            if (dis[end] > dis[tmp] + edge[j].value)
            {
                dis[end] = dis[tmp] + edge[j].value;
                // pre[end] = tmp;
                pri.emplace(-dis[end], end);
            }
        }
    }
}

auto main() -> int
{
    int start;
    int end;
    std::cin >> num >> cnt >> fre >> start >> end;
    init(num * (fre + 1), cnt * 2 * (fre + 1));
    for (int i = 0; i < cnt; i++)
    {
        int tstart;
        int tend;
        int value;
        std::cin >> tstart >> tend >> value;
        for (int j = 0; j <= fre; j++)
        {
            add(tstart + j * num, tend + j * num, value);
            add(tend + j * num, tstart + j * num, value);
            if (j != fre)
            {
                add(tstart + j * num, tend + (j + 1) * num, 0);
                add(tend + j * num, tstart + (j + 1) * num, 0);
            }
        }
    }
    int ans = INF;
    dij(start);
    for (int i = 0; i <= fre; i++)
    {
        ans = std::min(dis[end + i * num], ans);
        // std::cout << dis[end + i * num] << " ";
    }
    // for (int i = 0; i < num * (fre + 1); i++)
    // {
    //     std::cout << pre[i] << '-' << dis[i] << " ";
    // }
    std::cout << ans;
    return 0;
}
