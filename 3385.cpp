#include <bits/stdc++.h>
#define N   2001
#define M   6001
#define INF 0x3fff3f3f

struct
{
    int start;
    int end;
    int value;
} edge[M];

int num;
int cnt;
int ecnt;
int dis[N];

void add(int start, int end, int value)
{
    int idt = ++ecnt;
    edge[idt].end = end;
    edge[idt].value = value;
    edge[idt].start = start;
}

auto main() -> int
{
    int test;
    std::cin >> test;
    while (test-- != 0)
    {
        int num;
        int cnt;
        ecnt = 0;
        std::cin >> num >> cnt;
        for (int i = 1; i <= cnt; i++)
        {
            int start;
            int end;
            int value;
            std::cin >> start >> end >> value;
            add(start, end, value);
            if (value >= 0)
            {
                std::swap(start, end);
                add(start, end, value);
            }
        }
        for (int i = 1; i <= num; i++)
        {
            dis[i] = INF;
        }
        dis[1] = 0;
        for (int i = 1; i < num; i++)
        {
            for (int j = 1; j <= ecnt; j++)
            {
                if (dis[edge[j].end] > dis[edge[j].start] + edge[j].value &&
                    dis[edge[j].start] != INF)
                {
                    dis[edge[j].end] = dis[edge[j].start] + edge[j].value;
                }
            }
        }
        bool flag = false;
        for (int j = 1; j <= ecnt; j++)
        {
            if (dis[edge[j].end] > dis[edge[j].start] + edge[j].value &&
                dis[edge[j].start] != INF)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            std::cout << "YES";
        } else
        {
            std::cout << "NO";
        }
        std::cout << std::endl;
    }
    return 0;
}
